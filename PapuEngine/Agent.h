#pragma once
#include <glm/glm.hpp>
#include "SpriteBacth.h"
#include "GLTexture.h"
#include <string>

class Zombie;
class Human;

const float AGENT_WIDTH = 60.0f;
const float AGENT_RADIUS = AGENT_WIDTH / 2.0f;
class Agent
{
protected:
	glm::vec2 _position;
	float _speed;
	Color _color;
	//TO-DO MORE METHODS
	void checkTilePosition(const std::vector<std::string>& levelData,
		std::vector<glm::vec2>& collidePosition, float x, float y);
	void collideWithTile(glm::vec2 tilePos);
public:
	Agent();
	virtual ~Agent();
	virtual void update(const std::vector<std::string>& levelData, std::vector<Human*>& humans, std::vector<Zombie*>& zombies) = 0;
	bool collideWithLevel(const std::vector<std::string>& levelData);
	bool collideWithAgent(Agent* agent);
	glm::vec2 getPosition()const { return _position; }
	void draw(SpriteBacth& spriteBatch);
};

