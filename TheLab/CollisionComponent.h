#pragma once

#include <d3dx10math.h>
#include <vector>

#include "GameObject.h"

enum Label
{
	NoLabel,
	Player,
	LevelArchitecture,
	Object,
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

	virtual std::vector<CollisionComponent*>* getCollisions();
	virtual bool getIsColliding();

#pragma endregion

protected:
	// To be pushed and popped to by CollisionManager (Clears on Update)
	std::vector<CollisionComponent*> collisions;

	bool isColliding;
	D3DXVECTOR3 position;
	Label myLabel;
};

