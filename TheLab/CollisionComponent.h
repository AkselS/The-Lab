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

	virtual void Initialise();

	virtual void Update(float dt);

#pragma region Get/Set functions
	virtual GameObject* getParentObject();
	virtual void setParentObject(GameObject* _parentObject);

	virtual D3DXVECTOR3 getPosition();
	virtual void setPosition(D3DXVECTOR3 _position);

	virtual Label getLabel();
	virtual void setLabel(Label _label);

	virtual D3DXVECTOR3 getOffset();
	virtual void setOffSet(D3DXVECTOR3 _offset);
#pragma endregion

protected:
	GameObject* parentObject;
	D3DXVECTOR3 position;
	Label myLabel;
	D3DXVECTOR3 offset;
};

