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

}

void GameObject::Render()
{

}