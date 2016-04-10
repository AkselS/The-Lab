#include "CollisionComponent.h"


CollisionComponent::CollisionComponent()
{
}


CollisionComponent::~CollisionComponent()
{
}

void CollisionComponent::Initialise()
{
	// Set the position
	position = parentObject->getPosition() + offset;

	// Register with Collision Manager
	//CollisionManager::instance().addCollider(this);
}

void CollisionComponent::Update(float dt)
{
	// Continually set the position
	position = parentObject->getPosition() + offset;
}

#pragma region Get/Set Functions

GameObject* CollisionComponent::getParentObject()
{
	return parentObject;
}

void CollisionComponent::setParentObject(GameObject* _parentObject)
{
	parentObject = _parentObject;
}

Label CollisionComponent::getLabel()
{
	return myLabel; 
}

void CollisionComponent::setLabel(Label newLabel)
{
	myLabel = newLabel;
}

D3DXVECTOR3 CollisionComponent::getOffset()
{
	return offset;
}

void CollisionComponent::setOffSet(D3DXVECTOR3 _offset)
{
	offset = _offset;
}
#pragma endregion