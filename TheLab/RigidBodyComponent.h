#pragma once

#include <D3DX10math.h>

class RigidBodyComponent
{
public:
	RigidBodyComponent();
	~RigidBodyComponent();

	void Update(float dt);

protected:
	D3DXVECTOR3 Velocity;
	D3DXVECTOR3 Acceleration;

};

