#pragma once
#include "GameObject.h"
#include "SphereColliderComponent.h"
#include "RigidBodyComponent.h"

class TestObject :
	public GameObject
{
public:
	TestObject();
	TestObject(D3DXVECTOR3 _position, D3DXVECTOR3 _rotation, D3DXVECTOR3 _scale, bool _isActive, bool _updates, bool _visible);
	TestObject(D3DXVECTOR3 _position, D3DXVECTOR3 _rotation, D3DXVECTOR3 _scale);
	~TestObject();

	void Update(float dt) override;
	void Render() override;

#pragma region Get/Set Function

	SphereColliderComponent* getSphereColliderComponent();

	RigidBodyComponent* getRigidBodyComponent();

#pragma region Overrides
	virtual D3DXVECTOR3 getPosition() override;
	virtual void setPosition(D3DXVECTOR3 _position)override;

	virtual D3DXVECTOR3 getRotation()override;
	virtual void setRotation(D3DXVECTOR3 _rotation)override;

	virtual D3DXVECTOR3 getScale()override;
	virtual void setScale(D3DXVECTOR3 _scale)override;

	virtual bool getActive()override;
	virtual void setActive(bool active)override;

	virtual bool getUpdate()override;
	virtual void setUpdate(bool update)override;

	virtual bool getVisible()override;
	virtual void setVisible(bool _visible)override;
#pragma endregion

#pragma endregion

protected:
	SphereColliderComponent mySphereCollisionComponent;
	RigidBodyComponent myRigidBody;
};

