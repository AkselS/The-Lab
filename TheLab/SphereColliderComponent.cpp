#include "SphereColliderComponent.h"

#pragma region Constructors and Destructors
SphereColliderComponent::SphereColliderComponent()
{
}

SphereColliderComponent::SphereColliderComponent(D3DXVECTOR3 parentPosition, float _radius)
{
	// Defaults
	myLabel = NoLabel;
	
	// Required Overrides
	radius = _radius;

	// Optional Overrides(null)

	this->Initialise(parentPosition);
}

SphereColliderComponent::SphereColliderComponent(D3DXVECTOR3 parentPosition, float _radius, Label _label, D3DXVECTOR3 _offSet)
{
	// Defaults (Null)
	
	// Required Overrides
	radius = _radius;

	// Optional Overrides
	myLabel = _label;

	this->Initialise(parentPosition + _offSet);

}

SphereColliderComponent::SphereColliderComponent(D3DXVECTOR3 parentPosition, float _radius, Label _label)
{
	// Defaults
	
	// Required Overrides
	radius = _radius;

	// Optional Overrides
	myLabel = _label;

	this->Initialise(parentPosition);

}

SphereColliderComponent::SphereColliderComponent(D3DXVECTOR3 parentPosition, float _radius, D3DXVECTOR3 _offSet)
{
	// Defaults
	myLabel = NoLabel;

	// Required Overrides
	radius = _radius;

	// Optional Overrides

	this->Initialise(parentPosition + _offSet);

}

SphereColliderComponent::~SphereColliderComponent()
{
}

#pragma endregion

void SphereColliderComponent::Initialise(D3DXVECTOR3 thisPosition)
{
	CollisionComponent::Initialise(thisPosition);
}

void SphereColliderComponent::Update(D3DXVECTOR3 thisPosition, float dt)
{
	CollisionComponent::Update(thisPosition, dt);
}

#pragma region Get/Set functions

#pragma region Overrides

D3DXVECTOR3 SphereColliderComponent::getPosition()
{
	return position;
}

void SphereColliderComponent::setPosition(D3DXVECTOR3 _pos)
{
	position = _pos;
}

Label SphereColliderComponent::getLabel()
{
	return myLabel;
}

void SphereColliderComponent::setLabel(Label newLabel)
{
	myLabel = newLabel;
}

#pragma endregion

float SphereColliderComponent::getRadius()
{
	return radius;
}

void SphereColliderComponent::setRadius(float _radius)
{
	radius = _radius;
}

#pragma endregion