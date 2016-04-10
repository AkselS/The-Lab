#pragma once
#include "GameObject.h"
class Character :
	public GameObject
{
public:
	Character();
	~Character();

	virtual void Update(float dt) override;
	virtual void Render() override;

protected:
	//This is the base movement speed of the character and speedMul is the multiplier for the speed.
	float baseSpeed;
	float speedMul;
};

