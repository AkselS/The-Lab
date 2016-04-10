#include "Game.h"


Game::Game()
{
	renderer = 0;
	m_input = NULL;
	tempContext = 0;
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

	m_input = new InputComponent;
	if (!m_input->Initialise(hInstance, hwnd, SCREEN_DEPTH, SCREEN_NEAR))
	{
		return false;
	}
	//m_input->update();
	//input->Initialise();
	

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

	if (m_input)
	{
		delete m_input;
		m_input = 0;
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
	m_input->update();
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
InputComponent* Game::GetInput()
{
	return m_input;
}
LRESULT CALLBACK Game::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	InputComponent* m_input =Game::GetInput();
	if (m_input != NULL && m_input->isKeyDown(DIK_ESCAPE))
	{
		PostQuitMessage(0);
		DestroyWindow(hwnd);
		return 0;
	}
	//switch (umsg)
	//{

	//case WM_KEYDOWN:
	//{
	//	if (wparam == VK_ESCAPE)
	//	{
	//		PostQuitMessage(0);
	//		DestroyWindow(hwnd);
	//	}
	///*	m_input->KeyDown((unsigned int)wparam);
	//	return 0;*/
	//}break;

	//case WM_KEYUP:
	//{
	//	m_input->KeyUp((unsigned int)wparam);
	//	return 0;
	//}

	//default:
	//{
	//	return DefWindowProc(hwnd, umsg, wparam, lparam);
	//}
	//}
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