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
	~CollisionComponent();

	void setLabel(Label _label);
	Label getLabel();

	void setOffSet(D3DXVECTOR3 _offset);
	D3DXVECTOR3 getOffset();

private:
	Label myLabel;
	D3DXVECTOR3 offset;
};

