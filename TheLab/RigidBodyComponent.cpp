#include "RigidBodyComponent.h"


RigidBodyComponent::RigidBodyComponent()
{
	mass = 1.0f;
	useGravity = true;
	velocity = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	acceleration = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	force = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

RigidBodyComponent::RigidBodyComponent(float _mass)
{
	mass = _mass;
	useGravity = true;
	velocity = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	acceleration = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	force = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

RigidBodyComponent::~RigidBodyComponent()
{
}

void RigidBodyComponent::Update(float dt, bool isColliding)
{
	if (!isColliding)
	{
		if (useGravity)
		{
			acceleration = D3DXVECTOR3(0.0f, -g, 0.0f);
		}
		D3DXVECTOR3 addedAcceleration = force / mass;

		velocity += (acceleration+addedAcceleration)*dt;
	}
}

void RigidBodyComponent::addForce(D3DXVECTOR3 _force)
{
	force += _force;
}

#pragma region Get/Set Functions

D3DXVECTOR3 RigidBodyComponent::getVelocity()
{
	return velocity;
}
void RigidBodyComponent::setVelocity(D3DXVECTOR3 _velocity)
{
	velocity = _velocity;
}

D3DXVECTOR3 RigidBodyComponent::getAcceleration()
{
	return acceleration;
}
void RigidBodyComponent::setAcceleration(D3DXVECTOR3 _acceleration)
{
	acceleration = _acceleration;
}

D3DXVECTOR3 RigidBodyComponent::getForce()
{
	return force;
}

void RigidBodyComponent::setForce(D3DXVECTOR3 _force)
{
	force = _force;
}

float RigidBodyComponent::getMass()
{
	return mass;
}

void RigidBodyComponent::setMass(float _mass)
{
	mass = _mass;
}

bool RigidBodyComponent::getUseGravity()
{
	return useGravity;
}
void RigidBodyComponent::setUseGravity(bool _useGravity)
{
	useGravity = _useGravity;
}

#pragma endregion