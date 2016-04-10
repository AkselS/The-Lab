#include "CollisionComponent.h"


CollisionComponent::CollisionComponent()
{
}


CollisionComponent::~CollisionComponent()
{
}

void CollisionComponent::Initialise(D3DXVECTOR3 thisPosition)
{
	// Set the position
	position = thisPosition;

	// Register with Collision Manager
	//CollisionManager::instance().addCollider(this);
}

void CollisionComponent::Update(D3DXVECTOR3 thisPosition, float dt)
{
	// Continually set the position
	position = thisPosition;
}

#pragma region Get/Set Functions

D3DXVECTOR3 CollisionComponent::getPosition()
{
	return position;
}

void CollisionComponent::setPosition(D3DXVECTOR3 _pos)
{
	position = _pos;
}

Label CollisionComponent::getLabel()
{
	return myLabel; 
}

void CollisionComponent::setLabel(Label newLabel)
{
	myLabel = newLabel;
}

#pragma endregion