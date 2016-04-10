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

	void Initialise() override;

	void Update(float dt) override;


#pragma region Get/Set function
	
	float getRadius();
	void setRadius(float _radius);

#pragma endregion

protected:
	float radius;
};

