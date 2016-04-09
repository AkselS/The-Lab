#pragma once

#include <DirectXMath.h>
#include <string.h>

class State
{
public:
	State();
	~State();

	//
	virtual void Enter();
	virtual void Update(float dt);
	virtual void Render();
	virtual void Exit();

};

