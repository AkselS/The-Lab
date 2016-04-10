#include "RenderingManager.h"

RenderingManager::RenderingManager()
{
	D3D = 0;
	camera = 0;
	mesh1 = 0;
}

RenderingManager::RenderingManager(const RenderingManager&)
{
}

RenderingManager::~RenderingManager()
{
}

bool RenderingManager::Initialise(HINSTANCE hInstance, HWND hwnd)
{
	bool result;

	// Create the Direct3D object.
	D3D = new DX11Base;
	if (!D3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
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
	camera->setPosition(0.0f, 0.0f, -10.0f);

	// Create the model object.
	mesh1 = new StaticMeshComponent;
	if (!mesh1)
	{
		return false;
	}

	result = mesh1->Initialise(D3D->GetDevice(), "cube.txt", L"assets/textures/test.dds");
	if (!result)
	{
		MessageBox(hwnd, "Could not initialize the mesh.", "Error", MB_OK);
		return false;
	}

	return true;
}


void RenderingManager::Shutdown()
{
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
	D3DXMATRIX worldMatrix, viewMatrix, projectionMatrix;
	bool result;

	// Clear the buffers to begin the scene.
	D3D->BeginScene(1.0f, 1.0f, 1.0f, 0.0f);

	// Generate the view matrix based on the camera's position.
	camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	camera->GetViewMatrix(viewMatrix);
	D3D->GetWorldMatrix(worldMatrix);
	D3D->GetProjectionMatrix(projectionMatrix);

	// Rotate the world matrix by the rotation value so that the triangle will spin.
	D3DXMatrixRotationY(&worldMatrix, rotation);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	mesh1->Render(D3D->GetDeviceContext());

	// Present the rendered scene to the screen.
	D3D->EndScene();

	return true;
}