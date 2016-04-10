#include "SphereColliderComponent.h"


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

	// Optional Overrides

	// Implied
	position = parentObject->getPosition() + offset;
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

	// Implied
	position = parentObject->getPosition() + offset;
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

	// Implied
	position = parentObject->getPosition() + offset;
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

	// Implied
	position = parentObject->getPosition() + offset;
}

SphereColliderComponent::~SphereColliderComponent()
{
}
