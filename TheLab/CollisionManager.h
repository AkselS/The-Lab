#pragma once

#include "SphereColliderComponent.h"
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
};
