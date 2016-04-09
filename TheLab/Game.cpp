#include "Game.h"


Game::Game()
{
	renderer = 0;
	input = 0;
}

Game::Game(const Game& other)
{

}

Game::~Game()
{
}

bool Game::Initialise(HINSTANCE hInstance, HWND hwnd)
{
	int screenWidth, screenHeight;
	bool result;

	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);

	DX11Base::Initialise(hInstance, hwnd);

	renderer = new RenderingComponent;
	if (!renderer)
	{
		return false;
	}

	result = renderer->Initialise(screenWidth, screenHeight, hwnd);
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

	AppHandle = NULL;
	DX11Base::Shutdown();
	return;
}

void Game::Update(float dt)
{
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
	return;

}

void Game::Render()
{
	if (d3dContext_ ==0)
	{
		return;
	}

	//float clearColor[4] = { 0.0f, 0.0f, 0.25f, 1.0f };
	//d3dContext_->ClearRenderTargetView(backBufferTarget_, clearColor);



	//swapChain_->Present(0, 0);
}

bool Game::Frame()
{
	bool result;

	if (input->isKeyDown(VK_ESCAPE))
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