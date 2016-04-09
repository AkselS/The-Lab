#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#include "DX11Base.h"
#include "RenderingComponent.h"

class Game :
	public DX11Base
{
public:
	Game();
	Game(const Game&);
	virtual ~Game();

	bool Initialise(HINSTANCE hInstance, HWND hwnd);
	void Shutdown();

	void Update(float dt);
	void Render();

private:
	bool Frame();
	RenderingComponent* renderer;
};

