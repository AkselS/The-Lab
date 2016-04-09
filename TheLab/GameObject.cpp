#include "GameObject.h"


GameObject::GameObject()
{
	position = { 0.0f, 0.0f, 0.0f };
	scale = { 1.0f, 1.0f, 1.0f };
	rotation = { 0.0f, 0.0f, 0.0f };
	isActive = true;
	updates = true;
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