#include "InputComponent.h"


InputComponent::InputComponent()
{
	m_directInput = 0;
	m_keyboard = 0;
	m_mouse = 0;

}

InputComponent::InputComponent(const InputComponent& other)
{
}

InputComponent::~InputComponent()
{
	// used to realse the mouse
	if (m_mouse)
	{
		m_mouse->Unacquire();
		m_mouse->Release();
		m_mouse = 0;
	}
	if (m_keyboard)
	{
		m_keyboard->Unacquire();
		m_keyboard->Release();
		m_keyboard = 0;
	}
}

bool InputComponent::Initialise(HINSTANCE hinstance, HWND hwnd ,int screenWidth, int screenHeight)
{
	int i;
	m_screenHeight = screenHeight;
	m_screenWidth = screenWidth;
	HRESULT result;
	for (i = 0; i < 256; i++)
	{
		keys[i] = false;
	}
	m_mouseX = 0;
	m_mouseY = 0;
	// initialize direct input interface 
	result = DirectInput8Create(hinstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_directInput, NULL);
	if (FAILED(result))
	{
		return false;
	}
	//initialize keyboard interface
	result = m_directInput->CreateDevice(GUID_SysKeyboard, &m_keyboard, NULL);
	if (FAILED(result))
	{
		return false;
	}
	//// sets data formate for the keyboard
	result = m_keyboard->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(result))
	{
		return false;
	}
	//
	result = m_keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE);
	if (FAILED(result))
	{
		return false;
	}
	result = m_keyboard->Acquire();
	if (FAILED(result))
	{
		return false;
	}
	return true;

	// initialize mouse interface
	result = m_directInput->CreateDevice(GUID_SysMouse, &m_mouse, NULL);
	if (FAILED(result))
	{
		return false;
	}
	result = m_mouse->SetDataFormat(&c_dfDIMouse);
	if (FAILED(result))
	{
		return false;
	}
	result = m_mouse->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(result))
	{
		return false;
	}
	result = m_mouse->Acquire();
	if (FAILED(result))
	{
		return false;
	}
	//
}
bool InputComponent::update()
{
	bool result;
	//read keyboard input
	result = ReadKeyBoard();
	if (!result)
	{
		return false;
	}
	//read mouse
	result = ReadMouse();
	if (!result)
	{
		return false;
	}
	//update mouse posisition
	ProcessInput();
	return true;
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
bool InputComponent::ReadKeyBoard()
{
	HRESULT result;
	//read keyboar
	result = m_keyboard->GetDeviceState(sizeof(keys), (LPVOID)&keys);
	if (FAILED(result))
	{
		if (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED)
			{
				m_keyboard->Acquire(); 

             }
		else
		{
			return false;
		}
	}
	return true;

}
bool InputComponent::ReadMouse()
{
	HRESULT result;
	if (m_mouse = NULL)
	{
		m_directInput->CreateDevice(GUID_SysMouse, &m_mouse, NULL);
		return false;
	}
	result = m_mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&m_mouseState);
	if (FAILED(result))
	{
		if (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED)
		{
			m_keyboard->Acquire();

		}
		else
		{
			return false;
		}
	}
}
void InputComponent::ProcessInput()
{
	m_mouseX += m_mouseState.lX;
	m_mouseX += m_mouseState.lY;
	if (m_mouseX < 0)m_mouseX = 0;
	if (m_mouseY < 0)m_mouseY = 0;
	if (m_mouseX > m_screenWidth)m_mouseX = m_screenWidth;
	if (m_mouseY > m_screenHeight)m_mouseX = m_screenHeight;
}