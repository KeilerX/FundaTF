#include "Player.h"
#include <SDL\SDL.h>

Player::Player()
{
}

Player::~Player()
{
}

void Player::update(const std::vector<std::string>& levelData, std::vector<Human*>& humans, std::vector<Zombie*>& zombies)
{
	if (_inputManager->isKeyPressed(SDLK_w)) {
		_position.y += _speed;
	}
	if (_inputManager->isKeyPressed(SDLK_s)) {
		_position.y -= _speed;
	}
	if (_inputManager->isKeyPressed(SDLK_a)) {
		_position.x -= _speed;
	}
	if (_inputManager->isKeyPressed(SDLK_d)) {
		_position.x += _speed;
	}
	collideWithLevel(levelData);
}

void Player::init(float speed, glm::vec2 position, 
	InputManager* inputManager)
{
	_speed = speed;
	_position = position;
	_inputManager = inputManager;
	_color.set(0, 0, 185, 255);
}