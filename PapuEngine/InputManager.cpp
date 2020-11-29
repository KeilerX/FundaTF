#include "InputManager.h"

void InputManager::pressKey(unsigned int keyCode) {
	_keyMap[keyCode] = true;
}

void InputManager::releaseKey(unsigned int keyCode) {
	_keyMap[keyCode] = false;

}

bool InputManager::isKeyDown(unsigned int keyCode)
{
	auto it = _keyMap.find(keyCode);
	if (it != _keyMap.end()) {
		return it->second;
	}
	return false;
}

bool InputManager::isKeyPressed(unsigned int keyCode) {
	if (isKeyDown(keyCode) && !wasKeyDown(keyCode)) {
		return true;
	}
	return false;
}

void InputManager::update()
{
	for (auto& it : _keyMap) {
		_previousMap[it.first] = it.second;
	}
}

void InputManager::setMouseCoords(float x, float y) {
	_mouseCoords.x = x;
	_mouseCoords.y = y;
}

bool InputManager::wasKeyDown(unsigned int keyCode)
{
	auto it = _previousMap.find(keyCode);
	if (it != _previousMap.end()) {
		return it->second;
	}
	return false;
}

InputManager::InputManager():_mouseCoords(0.0f,0.0f)
{
}


InputManager::~InputManager()
{
}
