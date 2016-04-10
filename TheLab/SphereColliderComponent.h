#pragma once

#include "CollisionComponent.h"



class SphereColliderComponent :
	CollisionComponent
{
public:
	SphereColliderComponent();

	SphereColliderComponent(GameObject* _parentObject, float _radius);

	SphereColliderComponent(GameObject* _parentObject, float _radius, Label _label, D3DXVECTOR3 _offSet);

	SphereColliderComponent(GameObject* _parentObject, float _radius, Label _label);

	SphereColliderComponent(GameObject* _parentObject, float _radius, D3DXVECTOR3 _offSet);

	~SphereColliderComponent();

	void Initialise() override;

	void Update(float dt) override;


#pragma region Get/Set function
#pragma region Overrides
	 GameObject* getParentObject() override;
	 void setParentObject(GameObject* _parentObject) override;

	 D3DXVECTOR3 getPosition();
	 void setPosition(D3DXVECTOR3 _position) override;

	 Label getLabel() override;
	 void setLabel(Label _label) override;

	 D3DXVECTOR3 getOffset() override;
	 void setOffSet(D3DXVECTOR3 _offset) override;
#pragma endregion
	
	float getRadius();
	void setRadius(float _radius);

#pragma endregion

protected:
	float radius;
};

