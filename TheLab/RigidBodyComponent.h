#pragma once

#include <D3DX10math.h>

class RigidBodyComponent
{
public:
	RigidBodyComponent();
	RigidBodyComponent(float _mass);
	~RigidBodyComponent();

	void Update(float dt, bool isColliding);
	D3DXVECTOR3 deltaPosition(float dt);

	void addForce(D3DXVECTOR3 _force);


#pragma region Get/Set Functions

	D3DXVECTOR3 getVelocity();
	void setVelocity(D3DXVECTOR3 _velocity);

	D3DXVECTOR3 getAcceleration();
	void setAcceleration(D3DXVECTOR3 _acceleration);

	D3DXVECTOR3 getForce();
	void setForce(D3DXVECTOR3 _force);

	float getMass();
	void setMass(float _mass);

	bool getUseGravity();
	void setUseGravity(bool _useGravity);

#pragma endregion

protected:
	D3DXVECTOR3 velocity;
	D3DXVECTOR3 acceleration;
	D3DXVECTOR3 force;

	float mass;

	bool useGravity;

	float g = 9.81f;
};

