#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	Player();
	Player(bool _isActive, bool _updates, bool _visible);
	~Player();

	void Update(float dt) override;
	void Render() override;

	int health;
	//inventory playerInventory;

};

