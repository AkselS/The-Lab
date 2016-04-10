#pragma once

#include <d3dx10math.h>
#include "GameObject.h"

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

	virtual void Initialise(D3DXVECTOR3 thisPosition);

	virtual void Update(D3DXVECTOR3 thisPosition, float dt);

#pragma region Get/Set functions

	virtual D3DXVECTOR3 getPosition();
	virtual void setPosition(D3DXVECTOR3 _position);

	virtual Label getLabel();
	virtual void setLabel(Label _label);

#pragma endregion

protected:
	D3DXVECTOR3 position;
	Label myLabel;
};

