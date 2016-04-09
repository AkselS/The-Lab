#pragma once
<<<<<<< HEAD
=======

#include <d3dx10math.h>

enum Label
{
	NoLabel,
	Player,
	LevelArchitecture,
	Triggers
};

>>>>>>> Andrew
class CollisionComponent
{
public:
	CollisionComponent();
	~CollisionComponent();
<<<<<<< HEAD
=======

	void setLabel(Label _label);
	Label getLabel();

	void setOffSet(D3DXVECTOR3 _offset);
	D3DXVECTOR3 getOffset();

private:
	Label myLabel;
	D3DXVECTOR3 offset;
>>>>>>> Andrew
};

