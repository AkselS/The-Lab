#pragma once
#include <dinput.h>
#define DIRECTINPUT_VERSION 0x0800
class InputComponent
{
public:
	InputComponent();
	InputComponent(const InputComponent&);
	~InputComponent();
	bool Initialise(HINSTANCE hinstance, HWND hwdn, int screenWidth , int screenHeight);
	void GetMousePos(int& x, int& y);
	void KeyDown(unsigned int);
	void KeyUp(unsigned int);
	bool isKeyDown(unsigned int);
	bool update();

private:
	bool keys[256];
	bool prevKeys[256];
	int m_mouseX;
	int m_mouseY;
	bool ReadKeyBoard();
	bool ReadMouse();
	void ProcessInput();
	int m_screenWidth;
	 int m_screenHeight;
	IDirectInput8 * m_directInput;
	IDirectInputDevice8* m_keyboard;
	IDirectInputDevice8* m_mouse;
	DIMOUSESTATE m_mouseState;


};
