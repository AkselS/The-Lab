#ifndef _RENDERINGCOMPONENT_H_
#define _RENDERINGCOMPONENT_H_

#pragma once

#include "CameraComponent.h"
#include "StaticMeshComponent.h"
#include "TextureShader.h"

const bool FULL_SCREEN = true;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class RenderingComponent
{
public:
	RenderingComponent();
	RenderingComponent(const RenderingComponent&);
	~RenderingComponent();

	bool Initialise(int, int, HWND);
	void Shutdown();
	bool Frame();

private:
	bool Render(float);

private:
	Camera* camera;
	StaticMeshComponent* mesh1;
};

#endif