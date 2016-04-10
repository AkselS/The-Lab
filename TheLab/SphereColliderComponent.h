#pragma once

#include "CollisionComponent.h"



class SphereColliderComponent :
	CollisionComponent
{
public:
	SphereColliderComponent();

	SphereColliderComponent(GameObject* _parentObject, float _radius);

	SphereColliderComponent(GameObject* _parentObject, float _radius, Label _label, D3DXVECTOR3 _offSet);

	SphereColliderComponent(GameObject* _parentObject, float _radius, Label _label);

	SphereColliderComponent(GameObject* _parentObject, float _radius, D3DXVECTOR3 _offSet);

	~SphereColliderComponent();

	float getRadius();

protected:
	float radius;
};

