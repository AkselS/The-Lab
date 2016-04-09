#include "Game.h"


Game::Game()
{
	renderer = 0;
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
	DX11Base::Shutdown();
}

void Game::Update(float dt)
{

}

void Game::Render()
{
	if (d3dContext_ ==0)
	{
		return;
	}

	float clearColor[4] = { 0.0f, 0.0f, 0.25f, 1.0f };
	d3dContext_->ClearRenderTargetView(backBufferTarget_, clearColor);



	swapChain_->Present(0, 0);
}