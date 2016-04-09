#pragma once
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10math.h>
#include <vector>

class GameObject
{
public:
	GameObject();
	~GameObject();

	//declare the pos, rot, and scale as a 3D vector of floats
	D3DXVECTOR3 position, rotation, scale;

	void setActive(bool active);
	bool getActive();

	void setUpdate(bool update);
	bool getUpdate();

	void setVisible(bool _visible);
	bool getVisible();

	virtual void Update(float dt);
	virtual void Render();

private:
	// Is the object active?
	bool isActive;

	// Does the object update?
	bool updates;

	// Does the object render?
	bool visible;
};

