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

	virtual void Update(float dt);
	virtual void Render();
	
#pragma region Get/Set functions
	D3DXVECTOR3 getPosition();
	void setPosition(D3DXVECTOR3 _position);

	D3DXVECTOR3 getRotation();
	void setRotation(D3DXVECTOR3 _rotation);

	D3DXVECTOR3 getScale();
	void setScale(D3DXVECTOR3 _scale);

	bool getActive();
	void setActive(bool active);

	bool getUpdate();
	void setUpdate(bool update);

	bool getVisible();
	void setVisible(bool _visible);

#pragma endregion

protected:
	//declare the pos, rot, and scale as a 3D vector of floats
	D3DXVECTOR3 position;
	D3DXVECTOR3 rotation;
	D3DXVECTOR3 scale;

	// Is the object active?
	bool isActive;

	// Does the object update?
	bool updates;

	// Does the object render?
	bool visible;
};

