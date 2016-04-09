#pragma once

#include <d3dx10math.h>

enum Label
{
	NoLabel,
	Player,
	LevelArchitecture,
	Triggers
};

class CollisionComponent
{
public:
	CollisionComponent();

	CollisionComponent(D3DXVECTOR3 _offSet, float _radius, Label _label);

	CollisionComponent(float _radius);

	CollisionComponent(float _radius, Label _label);

	~CollisionComponent();

	Label myLabel;

	D3DXVECTOR3 offset;
	float radius;
};

