#ifndef _BITMAPCLASS_H_
#define _BITMAPCLASS_H_

#pragma once

#include <d3d11.h>
#include <D3DX10math.h>
#include <TextureComponent.h>

class MenuMain
{
private:

	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR2 texture;
	};

public:
	MenuMain();
	MenuMain(const MenuMain&);
	~MenuMain();

	bool Initialise(ID3D11Device*, int , int, WCHAR*, int, int);

	void Shutdown();
	bool Render(ID3D11DeviceContext*, int, int);

	int GetIndexCount();
	ID3D11ShaderResourceView* GetTexture();

private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	bool UpdateBuffers(ID3D11DeviceContext*, int, int);
	void RenderBuffers(ID3D11DeviceContext*);

	bool LoadTexture(ID3D11Device*, WCHAR*);
	void ReleaseTexture();

private:
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
	TextureComponent* m_Texture;

	int m_screenWidth, m_screenHeight;
	int m_menuWidth, m_menuHeight;
	int m_previousPosX, m_previousPosY;

};

#endif

