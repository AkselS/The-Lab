#pragma once

#include "SphereColliderComponent.h"
#include "AABBColliderComponent.h"
#include <vector>

class CollisionManager
{
public:
	static CollisionManager& instance();
	~CollisionManager();

	void Update(float dt);

	void addCollider(CollisionComponent* _collider);

private:
	CollisionManager();
	
	std::vector<CollisionComponent*> Colliders;

	bool sphereToSphereCollision(SphereColliderComponent* A, SphereColliderComponent* B);

	bool sphereToAABBCollision(SphereColliderComponent* A, AABBColliderComponent* B);

	bool AABBToAABBCollision(AABBColliderComponent* A, AABBColliderComponent* B);
};
