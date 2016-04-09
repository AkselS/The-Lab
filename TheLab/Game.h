#pragma once
#include "DX11Base.h"
class Game :
	public DX11Base
{
public:
	Game();
	virtual ~Game();

	bool LoadContent();
	void UnloadContent();

	void Update(float dt);
	void Render();
};

