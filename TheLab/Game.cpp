#include "Game.h"


Game::Game()
{
	renderer = 0;
	input = 0;
	tempContext = 0;
	collisionManager = 0;
}

Game::Game(const Game& other)
{

}

Game::~Game()
{
}

bool Game::Initialise(HINSTANCE hInstance, HWND hwnd)
{
	bool result;

	renderer = new RenderingManager();
	if (!renderer)
	{
		return false;
	}

	result = renderer->Initialise(hInstance, hwnd);
	if (!result)
	{
		return false;
	}

	input = new InputComponent;
	if (!input)
	{
		return false;
	}

	input->Initialise();

	collisionManager->instance();

	return true;
}

void Game::Shutdown()
{
	if (renderer)
	{
		renderer->Shutdown();
		delete renderer;
		renderer = 0;
	}

	if (input)
	{
		delete input;
		input = 0;
	}

	if (tempContext)
	{
		tempContext->Release();
		tempContext = 0;
	}

	AppHandle = NULL;
	return;
}

void Game::Update(float dt)
{

	return;

}

void Game::Render()
{
	/*tempContext = renderer->GetDeviceContext();
	if (tempContext == 0)
	{
		return;
	}*/

	MSG msg;
	bool done, result;

	ZeroMemory(&msg, sizeof(MSG));

	done = false;
	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (msg.message == WM_QUIT)
		{
			done = true;
		}
		else
		{
			result = Frame();
			if (!result)
			{
				done = true;
			}
		}
	}
}

bool Game::Frame()
{
	bool result;

	if (GetAsyncKeyState(VK_ESCAPE))
	{
		return false;
	}

	result = renderer->Frame();
	if (!result)
	{
		return false;
	}

	return true;
}

LRESULT CALLBACK Game::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	switch (umsg)
	{

	case WM_KEYDOWN:
	{
		input->KeyDown((unsigned int)wparam);
		return 0;
	}

	case WM_KEYUP:
	{
		input->KeyUp((unsigned int)wparam);
		return 0;
	}

	default:
	{
		return DefWindowProc(hwnd, umsg, wparam, lparam);
	}
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch (umessage)
	{

	case WM_QUIT:
	{
		PostQuitMessage(0);
		return 0;
	}

	case WM_CLOSE:
	{
		PostQuitMessage(0);
		return 0;
	}

	default:
	{
		return DefWindowProc(hwnd, umessage, wparam, lparam); //AppHandle->MessageHandler(hwnd, umessage, wparam, lparam);
	}
	}
}