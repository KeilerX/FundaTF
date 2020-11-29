#include "Zombie.h"
#include "Human.h"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

void Zombie::update(const std::vector<std::string>& levelData, std::vector<Human*>& humans, std::vector<Zombie*>& zombies)
{
	collideWithLevel(levelData);
	Human* closeHuman = getNearestHuman(humans);
	if (closeHuman != nullptr) {
		glm::vec2 direction = glm::normalize(
			closeHuman->getPosition() - _position
		);
		_position += direction * _speed;
	}
}

void Zombie::init(float speed, glm::vec2 position)
{
	_speed = speed;
	_position = position;
	//_inputManager = inputManager;
	_color.set(0, 185, 0, 255);
}

Human* Zombie::getNearestHuman(std::vector<Human*>& humans)
{
	Human* closestHuman = nullptr;
	float smallestDistance = 8888888888.0f;
	for (size_t i = 0; i < humans.size(); i++) {
		glm::vec2 dist = humans[i]->getPosition() - _position;
		float distance = glm::length(dist);
		if (distance < smallestDistance) {
			smallestDistance = distance;
			closestHuman = humans[i];
		}
	}
	return closestHuman;
}
