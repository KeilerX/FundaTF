#pragma once
#include <algorithm>
#include "Game.h"
#include "GamePlayScreen.h"
#include "MenuPlayScreen.h"

class App : public Game
{
public:
	App();
	~App();
	virtual void onInit() override;
	virtual void addScreens() override;
	virtual void onExit() override;
private:
	//aqu� se declara todas las pantallas que se tendr�n en el juego
	std::unique_ptr<MenuPlayScreen> _menuScreen = nullptr;
	std::unique_ptr<GamePlayScreen> _gamePlayScreen = nullptr;
};

