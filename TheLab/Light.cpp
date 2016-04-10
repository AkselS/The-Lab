#include "Light.h"


Light::Light()
{

}

Light::Light(const Light&)
{

}

Light::~Light()
{

}

void Light::setDiffuseColour(float r, float g, float b, float a)
{
	diffuseColour = (D3DXVECTOR4(r, g, b, a));
	return;
}

void Light::setDirection(float x, float y, float z)
{
	direction = (D3DXVECTOR3(x, y, z));
	return;
}

D3DXVECTOR4 Light::GetDiffuseColour()
{
	return diffuseColour;
}

D3DXVECTOR3 Light::GetDirection()
{
	return direction;
}