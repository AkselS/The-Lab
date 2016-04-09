#ifndef _STATICMESHCOMPONENT_H_
#define _STATICMESHCOMPONENT_H_
#pragma once

#include <list>
#include <fstream>
#include <istream>
#include <vector>
#include <d3d11.h>
#include <d3dx11.h>
#include <D3DX10math.h>
#include <string>
#include <dinput.h>
#include <Windows.h>
#include "TextureComponent.h"
using namespace std;

class StaticMeshComponent
{
public:
	StaticMeshComponent();
	StaticMeshComponent(const StaticMeshComponent&);
	~StaticMeshComponent();

	bool Initialise(ID3D11Device*, char*, WCHAR*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();
	ID3D11ShaderResourceView* GetTexture();

private:
	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR2 texture;
		D3DXVECTOR3 normal;
	};

	struct Model
	{
		float x, y, z;
		float tu, tv;
		float nx, ny, nz;
	};

	bool InitialiseBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

	bool LoadTexture(ID3D11Device*, WCHAR*);
	void ReleaseTexture();

	bool LoadModel(char*);
	void ReleaseModel();

	ID3D11Buffer *vertexBuffer, *indexBuffer;
	int vertexCount, indexCount;
	TextureComponent* texture;
	Model* mesh;
};

#endif

