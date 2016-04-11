#include "RenderingManager.h"

RenderingManager::RenderingManager()
{
	D3D = 0;
	camera = 0;
	mesh1 = 0;

	m_Menu = 0;
}

RenderingManager::RenderingManager(const RenderingManager&)
{
}

RenderingManager::~RenderingManager()
{
}

bool RenderingManager::Initialise(int screenWidth, int screenHeight, HINSTANCE hInstance, HWND hwnd)
{
	bool result;

	// Create the Direct3D object.
	D3D = new DX11Base;
	if (!D3D)
	{
		return false;
	}

	// Initialize the Direct3D object
	result = D3D->Initialise(hInstance, hwnd);
	if (!result)
	{
		MessageBox(hwnd, "Could not initialize Direct3D.", "Error", MB_OK);
		return false;
	}

	// Create the camera object.
	camera = new Camera;
	if (!camera)
	{
		return false;
	}

	// Set the initial position of the camera.
	camera->Position(XMFLOAT3(0.0f, 0.0f, -10.0f));

	//// Create the model object.
	//mesh1 = new StaticMeshComponent;
	//if (!mesh1)
	//{
	//	return false;
	//}

	//result = mesh1->Initialise(D3D->GetDevice(), "cube.txt", L"assets/textures/test.dds");
	//if (!result)
	//{
	//	MessageBox(hwnd, "Could not initialize the mesh.", "Error", MB_OK);
	//	return false;
	//}

	//Create Menu
	m_Menu = new MenuMain;
	if (!m_Menu)
	{
		return false;
	}

	//Initialise Menu
	result = m_Menu->Initialise(D3D->GetDevice(), screenWidth, screenHeight, L"../assets/textures/MainMenu.dds", 256, 256);
	if (!result)
	{
		MessageBox(hwnd, "Could not initialize the bitmap object.", "Error", MB_OK);
		return false;
	}

	return true;
}


void RenderingManager::Shutdown()
{

	//Release Menu
	if (m_Menu)
	{
		m_Menu->Shutdown();
		delete m_Menu;
		m_Menu = 0;
	}

	if (mesh1)
	{
		mesh1->Shutdown();
		delete mesh1;
		mesh1 = 0;
	}

	// Release the camera object.
	if (camera)
	{
		delete camera;
		camera = 0;
	}

	// Release the D3D object.
	if (D3D)
	{
		D3D->Shutdown();
		delete D3D;
		D3D = 0;
	}

	return;
}


bool RenderingManager::Frame()
{
	bool result;
	static float rotation = 0.0f;


	// Update the rotation variable each frame.
	rotation += (float)D3DX_PI * 0.01f;
	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	// Render the graphics scene.
	result = Render(rotation);
	if (!result)
	{
		return false;
	}

	return true;
}


bool RenderingManager::Render(float rotation)
{
	D3DXMATRIX worldMatrix, viewMatrix, projectionMatrix, orthoMatrix;
	bool result;

	// Clear the buffers to begin the scene.
	D3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	camera->GetViewMatrix(&viewMatrix);
	D3D->GetWorldMatrix(worldMatrix);
	D3D->GetProjectionMatrix(projectionMatrix);

	D3D->GetProjectionMatrix(orthoMatrix);

	//Turn ZBuffer off before 2D rendering
	D3D->TurnZBufferOff();

	//Put the bitmap vertex and index buffers on graphics pipeline for drawing
	result = m_Menu->Render(D3D->GetDeviceContext(), 100, 100);
	if (!result)
	{
		return false;
	}

	//Render menu with texture shader
	result = mesh1->Render (D3D->GetDeviceContext(), m_Menu->GetIndexCount(), worldMatrix, viewMatrix, orthoMatrix, m_Menu->GetTexture());
	if (!result)
	{
		return false;
	}

	//Turn ZBuffer on
	D3D->TurnZBufferOn();

	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationY(&worldMatrix, rotation);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	mesh1->Render(D3D->GetDeviceContext());

	// Present the rendered scene to the screen.
	D3D->EndScene();

	return true;
}