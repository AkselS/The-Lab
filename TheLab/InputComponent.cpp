#include "InputComponent.h"


InputComponent::InputComponent()
{
}

InputComponent::InputComponent(const InputComponent& other)
{
}

InputComponent::~InputComponent()
{
}

void InputComponent::Initialise()
{
	int i;

	for (i = 0; i < 256; i++)
	{
		keys[i] = false;
	}

	return;
}

void InputComponent::KeyDown(unsigned int input)
{
	keys[input] = true;
	return;
}

void InputComponent::KeyUp(unsigned int input)
{
	keys[input] = false;
	return;
}

bool InputComponent::isKeyDown(unsigned int key)
{
	return keys[key];
}