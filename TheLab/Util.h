#pragma once

#include <windows.h>
#include <d3d11.h>
#include <directxmath.h>
#include <iostream>

using namespace DirectX;

inline XMVECTOR MathFV(XMFLOAT3& val)
{
	return XMLoadFloat3(&val);
}

inline XMFLOAT3 MathVF(XMVECTOR& vec)
{
	XMFLOAT3 val;
	XMStoreFloat3(&val, vec);
	return val;
}

inline XMMATRIX MathFM(XMFLOAT4X4& val)
{
	return XMLoadFloat4x4(&val);
}

inline XMFLOAT4X4 MathMF(XMMATRIX& matrix)
{
	XMFLOAT4X4 val;
	XMStoreFloat4x4(&val, matrix);
	return val;
}
