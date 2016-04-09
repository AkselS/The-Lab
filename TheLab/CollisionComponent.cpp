#include "CollisionComponent.h"


CollisionComponent::CollisionComponent()
{
}

CollisionComponent::CollisionComponent(D3DXVECTOR3 _offSet, float _radius, Label _label)
{
	offset = _offSet;
	radius = _radius;
	myLabel = _label;
}

CollisionComponent::CollisionComponent(float _radius)
{
	offset = D3DXVECTOR3(0.0f,0.0f,0.0f);
	radius = _radius;
	myLabel = NoLabel;
}

CollisionComponent::CollisionComponent(float _radius, Label _label)
{
	offset = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	radius = _radius;
	myLabel = _label;
}

CollisionComponent::~CollisionComponent()
{
}
