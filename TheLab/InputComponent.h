#pragma once
class InputComponent
{
public:
	InputComponent();
	InputComponent(const InputComponent&);
	~InputComponent();

	void Initialise();

	void KeyDown(unsigned int);
	void KeyUp(unsigned int);
	bool isKeyDown(unsigned int);

private:
	bool keys[256];
};

