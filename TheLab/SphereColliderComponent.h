#pragma once

#include <d3dx10math.h>

enum Label
{
	NoLabel,
	Player,
	LevelArchitecture,
	Triggers
};

class SphereColliderComponent
{
public:
	SphereColliderComponent();

	SphereColliderComponent(D3DXVECTOR3 _offSet, float _radius, Label _label);

	SphereColliderComponent(float _radius);

	SphereColliderComponent(float _radius, Label _label);

	~SphereColliderComponent();

	Label myLabel;

	D3DXVECTOR3 offset;
	float radius;
};

