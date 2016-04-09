#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#include "DX11Base.h"
#include "RenderingComponent.h"
#include "InputComponent.h"

class Game :
	public DX11Base
{
public:
	Game();
	Game(const Game&);
	virtual ~Game();

	bool Initialise(HINSTANCE hInstance, HWND hwnd);
	void Shutdown();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

	void Update(float dt);
	void Render();

private:
	bool Frame();
	RenderingComponent* renderer;
	InputComponent* input;
};

static LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

static Game* AppHandle = 0;