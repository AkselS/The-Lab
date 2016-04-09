#include "Player.h"

Player::Player()
{

}

Player::Player(bool _isActive, bool _updates, bool _visible)
{
	setActive(_isActive);
	setUpdate(_updates);
	setVisible(_visible);
}

Player::~Player()
{
}

void Player::Update(float dt)
{
	// Does not update if Player is not active or not updating
	if (!getActive() || !getUpdate())
	{
		return;
	}

	// Calls base function for update logic shared by all characters
	Character::Update(dt);

#pragma region Update Logic

	// Enter update logic here

#pragma endregion

}

void Player::Render()
{
	// Does not render if GameObject is not active or not visible
	if (!getActive() || !getVisible())
	{
		return;
	}

	// Calls base function for render logic shared by all characters
	Character::Render();

#pragma region RenderLogic

	// Enter render logic here

#pragma endregion

}