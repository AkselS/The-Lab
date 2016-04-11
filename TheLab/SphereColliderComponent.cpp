#include "SphereColliderComponent.h"

#pragma region Constructors and Destructors
SphereColliderComponent::SphereColliderComponent()
{
}

SphereColliderComponent::SphereColliderComponent(D3DXVECTOR3 _parentPosition, float _radius)
{
	// Defaults
	myLabel = NoLabel;
	
	// Required Overrides
	position + _parentPosition;
	radius = _radius;

	// Optional Overrides(null)

}

SphereColliderComponent::SphereColliderComponent(D3DXVECTOR3 _parentPosition, float _radius, Label _label, D3DXVECTOR3 _offSet)
{
	// Defaults (Null)
	
	// Required Overrides
	position = _parentPosition + _offSet;
	radius = _radius;

	// Optional Overrides
	myLabel = _label;


}

SphereColliderComponent::SphereColliderComponent(D3DXVECTOR3 _parentPosition, float _radius, Label _label)
{
	// Defaults
	
	// Required Overrides
	position = _parentPosition;
	radius = _radius;

	// Optional Overrides
	myLabel = _label;


}

SphereColliderComponent::SphereColliderComponent(D3DXVECTOR3 _parentPosition, float _radius, D3DXVECTOR3 _offSet)
{
	// Defaults
	myLabel = NoLabel;

	// Required Overrides
	position = _parentPosition + _offSet;
	radius = _radius;

	// Optional Overrides

	

}

SphereColliderComponent::~SphereColliderComponent()
{
}

#pragma endregion

void SphereColliderComponent::Update(D3DXVECTOR3 thisPosition, float dt)
{
	// Calls base function for shared update logic
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