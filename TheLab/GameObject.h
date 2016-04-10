#pragma once
#include <d3dx10math.h>
#include <vector>

class GameObject
{
public:
	GameObject();
	GameObject(D3DXVECTOR3 _position, D3DXVECTOR3 _rotation, D3DXVECTOR3 _scale, bool _isActive, bool _updates, bool _visible);
	GameObject(D3DXVECTOR3 _position, D3DXVECTOR3 _rotation, D3DXVECTOR3 _scale);

	~GameObject();

	virtual void Update(float dt);
	virtual void Render();
	
#pragma region Get/Set functions
	virtual D3DXVECTOR3 getPosition();
	virtual void setPosition(D3DXVECTOR3 _position);

	virtual D3DXVECTOR3 getRotation();
	virtual void setRotation(D3DXVECTOR3 _rotation);

	virtual D3DXVECTOR3 getScale();
	virtual void setScale(D3DXVECTOR3 _scale);

	virtual bool getActive();
	virtual void setActive(bool active);

	virtual bool getUpdate();
	virtual void setUpdate(bool update);

	virtual bool getVisible();
	virtual void setVisible(bool _visible);

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

