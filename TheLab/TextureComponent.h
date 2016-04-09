#ifndef _TEXTURECOMPONENT_H_
#define _TEXTURECOMPONENT_H_

#pragma once

#include <d3d11.h>
#include <D3DX11tex.h>

class TextureComponent
{
public:
	TextureComponent();
	TextureComponent(const TextureComponent&);
	~TextureComponent();

	bool Initialise(ID3D11Device*, WCHAR*);
	void Shutdown();
	ID3D11ShaderResourceView* GetTexture();

private:
	ID3D11ShaderResourceView* texture;
};

#endif
