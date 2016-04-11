#include "AABBColliderComponent.h"

#pragma region Constructors/Destructors
AABBColliderComponent::AABBColliderComponent()
{
}

AABBColliderComponent::AABBColliderComponent(D3DXVECTOR3 _position, D3DXVECTOR3 _dimensions)
{
	// Defaults
	myLabel = NoLabel;

	// Required Overrides
	dimensions = _dimensions;
	position = _position;

	// Optional Overrides
}
AABBColliderComponent::AABBColliderComponent(D3DXVECTOR3 _position, D3DXVECTOR3 _dimensions, Label _label)
{
	// Defaults

	// Required Overrides
	dimensions = _dimensions;
	position = _position;

	// Optional Overrides
	myLabel = _label;
}
AABBColliderComponent::AABBColliderComponent(D3DXVECTOR3 _position, D3DXVECTOR3 _dimensions, D3DXVECTOR3 _offSet)
{
	// Defaults
	myLabel = NoLabel;

	// Required Overrides
	dimensions = _dimensions;
	position = _position + _offSet;

	// Optional Overrides
}
AABBColliderComponent::AABBColliderComponent(D3DXVECTOR3 _position, D3DXVECTOR3 _dimensions, D3DXVECTOR3 _offSet, Label _label)
{
	// Defaults

	// Required Overrides
	dimensions = _dimensions;
	position = _position + _offSet;

	// Optional Overrides
	myLabel = _label;
}

AABBColliderComponent::~AABBColliderComponent()
{
}

#pragma endregion

#pragma region Get/Set Functions

#pragma region Overrides

D3DXVECTOR3 AABBColliderComponent::getPosition()
{
	return position;
}

void AABBColliderComponent::setPosition(D3DXVECTOR3 _pos)
{
	position = _pos;
}

Label AABBColliderComponent::getLabel()
{
	return myLabel;
}

void AABBColliderComponent::setLabel(Label newLabel)
{
	myLabel = newLabel;
}

#pragma endregion

D3DXVECTOR3 AABBColliderComponent::getAABBMin()
{
	// position is at center of cube so must subtract 1/2 dimension
	return position - (dimensions/2);
}
D3DXVECTOR3 AABBColliderComponent::getAABBMax()
{
	// position is at center of cube so must add 1/2 dimension
	return position + (dimensions/2);
}

#pragma endregion