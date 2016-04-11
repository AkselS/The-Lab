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
	// Clear vector of colliders in every Collider
	for (int i = 0; i < Colliders.size(); i++)
	{
		int ColliderISize = Colliders[i]->getCollisions()->size();
		for (int k = 0; k < ColliderISize; k++)
		{
			Colliders[i]->getCollisions()->pop_back();
		}
	}

	// Check colliders here
	for (int i = 0; i < Colliders.size(); i++)
	{
		// Check if Collider[i] is colliding with any other collision components
		// Excludes duplicate checks by using upper traingular
		for (int j = i + 1; j < Colliders.size(); j++)
		{
			// Does Colliders[i] label collide with Colliders[j] label?
			////Is collider[i] a sphere and Colliders[j] a sphere
			if (dynamic_cast<SphereColliderComponent*>(Colliders[i]) != NULL && dynamic_cast<SphereColliderComponent*>(Colliders[j]) != NULL)
			{
				//////Do sphere to sphere collision check
				if (sphereToSphereCollision(dynamic_cast<SphereColliderComponent*>(Colliders[i]), dynamic_cast<SphereColliderComponent*>(Colliders[j])))
				{
					OutputDebugString("Collision between object 1 and 2");
					Colliders[i]->getCollisions()->push_back(Colliders[j]);
					Colliders[j]->getCollisions()->push_back(Colliders[i]);
				}
			}
			
			////Is collider[i] a sphere and Colliders[j] a AABB
			if (dynamic_cast<SphereColliderComponent*>(Colliders[i]) != NULL && dynamic_cast<AABBColliderComponent*>(Colliders[j]) != NULL)
			{
				//////Do sphere to AABB collision check
				if (sphereToAABBCollision(dynamic_cast<SphereColliderComponent*>(Colliders[i]), dynamic_cast<AABBColliderComponent*>(Colliders[j])))
				{
					OutputDebugString("Collision between object 1 and 2");
					Colliders[i]->getCollisions()->push_back(Colliders[j]);
					Colliders[j]->getCollisions()->push_back(Colliders[i]);
				}
			}
			////Is collider[i] a AABB and collider[j] a sphere
			if (dynamic_cast<AABBColliderComponent*>(Colliders[i]) != NULL && dynamic_cast<SphereColliderComponent*>(Colliders[j]) != NULL)
			{
				//////Do AABB to sphere collision check
				if (sphereToAABBCollision(dynamic_cast<SphereColliderComponent*>(Colliders[j]), dynamic_cast<AABBColliderComponent*>(Colliders[i])))
				{
					OutputDebugString("Collision between object 1 and 2");
					Colliders[i]->getCollisions()->push_back(Colliders[j]);
					Colliders[j]->getCollisions()->push_back(Colliders[i]);
				}
			}
			
			////Is collider[i] an AABB and collider[j] an AABB
			/////Do cube to AABB collision AABB
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

bool CollisionManager::sphereToSphereCollision(SphereColliderComponent* A, SphereColliderComponent* B)
{
	D3DXVECTOR3 posA = A->getPosition();
	D3DXVECTOR3 posB = B->getPosition();
	float dX = posA.x - posB.x;
	float dY = posA.y - posB.y;
	float dZ = posA.z - posB.z;

	// Calculate the square distance between point A and point B
	float distSqr = dX*dX + dY*dY + dZ*dZ;

	bool result = false;
	// If the distance is smaller than any radius square then they have collided
	// does not use regular distance vs radius due to optimisation i.e multiplication is simpler than square rooting
	if (distSqr <= (A->getRadius()*A->getRadius()) || distSqr <= (B->getRadius()*B->getRadius()))
	{
		result = true;
	}

	return result;
}

bool CollisionManager::sphereToAABBCollision(SphereColliderComponent* A, AABBColliderComponent* B)
{
	D3DXVECTOR3 AABBmin = B->getAABBMin();
	D3DXVECTOR3 AABBmax = B->getAABBMax();
	D3DXVECTOR3 SphereCenter = A->getPosition();
	float radius = A->getRadius();
	float tempX;
	float tempY;
	float tempZ;
#pragma region Vector3.Max(SphereCenter,AABBmin)
	if (SphereCenter.x >= AABBmin.x)
	{
		tempX = SphereCenter.x;
	}
	else
	{
		tempX = AABBmin.x;
	}
	if (SphereCenter.y >= AABBmin.y)
	{
		tempY = SphereCenter.y;
	}
	else
	{
		tempY = AABBmin.y;
	}
	if (SphereCenter.z >= AABBmin.z)
	{
		tempZ = SphereCenter.z;
	}
	else
	{
		tempZ = AABBmin.z;
	}
#pragma endregion

	D3DXVECTOR3 tempV = D3DXVECTOR3(tempX, tempY, tempZ);

#pragma region Vector3.Min(tempV,AABBmax)
	if (tempV.x <= AABBmax.x)
	{
		tempX = tempV.x;
	}
	else
	{
		tempX = AABBmax.x;
	}
	if (tempV.y <= AABBmax.y)
	{
		tempY = tempV.y;
	}
	else
	{
		tempY = AABBmax.y;
	}
	if (tempV.z <= AABBmax.z)
	{
		tempZ = tempV.z;
	}
	else
	{
		tempZ = AABBmax.z;
	}

#pragma endregion

	D3DXVECTOR3 closestPoint = D3DXVECTOR3(tempX, tempY, tempZ);

	tempX = closestPoint.x - SphereCenter.x;
	tempY = closestPoint.y - SphereCenter.y;
	tempZ = closestPoint.z - SphereCenter.z;

	float distSqr = (tempX*tempX) + (tempY*tempY) + (tempZ*tempZ);

	return distSqr < (radius*radius);
}

bool CollisionManager::AABBToAABBCollision(AABBColliderComponent* A, AABBColliderComponent* B)
{
	return (A->getAABBMax().x > B->getAABBMin().x &&
		A->getAABBMin().x < B->getAABBMax().x &&
		A->getAABBMax().y > B->getAABBMin().y &&
		A->getAABBMin().y < B->getAABBMax().y &&
		A->getAABBMax().z > B->getAABBMin().z &&
		A->getAABBMin().z < B->getAABBMax().z);
}