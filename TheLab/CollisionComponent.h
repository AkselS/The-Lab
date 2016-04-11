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

	// Return true if there are colliders in collisions
	bool isColliding;

	// Center for sphere, bottom left towards screen for AABB
	D3DXVECTOR3 position;

	// For checking if other colliders will collide with this one
	Label myLabel;
};

