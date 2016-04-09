#include "SphereColliderComponent.h"


SphereColliderComponent::SphereColliderComponent()
{
}

SphereColliderComponent::SphereColliderComponent(D3DXVECTOR3 _offSet, float _radius, Label _label)
{
	offset = _offSet;
	radius = _radius;
	myLabel = _label;
}

SphereColliderComponent::SphereColliderComponent(float _radius)
{
	offset = D3DXVECTOR3(0.0f,0.0f,0.0f);
	radius = _radius;
	myLabel = NoLabel;
}

SphereColliderComponent::SphereColliderComponent(float _radius, Label _label)
{
	offset = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	radius = _radius;
	myLabel = _label;
}

SphereColliderComponent::~SphereColliderComponent()
{
}
