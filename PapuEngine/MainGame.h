#pragma once
#include <SDL\SDL.h>
#include <GL\glew.h>
#include "GLS_Program.h"
#include "Sprite.h"
#include "Window.h"
#include "Camera2D.h"
#include <vector>
#include "SpriteBacth.h"
#include "InputManager.h"
#include "Level.h"
#include "Player.h"
#include "Zombie.h"
#include "Human.h"
#include "SoundManager.h"

enum class GameState
{
	PLAY, EXIT
};


class MainGame
{
private:
	int _witdh;
	int _height;
	float _time;
	vector<Level*> _levels;
	Player* _player;
	vector<Zombie*> _zombies;
	vector<Human*> _humans;
	int _currentLevel;
	Window _window;
	void init();
	void procesInput();
	GLS_Program _program;
	vector<Sprite*> _sprites;
	Camera2D _camera;
	SpriteBacth _spriteBacth;
	InputManager _inputManager;
	SoundManager* _soundManager;
	void initLevel();
	
public:
	MainGame();
	~MainGame();
	GameState _gameState;
	void initShaders();
	void run();
	void draw();
	void update();
};

