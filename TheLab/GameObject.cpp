#include "GameObject.h"


GameObject::GameObject()
{
	position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	isActive = true;
	updates = true;
	visible = true;
}

GameObject::GameObject(D3DXVECTOR3 _position, D3DXVECTOR3 _rotation, D3DXVECTOR3 _scale, bool _isActive, bool _updates, bool _visible)
{
	position = _position;
	scale = _scale;
	rotation = _rotation;
	isActive = _isActive;
	updates = _updates;
	visible = _visible;
}

GameObject::GameObject(D3DXVECTOR3 _position, D3DXVECTOR3 _rotation, D3DXVECTOR3 _scale)
{
	position = _position;
	scale = _scale;
	rotation = _rotation;
	isActive = true;
	updates = true;
	visible = true;
}

GameObject::~GameObject()
{
}

void GameObject::Update(float dt)
{
	// Does not update if GameObject is not active or not updating
	if (!getActive() || !getUpdate())
	{
		return;
	}

#pragma region Update Logic

	// Enter logic here shared by all GameObject

#pragma endregion

}

void GameObject::Render()
{
	// Does not render if GameObject is not active or not visible
	if (!getActive() || !getVisible())
	{
		return;
	}

#pragma region Render Logic

	// Enter logic here shared by all GameObject

#pragma endregion
	return;
}

#pragma region Get/Set functions

D3DXVECTOR3 GameObject::getPosition()
{
	return position;
}

void GameObject::setPosition(D3DXVECTOR3 _position)
{
	position = _position;
}

D3DXVECTOR3 GameObject::getRotation()
{
	return rotation;
}

void GameObject::setRotation(D3DXVECTOR3 _rotation)
{
	rotation = _rotation;
}

D3DXVECTOR3 GameObject::getScale()
{
	return scale;
}

void GameObject::setScale(D3DXVECTOR3 _scale)
{
	scale = _scale;
}

void GameObject::setActive(bool active)
{
	isActive = active;
}

bool GameObject::getActive()
{
	return isActive;
}

void GameObject::setUpdate(bool update)
{
	updates = update;
}

bool GameObject::getUpdate()
{
	return updates;
}

void GameObject::setVisible(bool _visible)
{
	visible = _visible;
}

bool GameObject::getVisible()
{
	return visible;
}

#pragma endregion