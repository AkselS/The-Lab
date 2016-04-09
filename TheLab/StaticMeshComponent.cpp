#include "StaticMeshComponent.h"

StaticMeshComponent::StaticMeshComponent()
{
	vertexBuffer = 0;
	indexBuffer = 0;
	texture = 0;
	mesh = 0;
}

StaticMeshComponent::StaticMeshComponent(const StaticMeshComponent&)
{

}

StaticMeshComponent::~StaticMeshComponent()
{

}

bool StaticMeshComponent::Initialise(ID3D11Device* device, char* modelFilename, WCHAR* textureFilename)
{
	bool result;
	
	result = LoadModel(modelFilename);
	if (!result)
	{
		return false;
	}

	result = InitialiseBuffers(device);
	if (!result)
	{
		return false;
	}

	result = LoadTexture(device, textureFilename);
	if (!result)
	{
		return false;
	}

	return true;
}


void StaticMeshComponent::Shutdown()
{
	ReleaseTexture();
	ShutdownBuffers();
	ReleaseModel();
	return;
}


void StaticMeshComponent::Render(ID3D11DeviceContext* deviceContext)
{
	RenderBuffers(deviceContext);
	return;
}


int StaticMeshComponent::GetIndexCount()
{
	return indexCount;
}


ID3D11ShaderResourceView* StaticMeshComponent::GetTexture()
{
	return texture->GetTexture();
}


bool StaticMeshComponent::InitialiseBuffers(ID3D11Device* device)
{
	VertexType* vertices;
	unsigned long* indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT result;
	int i;

	vertices = new VertexType[vertexCount];
	if (!vertices)
	{
		return false;
	}

	indices = new unsigned long[indexCount];
	if (!indices)
	{
		return false;
	}

	for (i = 0; i<vertexCount; i++)
	{
		vertices[i].position = D3DXVECTOR3(mesh[i].x, mesh[i].y, mesh[i].z);
		vertices[i].texture = D3DXVECTOR2(mesh[i].tu, mesh[i].tv);
		vertices[i].normal = D3DXVECTOR3(mesh[i].nx, mesh[i].ny, mesh[i].nz);

		indices[i] = i;
	}

	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(VertexType)* vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &vertexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long)* indexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	result = device->CreateBuffer(&indexBufferDesc, &indexData, &indexBuffer);
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


void StaticMeshComponent::ShutdownBuffers()
{
	if (indexBuffer)
	{
		indexBuffer->Release();
		indexBuffer = 0;
	}

	if (vertexBuffer)
	{
		vertexBuffer->Release();
		vertexBuffer = 0;
	}

	return;
}


void StaticMeshComponent::RenderBuffers(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride;
	unsigned int offset;

	stride = sizeof(VertexType);
	offset = 0;

	deviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	deviceContext->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	return;
}


bool StaticMeshComponent::LoadTexture(ID3D11Device* device, WCHAR* filename)
{
	bool result;

	texture = new TextureComponent;
	if (!texture)
	{
		return false;
	}

	// Initialize the texture object.
	result = texture->Initialise(device, filename);
	if (!result)
	{
		return false;
	}

	return true;
}


void StaticMeshComponent::ReleaseTexture()
{
	// Release the texture object.
	if (texture)
	{
		texture->Shutdown();
		delete texture;
		texture = 0;
	}

	return;
}

bool StaticMeshComponent::LoadModel(char* filename)
{
	ifstream fin;
	char input;
	int i;

	fin.open(filename);

	if (fin.fail())
	{
		return false;
	}

	fin.get(input);
	while (input != ':')
	{
		fin.get(input);
	}

	fin >> vertexCount;
	indexCount = vertexCount;
	mesh = new Model[vertexCount];
	if (!mesh)
	{
		return false;
	}

	fin.get(input);
	while (input != ':')
	{
		fin.get(input);
	}
	fin.get(input);
	fin.get(input);

	for (i = 0; i<vertexCount; i++)
	{
		fin >> mesh[i].x >> mesh[i].y >> mesh[i].z;
		fin >> mesh[i].tu >> mesh[i].tv;
		fin >> mesh[i].nx >> mesh[i].ny >> mesh[i].nz;
	}

	fin.close();

	return true;
}

void StaticMeshComponent::ReleaseModel()
{
	if (mesh)
	{
		delete[] mesh;
		mesh = 0;
	}

	return;
}
