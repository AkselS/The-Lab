#include "CameraComponent.h"

Camera::Camera(void)
{
	cPosition = XMFLOAT3(0.0f, 0.0f, -1.0f);
	cTarget = XMFLOAT3(0.0f, 0.0f, 0.0f);
	cUp = MathVF(MathFV(cPosition) + MathFV(XMFLOAT3(0, 1, 0)));
	this->initViewMatrix();

	cAngle = 0.0f;
	wClientWidth = 0.0f;
	wClientHeight = 0.0f;
	vNearest = 0.0f;
	vFarthest = 0.0f;

	XMStoreFloat4x4(&mView, XMMatrixIdentity());
	XMStoreFloat4x4(&mProj, XMMatrixIdentity());
	XMStoreFloat4x4(&mOrtho, XMMatrixIdentity());
}

Camera::Camera(const Camera& cam)
{
	*this = cam;
}

Camera& Camera::operator=(const Camera& cam)
{
	cPosition = cam.cPosition;
	cTarget = cam.cTarget;
	cUp = cam.cUp;

	cAngle = cam.cAngle;
	wClientWidth = cam.wClientWidth;
	wClientHeight = cam.wClientHeight;
	vNearest = cam.vNearest;
	vFarthest = cam.vFarthest;

	mView = cam.mView;
	mProj = cam.mProj;
	mOrtho = cam.mOrtho;
	return *this;
}

void Camera::initViewMatrix()
{
	XMStoreFloat4x4(&mView, XMMatrixLookAtLH(XMLoadFloat3(&cPosition), XMLoadFloat3(&cTarget), XMLoadFloat3(&this->Up())));
}

void Camera::InitProjMatrix(const float angle, const float client_width, const float client_height,
	const float near_plane, const float far_plane)
{
	cAngle = angle;
	wClientWidth = client_width;
	wClientHeight = client_height;
	vNearest = near_plane;
	vFarthest = far_plane;
	XMStoreFloat4x4(&mProj, XMMatrixPerspectiveFovLH(angle, client_width / client_height, near_plane, far_plane));
}

void Camera::Move(XMFLOAT3 direction)
{
	cPosition = MathVF(XMVector3Transform(MathFV(cPosition), XMMatrixTranslation(direction.x, direction.y, direction.z)));
	cTarget = MathVF(XMVector3Transform(MathFV(cTarget), XMMatrixTranslation(direction.x, direction.y, direction.z)));
	cUp = MathVF(XMVector3Transform(MathFV(cUp), XMMatrixTranslation(direction.x, direction.y, direction.z)));

	this->initViewMatrix();
}

void Camera::Rotate(XMFLOAT3 axis, float degrees)
{
	if (XMVector3Equal(MathFV(axis), XMVectorZero()) ||
		degrees == 0.0f)
		return;

	// rotate vectors
	XMFLOAT3 look_at_target = MathVF(MathFV(cTarget) - MathFV(cPosition));
	XMFLOAT3 look_at_up = MathVF(MathFV(cUp) - MathFV(cPosition));
	look_at_target = MathVF(XMVector3Transform(MathFV(look_at_target), XMMatrixRotationAxis(MathFV(axis), XMConvertToRadians(degrees))));
	look_at_up = MathVF(XMVector3Transform(MathFV(look_at_up), XMMatrixRotationAxis(MathFV(axis), XMConvertToRadians(degrees))));

	// restore vectors's end points mTarget and mUp from new rotated vectors
	cTarget = MathVF(MathFV(cPosition) + MathFV(look_at_target));
	cUp = MathVF(MathFV(cPosition) + MathFV(look_at_up));

	this->initViewMatrix();
}

void Camera::Target(XMFLOAT3 new_target)
{
	if (XMVector3Equal(MathFV(new_target), MathFV(cPosition)) ||
		XMVector3Equal(MathFV(new_target), MathFV(cTarget)))
		return;

	XMFLOAT3 old_look_at_target = MathVF(MathFV(cTarget) - MathFV(cPosition));
	XMFLOAT3 new_look_at_target = MathVF(MathFV(new_target) - MathFV(cPosition));
	float angle = XMConvertToDegrees(XMVectorGetX(XMVector3AngleBetweenNormals(XMVector3Normalize(MathFV(old_look_at_target)), XMVector3Normalize(MathFV(new_look_at_target)))));
	if (angle != 0.0f && angle != 360.0f && angle != 180.0f)
	{
		XMVECTOR axis = XMVector3Cross(MathFV(old_look_at_target), MathFV(new_look_at_target));
		Rotate(MathVF(axis), angle);
	}
	cTarget = new_target;
	this->initViewMatrix();
}

// Set camera position
void Camera::Position(XMFLOAT3& new_position)
{
	XMFLOAT3 move_vector = MathVF(MathFV(new_position) - MathFV(cPosition));
	XMFLOAT3 target = cTarget;
	this->Move(move_vector);
	this->Target(target);
}

void Camera::Angle(float angle)
{
	cAngle = angle;
	InitProjMatrix(cAngle, wClientWidth, wClientHeight, vNearest, vFarthest);
}

void Camera::NearestPlane(float nearest)
{
	vNearest = nearest;
	OnResize(wClientWidth, wClientHeight);
}

void Camera::FarthestPlane(float farthest)
{
	vFarthest = farthest;
	OnResize(wClientWidth, wClientHeight);
}

void Camera::InitOrthoMatrix(const float clientWidth, const float clientHeight,
	const float nearZ, const float fartherZ)
{
	XMStoreFloat4x4(&mOrtho, XMMatrixOrthographicLH(clientWidth, clientHeight, 0.0f, fartherZ));
}

void Camera::OnResize(uint32_t new_width, uint32_t new_height)
{
	wClientWidth = new_width;
	wClientHeight = new_height;
	InitProjMatrix(cAngle, static_cast<float>(new_width), static_cast<float>(new_height), vNearest, vFarthest);
	InitOrthoMatrix(static_cast<float>(new_width), static_cast<float>(new_height), 0.0f, vFarthest);
}