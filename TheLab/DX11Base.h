#pragma once
#ifndef _DX11BASE_H_
#define _DX11BASE_H_

#include <d3d11.h>
#include <d3dx11.h>
#include <DxErr.h>

using namespace std;

class DX11Base
{
public:
	DX11Base();
	DX11Base(const DX11Base& other);
	virtual ~DX11Base();

	
	bool Initialise(HINSTANCE hInstance, HWND hwnd);
	void Shutdown();

	virtual bool LoadContent();
	virtual void UnloadContent();

	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
protected:
	HINSTANCE hInstance_;
	HWND hwnd_;

	D3D_DRIVER_TYPE driverType_;
	D3D_FEATURE_LEVEL featureLevel_;

	ID3D11Device* d3dDevice_;
	ID3D11DeviceContext* d3dContext_;
	IDXGISwapChain* swapChain_;
	ID3D11RenderTargetView* backBufferTarget_;

	
};

DX11Base* D3D;

#endif