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

	// Check if it is colliding with anything by checking if the Collision list is empty
	if (collisions.size() == 0)
	{
		isColliding = false;
	}
	else
	{
		isColliding = true;
	}
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

std::vector<CollisionComponent*>* CollisionComponent::getCollisions()
{
	return &collisions;
}

bool CollisionComponent::getIsColliding()
{
	return isColliding;
}

#pragma endregion