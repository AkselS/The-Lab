#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#include "RenderingManager.h"
#include "InputComponent.h"

class Game
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
	ID3D11DeviceContext* tempContext;
	RenderingManager* renderer;
	InputComponent* input;
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

static Game* AppHandle = 0;