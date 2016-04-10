#ifndef _LIGHT_H_
#define _LIGHT_H_

#include <D3DX10math.h>

class Light
{
public:
	Light();
	Light(const Light&);
	~Light();

	void setDiffuseColour(float, float, float, float);
	void setDirection(float, float, float);

	D3DXVECTOR4 GetDiffuseColour();
	D3DXVECTOR3 GetDirection();

private:
	D3DXVECTOR4 diffuseColour;
	D3DXVECTOR3 direction;
};

#endif