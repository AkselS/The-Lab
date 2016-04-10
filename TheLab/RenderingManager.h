#ifndef _RENDERINGMANAGER_H_
#define _RENDERINGMANAGER_H_

#pragma once

#include <d3d10_1.h>
#include "CameraComponent.h"
#include "StaticMeshComponent.h"
#include "LightShader.h"
#include "Light.h"
#include "TextureShader.h"
#include "DX11Base.h"

const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class RenderingManager : public DX11Base
{
public:
	RenderingManager();
	RenderingManager(const RenderingManager&);
	~RenderingManager();

	bool Initialise(HINSTANCE, HWND);
	void Shutdown();
	bool Frame();

private:
	bool Render(float);

private:
	Camera* camera;
	StaticMeshComponent* mesh1;
	DX11Base* D3D;
	LightShader* lightShader;
	Light* light;
};

#endif