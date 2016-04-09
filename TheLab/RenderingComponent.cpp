#include "RenderingComponent.h"

RenderingComponent::RenderingComponent()
{
	D3D = 0;
	camera = 0;
	mesh1 = 0;
}

RenderingComponent::RenderingComponent(const RenderingComponent&)
{
}

RenderingComponent::~RenderingComponent()
{
}

bool RenderingComponent::Initialise(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;


	// Create the Direct3D object.
	D3D = new D3DComponent;
	if (!D3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = D3D->Initialise(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
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

	XMFLOAT3 newPos;
	newPos.x = 0.0f;
	newPos.y = 0.0f;
	newPos.z = -10.0f;
	// Set the initial position of the camera.
	camera->Position(newPos);

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


void RenderingComponent::Shutdown()
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


bool RenderingComponent::Frame()
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


bool RenderingComponent::Render(float rotation)
{
	D3DXMATRIX worldMatrix, viewMatrix, projectionMatrix;
	bool result;

	// Clear the buffers to begin the scene.
	D3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	camera->GetViewMatrix(&viewMatrix);
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