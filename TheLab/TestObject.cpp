#include "TestObject.h"

#pragma region Constructors/Destructors
TestObject::TestObject()
{
	position = { 0.0f, 0.0f, 0.0f };
	scale = { 1.0f, 1.0f, 1.0f };
	rotation = { 0.0f, 0.0f, 0.0f };
	isActive = true;
	updates = true;
	visible = true;

	mySphereCollisionComponent = SphereColliderComponent(position, 1.0f, NoLabel);
	myRigidBody = RigidBodyComponent();
}

TestObject::TestObject(D3DXVECTOR3 _position, D3DXVECTOR3 _rotation, D3DXVECTOR3 _scale, bool _isActive, bool _updates, bool _visible)
{
	position = _position;
	scale = _scale;
	rotation = _rotation;
	isActive = _isActive;
	updates = _updates;
	visible = _visible;

	mySphereCollisionComponent = SphereColliderComponent(position, 1.0f, NoLabel);
	myRigidBody = RigidBodyComponent(1.0f);
}

TestObject::TestObject(D3DXVECTOR3 _position, D3DXVECTOR3 _rotation, D3DXVECTOR3 _scale)
{
	position = _position;
	scale = _scale;
	rotation = _rotation;
	isActive = true;
	updates = true;
	visible = true;

	mySphereCollisionComponent = SphereColliderComponent(position, 1.0f, NoLabel);
	myRigidBody = RigidBodyComponent(1.0f);
}


TestObject::~TestObject()
{
	mySphereCollisionComponent.~SphereColliderComponent();
	myRigidBody.~RigidBodyComponent();
}

#pragma endregion

void TestObject::Update(float dt)
{
	GameObject::Update(dt);

	mySphereCollisionComponent.Update(this->getPosition(), dt);
}

void TestObject::Render()
{
	GameObject::Render();
}

#pragma region Get/Set functions

#pragma region Overrides

D3DXVECTOR3 TestObject::getPosition()
{
	return position;
}

void TestObject::setPosition(D3DXVECTOR3 _position)
{
	position = _position;
}

D3DXVECTOR3 TestObject::getRotation()
{
	return rotation;
}

void TestObject::setRotation(D3DXVECTOR3 _rotation)
{
	rotation = _rotation;
}

D3DXVECTOR3 TestObject::getScale()
{
	return scale;
}

void TestObject::setScale(D3DXVECTOR3 _scale)
{
	scale = _scale;
}

void TestObject::setActive(bool active)
{
	isActive = active;
}

bool TestObject::getActive()
{
	return isActive;
}

void TestObject::setUpdate(bool update)
{
	updates = update;
}

bool TestObject::getUpdate()
{
	return updates;
}

void TestObject::setVisible(bool _visible)
{
	visible = _visible;
}

bool TestObject::getVisible()
{
	return visible;
}

#pragma endregion

#pragma endregion