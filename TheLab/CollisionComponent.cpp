#include "CollisionComponent.h"


CollisionComponent::CollisionComponent()
{
}


CollisionComponent::~CollisionComponent()
{
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