#pragma once
#include "CollisionComponent.h"
class AABBColliderComponent :
	public CollisionComponent
{
public:
	AABBColliderComponent();
	AABBColliderComponent(D3DXVECTOR3 _position, D3DXVECTOR3 _dimensions);
	AABBColliderComponent(D3DXVECTOR3 _position, D3DXVECTOR3 _dimensions, Label _label);
	AABBColliderComponent(D3DXVECTOR3 _position, D3DXVECTOR3 _dimensions, D3DXVECTOR3 _offSet);
	AABBColliderComponent(D3DXVECTOR3 _position, D3DXVECTOR3 _dimensions, D3DXVECTOR3 _offSet, Label _label);

	~AABBColliderComponent();

#pragma Get/Set Functions

#pragma region Overrides

	D3DXVECTOR3 getPosition() override;
	void setPosition(D3DXVECTOR3 _position) override;

	Label getLabel() override;
	void setLabel(Label _label) override;

#pragma endregion

	D3DXVECTOR3 getAABBMin();
	D3DXVECTOR3 getAABBMax();

#pragma endregion

private:
	D3DXVECTOR3 dimensions;
};

