#ifndef _RENDERINGCOMPONENT_H_
#define _RENDERINGCOMPONENT_H_

#pragma once

#include "CameraComponent.h"
#include "StaticMeshComponent.h"
#include "TextureShader.h"
#include "D3DComponent.h"
#include "DX11Base.h"

const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class RenderingComponent
{
public:
	RenderingComponent(DX11Base* DX11);
	RenderingComponent(const RenderingComponent&);
	~RenderingComponent();

	bool Initialise(int, int, HWND);
	void Shutdown();
	bool Frame();

private:
	bool Render(float);

private:
	DX11Base* D3D;
	Camera* camera;
	StaticMeshComponent* mesh1;
};

#endif