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

#pragma region Get/Set functions
	GameObject* getParentObject();
	void setParentObject(GameObject* _parentObject);

	Label getLabel();
	void setLabel(Label _label);

	D3DXVECTOR3 getOffset();
	void setOffSet(D3DXVECTOR3 _offset);
#pragma endregion

protected:
	GameObject* parentObject;
	D3DXVECTOR3 position;
	Label myLabel;
	D3DXVECTOR3 offset;
};

