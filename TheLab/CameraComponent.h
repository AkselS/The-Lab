#pragma once
#include "Util.h"

using namespace std;

class Camera
{
public:
	Camera(void);
	Camera(const Camera& cam);
	Camera& operator=(const Camera& cam);
	~Camera(void) {}

private:
	void initViewMatrix();

public:
	void InitProjMatrix(const float angle, const float client_width, const float client_height,
		const float nearest, const float farthest);
	void InitOrthoMatrix(const float client_width, const float client_height,
		const float near_plane, const float far_plane);

	void OnResize(uint32_t new_width, uint32_t new_height);



	void Move(XMFLOAT3 direction);
	void Rotate(XMFLOAT3 axis, float degrees);
	void Position(XMFLOAT3& new_position);
	const XMFLOAT3& Position() const { return cPosition; }
	void Target(XMFLOAT3 new_target);
	const XMFLOAT3& Target() const { return cTarget; }
	const XMFLOAT3 Up() { return MathVF(MathFV(cUp) - MathFV(cPosition)); }
	const XMFLOAT3 LookAtTarget() { return MathVF(MathFV(cTarget) - MathFV(cPosition)); }
	const XMFLOAT4X4 View() { return MathMF(XMMatrixTranspose(MathFM(mView))); }



	void Angle(float angle);
	const float& Angle() const { return cAngle; }

	void NearestPlane(float nearest);
	void FarthestPlane(float farthest);

	const XMFLOAT4X4 Proj() { return MathMF(XMMatrixTranspose(MathFM(mProj))); }
	const XMFLOAT4X4 Ortho() { return MathMF(XMMatrixTranspose(MathFM(mOrtho))); }

private:
	XMFLOAT3 cPosition;
	XMFLOAT3 cTarget;
	XMFLOAT3 cUp;

	float cAngle;
	float wClientWidth;
	float wClientHeight;
	float vNearest;
	float vFarthest;

	XMFLOAT4X4  mView;
	XMFLOAT4X4	mProj;
	XMFLOAT4X4	mOrtho;
};