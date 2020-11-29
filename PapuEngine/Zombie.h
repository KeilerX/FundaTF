#pragma once
#include "Agent.h"
#include "InputManager.h"
class Zombie : public Agent
{
private:
	InputManager* _inputManager;
protected:
	glm::vec2 _direction;
public:
	Zombie();
	~Zombie();
	void update(const std::vector<std::string>& levelData, std::vector<Human*>& humans, std::vector<Zombie*>& zombies);
	void init(float speed, glm::vec2 position);
	Human* getNearestHuman(std::vector<Human*>& humans);
};

