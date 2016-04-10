#include "SphereColliderComponent.h"

#pragma region Constructors and Destructors
SphereColliderComponent::SphereColliderComponent()
{
}

SphereColliderComponent::SphereColliderComponent(GameObject* _parentObject, float _radius)
{
	// Defaults
	offset = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	myLabel = NoLabel;
	
	// Required Overrides
	parentObject = _parentObject;
	radius = radius;

	// Optional Overrides(null)

	this->Initialise();
}

SphereColliderComponent::SphereColliderComponent(GameObject* _parentObject, float _radius, Label _label, D3DXVECTOR3 _offSet)
{
	// Defaults (Null)
	
	// Required Overrides
	parentObject = _parentObject;
	radius = radius;

	// Optional Overrides
	offset = _offSet;
	myLabel = _label;

	this->Initialise();

}

SphereColliderComponent::SphereColliderComponent(GameObject* _parentObject, float _radius, Label _label)
{
	// Defaults
	offset = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// Required Overrides
	parentObject = _parentObject;
	radius = radius;

	// Optional Overrides
	myLabel = _label;

	this->Initialise();

}

SphereColliderComponent::SphereColliderComponent(GameObject* _parentObject, float _radius, D3DXVECTOR3 _offSet)
{
	// Defaults
	myLabel = NoLabel;

	// Required Overrides
	parentObject = _parentObject;
	radius = radius;

	// Optional Overrides
	offset = _offSet;

	this->Initialise();

}

SphereColliderComponent::~SphereColliderComponent()
{
}

#pragma endregion

void SphereColliderComponent::Initialise()
{
	CollisionComponent::Initialise();
}

void SphereColliderComponent::Update(float dt)
{
	CollisionComponent::Update(dt);
}

#pragma region Get/Set functions

float SphereColliderComponent::getRadius()
{
	return radius;
}

void SphereColliderComponent::setRadius(float _radius)
{
	radius = _radius;
}

#pragma endregion