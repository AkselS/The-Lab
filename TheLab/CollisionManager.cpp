#include "CollisionManager.h"


CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}

CollisionManager& CollisionManager::instance()
{
	static CollisionManager *instance = new CollisionManager();
	return *instance;
}

void CollisionManager::Update(float dt)
{
	// Check colliders here
	// If label collides with other label (Needs to be decided in design)
}

void CollisionManager::addCollider(CollisionComponent* _collider)
{
	Colliders.push_back(_collider);
}
