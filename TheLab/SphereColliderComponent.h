#pragma once

#include "CollisionComponent.h"



class SphereColliderComponent :
	CollisionComponent
{
public:
	SphereColliderComponent();

	SphereColliderComponent(D3DXVECTOR3 parentPosition, float _radius);

	SphereColliderComponent(D3DXVECTOR3 parentPosition, float _radius, Label _label, D3DXVECTOR3 _offSet);

	SphereColliderComponent(D3DXVECTOR3 parentPosition, float _radius, Label _label);

	SphereColliderComponent(D3DXVECTOR3 parentPosition, float _radius, D3DXVECTOR3 _offSet);

	~SphereColliderComponent();

	void Initialise(D3DXVECTOR3 thisPosition) override;

	void Update(D3DXVECTOR3 thisPosition, float dt) override;


#pragma region Get/Set function
#pragma region Overrides

	 D3DXVECTOR3 getPosition();
	 void setPosition(D3DXVECTOR3 _position) override;

	 Label getLabel() override;
	 void setLabel(Label _label) override;

#pragma endregion
	
	float getRadius();
	void setRadius(float _radius);

#pragma endregion

protected:
	float radius;
};

