#include "Character.h"


Character::Character()
{
}


Character::~Character()
{
}

void Character::Update(float dt)
{
	// Does not update if Character is not active or not updating
	if (!getActive() || !getUpdate())
	{
		return;
	}

	// Call base function for logic shared by all gameobjects
	GameObject::Update(dt);

#pragma region Update Logic

	// Enter logic here shared by all game characters

#pragma endregion

}

void Character::Render()
{
	// Does not render if GameObject is not active or not visible
	if (!getActive || !getVisible)
	{
		return;
	}

	// Call base function for logic shared by all gameobjects
	GameObject::Render();

#pragma region Render Logic

	// Enter logic here shared by all characters

#pragma endregion

}

