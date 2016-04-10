#include "CameraComponent.h"

Camera::Camera()
{
	positionX = 0;
	positionY = 0;
	positionZ = 0;

	rotationX = 0;
	rotationY = 0;
	rotationZ = 0;
}

Camera::Camera(const Camera&)
{

}

Camera::~Camera()
{

}

void Camera::setPosition(float x, float y, float z)
{
	positionX = x;
	positionY = y;
	positionZ = z;
	return;
}

void Camera::setRotation(float x, float y, float z)
{
	rotationX = x;
	rotationY = y;
	rotationZ = z;
}

D3DXVECTOR3 Camera::GetPosition()
{
	return D3DXVECTOR3(positionX, positionY, positionZ);
}

D3DXVECTOR3 Camera::GetRotation()
{
	return D3DXVECTOR3(rotationX, rotationY, rotationZ);
}

void Camera::Render()
{
	D3DXVECTOR3 up, position, lookAt;
	float yaw, pitch, roll;
	D3DXMATRIX rotationMatrix;

	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;

	position.x = positionX;
	position.y = positionY;
	position.z = positionZ;

	lookAt.x = 0.0f;
	lookAt.y = 0.0f;
	lookAt.z = 1.0f;

	pitch = rotationX * 0.0174532925f;
	yaw = rotationY * 0.0174532925f;
	roll = rotationZ * 0.0174532925f;

	D3DXMatrixRotationYawPitchRoll(&rotationMatrix, yaw, pitch, roll);

	D3DXVec3TransformCoord(&lookAt, &lookAt, &rotationMatrix);
	D3DXVec3TransformCoord(&up, &up, &rotationMatrix);

	lookAt = position + lookAt;

	D3DXMatrixLookAtLH(&viewMatrix, &position, &lookAt, &up);

	return;
}

void Camera::GetViewMatrix(D3DXMATRIX& nViewMatrix)
{
	nViewMatrix = viewMatrix;
}