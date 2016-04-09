#include "TextureComponent.h"

TextureComponent::TextureComponent()
{
	texture = 0;
}

TextureComponent::TextureComponent(const TextureComponent&)
{

}

TextureComponent::~TextureComponent()
{

}

bool TextureComponent::Initialise(ID3D11Device* device, WCHAR* filename)
{
	HRESULT result;

	result = D3DX11CreateShaderResourceViewFromFile(device, "assets/textures/test.dds", NULL, NULL, &texture, NULL);
	if (FAILED(result))
	{
		return false;
	}

	return true;
}

void TextureComponent::Shutdown()
{
	if (texture)
	{
		texture->Release();
		texture = 0;
	}

	return;
}

ID3D11ShaderResourceView* TextureComponent::GetTexture()
{
	return texture;
}

