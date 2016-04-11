#pragma once

#include "MenuMain.h"

MenuMain::MenuMain()
{
	m_vertexBuffer = 0;
	m_indexBuffer = 0;
	m_Texture = 0;
}

MenuMain::MenuMain(const MenuMain& other)
{
}


MenuMain::~MenuMain()
{
}

bool MenuMain::Initialise(ID3D11Device* device, int screenWidth, int screenHeight, WCHAR* textureFilename, int menuWidth, int menuHeight)
{
	bool result;

	//Screen size
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;

	//Store pixel size to render
	m_menuWidth = menuWidth;
	m_menuHeight = menuHeight;

	//Initialize previous rendering pos
	m_previousPosX = -1;
	m_previousPosY = -1;

	//Initialize vertex and index buffers
	result = InitializeBuffers(device);
	if (!result)
	{
		return false;
	}

	// Load the texture for model
	result = LoadTexture(device, textureFilename);
	if (!result)
	{
		return false;
	}

	return true;
}

void MenuMain::Shutdown()
{
	//Release the model texture
	ReleaseTexture();

	//Shutdown the vertex and index buffers
	ShutdownBuffers();

	return;
}

bool MenuMain::Render(ID3D11DeviceContext* deviceContext, int positionX, int positionY)
{
	bool result;


	//Re-build dynamic vertex buffer for rendering to different location on screen
	result = UpdateBuffers(deviceContext, positionX, positionY);
	if (!result)
	{
		return false;
	}

	//Put the vertex and index buffers on the graphics pipeline
	RenderBuffers(deviceContext);

	return true;
}

int MenuMain::GetIndexCount()
{
	return m_indexCount;
}

ID3D11ShaderResourceView* MenuMain::GetTexture()
{
	return m_Texture->GetTexture();
}

bool MenuMain::InitializeBuffers(ID3D11Device* device)
{
	VertexType* vertices;
	unsigned long* indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT result;
	int i;

	//Set nr of vertices in vertex array
	m_vertexCount = 6;
	
	//Set nr of indices
	m_indexCount = m_vertexCount;

	//Create new array vertex
	vertices = new VertexType[m_vertexCount];
	if (!vertices)
	{
		return false;
	}

	//Create index array
	indices = new unsigned long[m_indexCount];
	if (!indices)
	{
		return false;
	}

	//Initialize vertex array to zero
	memset(vertices, 0, (sizeof(VertexType)* m_vertexCount));

	//Load index array with data
	for (i = 0; i < m_indexCount; i++)
	{
		indices[i] = i;
	}

	vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * m_vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	//Create vertex buffer
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * m_indexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	//Create index buffer
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	delete[] vertices;
	vertices = 0;

	delete[] indices;
	indices = 0;

	return true;

}

void MenuMain::ShutdownBuffers()
{
	//Release index buffer
	if (m_indexBuffer)
	{
		m_indexBuffer->Release();
		m_indexBuffer = 0;
	}

	//Release vertex buffer
	if (m_vertexBuffer)
	{
		m_vertexBuffer->Release();
		m_vertexBuffer = 0;
	}

	return;

}

bool MenuMain::UpdateBuffers(ID3D11DeviceContext* deviceContext, int positionX, int positionY)
{
	float left, right, top, bottom;
	VertexType* vertices;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	VertexType* verticesPtr;
	HRESULT result;

	if ((positionX == m_previousPosX) && (positionY == m_previousPosY))
	{
		return true;
	}

	m_previousPosX = positionX;
	m_previousPosY = positionY;

	left = (float)((m_screenWidth / 2) * -1) + (float)positionX;

	right = left + (float)m_menuWidth;

	top = (float)(m_screenHeight / 2) - (float)positionY;

	bottom = top - (float)m_menuHeight;

	//Create new vertex array
	vertices = new VertexType[m_vertexCount];
	if (!vertices)
	{
		return false;
	}

	//Load vertex array with data. First triangle
	vertices[0].position = D3DXVECTOR3(left, top, 0.0f);  // Top left.
	vertices[0].texture = D3DXVECTOR2(0.0f, 0.0f);

	vertices[1].position = D3DXVECTOR3(right, bottom, 0.0f);  // Bottom right.
	vertices[1].texture = D3DXVECTOR2(1.0f, 1.0f);

	vertices[2].position = D3DXVECTOR3(left, bottom, 0.0f);  // Bottom left.
	vertices[2].texture = D3DXVECTOR2(0.0f, 1.0f);

	//Second triangle
	vertices[3].position = D3DXVECTOR3(left, top, 0.0f);  // Top left.
	vertices[3].texture = D3DXVECTOR2(0.0f, 0.0f);

	vertices[4].position = D3DXVECTOR3(right, top, 0.0f);  // Top right.
	vertices[4].texture = D3DXVECTOR2(1.0f, 0.0f);

	vertices[5].position = D3DXVECTOR3(right, bottom, 0.0f);  // Bottom right.
	vertices[5].texture = D3DXVECTOR2(1.0f, 1.0f);

	//Lock vertex buffer to write to
	result = deviceContext->Map(m_vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(result))
	{
		return false;
	}

	//Get pointer to data in vertex buffer
	verticesPtr = (VertexType*)mappedResource.pData;

	//Copy data into vertex buffer
	memcpy(verticesPtr, (void*)vertices, (sizeof(VertexType) * m_vertexCount));

	//Unlock vertex buffer
	deviceContext->Unmap(m_vertexBuffer, 0);

	//Release vertex array
	delete[] vertices;
	vertices = 0;

	return true;

}

void MenuMain::RenderBuffers(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride;
	unsigned int offset;


	//Set vertex buffer stride and offset
	stride = sizeof(VertexType);
	offset = 0;

	//Set the vertex buffer active in input assembler to be rendered
	deviceContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);

	//Set the index buffer active in input assembler to be rendered
	deviceContext->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	//Set the type of primitive
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	return;

}

bool MenuMain::LoadTexture(ID3D11Device* device, WCHAR* filename)
{
	bool result;


	// Create the texture object.
	m_Texture = new TextureComponent;
	if (!m_Texture)
	{
		return false;
	}

	// Initialize the texture object.
	result = m_Texture->Initialise(device, filename);
	if (!result)
	{
		return false;
	}

	return true;

}

void MenuMain::ReleaseTexture()
{
	// Release the texture object.
	if (m_Texture)
	{
		m_Texture->Shutdown();
		delete m_Texture;
		m_Texture = 0;
	}

	return;

}

