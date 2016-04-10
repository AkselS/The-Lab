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

#pragma region Get/Set function

	float getBaseSpeed();
	void setBaseSpeed(float _speed);

	float getSpeedMul();
	void setSpeedMul(float _speedMul);
	
#pragma endregion

protected:
	//This is the base movement speed of the character and speedMul is the multiplier for the speed.
	float baseSpeed;
	float speedMul;
};

