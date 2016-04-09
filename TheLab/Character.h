#pragma once
#include "GameObject.h"
class Character :
	public GameObject
{
public:
	Character();
	~Character();

	//This is the base movement speed of the character and speedMul is the multiplier for the speed.
	float baseSpeed, speedMul;

	virtual void Update(float dt) override;
	virtual void Render() override;
};
