#pragma once
#ifndef _DX11BASE_H_
#define _DX11BASE_H_

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")

#include <dxgi.h>
#include <d3dcommon.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10math.h>
#include <DxErr.h>

class DX11Base
{
public:
	DX11Base();
	DX11Base(const DX11Base&);
	virtual ~DX11Base();

	bool Initialise(HINSTANCE hInstance, HWND hwnd);
	void Shutdown();

	void BeginScene(float, float, float, float);
	void EndScene();

	virtual bool LoadContent();
	virtual void UnloadContent();

	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetDeviceContext();

	void GetProjectionMatrix(D3DXMATRIX&);
	void GetWorldMatrix(D3DXMATRIX&);
	void GetOrthoMatrix(D3DXMATRIX&);

	void GetVideoCardInfo(char*, int&);

	//virtual void Update(float dt) = 0;
	//virtual void Render() = 0;

	void TurnZBufferOn();
	void TurnZBufferOff();

protected:
	HINSTANCE hInstance_;
	HWND hwnd_;

	bool vsync_enabled, fullscreen;
	int videoCardMemory;
	char videoCardDescription[128];

	D3D_DRIVER_TYPE driverType_;
	D3D_FEATURE_LEVEL featureLevel_;

	ID3D11Device* d3dDevice;
	ID3D11DeviceContext* deviceContext;
	IDXGISwapChain* swapChain;
	ID3D11RenderTargetView* renderTargetView;
	ID3D11Texture2D* depthStencilBuffer;
	ID3D11DepthStencilState* depthStencilState;
	ID3D11DepthStencilView* depthStencilView;
	ID3D11RasterizerState* rasterState;
	D3DXMATRIX projectionMatrix;
	D3DXMATRIX worldMatrix;
	D3DXMATRIX orthoMatrix;

	ID3D11DepthStencilState* depthDisabledStencilState;
};

#endif