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
	for (int i = 0; i < Colliders.size(); i++)
	{
		for (int j = i + 1; j < Colliders.size(); j++)
		{
			// Does Colliders[i] label collide with Colliders[j] label?
			////Is collider[i] a sphere and Colliders[j] a sphere
			//////Do sphere to sphere collision check
			////Is collider[i] a sphere and Colliders[j] a cube
			//////Do sphere to box collision check
			////Is collider[i] a box and collider[j] a sphere
			//////Do cube to sphere collision check
			////Is collider[i] a box and collider[j] a box
			/////Do cube to cube collision check
			//

		}
	}

}

//void CollisionManager::addCollider(CollisionComponent* _collider)
//{
//	Colliders.push_back(_collider);
//}


void CollisionManager::addCollider(CollisionComponent* _collider)
{
	Colliders.push_back(_collider);
}