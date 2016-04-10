#ifndef _CAMERACOMPONENT_H_
#define _CAMERACOMPONENT_H_

#include <d3dx10math.h>

class Camera
{
public:
	Camera();
	Camera(const Camera&);
	~Camera();

	void setPosition(float, float, float);
	void setRotation(float, float, float);
	
	D3DXVECTOR3 GetPosition();
	D3DXVECTOR3 GetRotation();

	void Render();
	void GetViewMatrix(D3DXMATRIX&);

private:
	float positionX, positionY, positionZ;
	float rotationX, rotationY, rotationZ;
	D3DXMATRIX viewMatrix;
};

#endif