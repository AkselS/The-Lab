#include "SphereColliderComponent.h"


SphereColliderComponent::SphereColliderComponent()
{
}

SphereColliderComponent::SphereColliderComponent(D3DXVECTOR3 _offSet, float _radius, Label _label)
{
	setOffSet(_offSet);
	radius = _radius;
	setLabel(_label);
}

SphereColliderComponent::SphereColliderComponent(float _radius)
{
	setOffSet(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	radius = _radius;
	setLabel(NoLabel);
}

SphereColliderComponent::SphereColliderComponent(float _radius, Label _label)
{
	setOffSet(D3DXVECTOR3(0.0f, 0.0f, 0.0f));	
	radius = _radius;
	setLabel(_label);
}

SphereColliderComponent::~SphereColliderComponent()
{
}
