#pragma once

#include "CollisionComponent.h"



class SphereColliderComponent :
	CollisionComponent
{
public:
	SphereColliderComponent();

	SphereColliderComponent(D3DXVECTOR3 _offSet, float _radius, Label _label);

	SphereColliderComponent(float _radius);

	SphereColliderComponent(float _radius, Label _label);

	~SphereColliderComponent();

	float getRadius();

private:
	float radius;
};

