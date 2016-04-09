#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

bool Game::LoadContent()
{
	return true;
}

void Game::UnloadContent()
{
	
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