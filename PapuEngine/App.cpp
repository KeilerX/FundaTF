#include "App.h"
#include "ScreenList.h"

App::App()
{
}

App::~App()
{
}

void App::onInit()
{
}

void App::addScreens()
{
	//_gamePlayScreen = std::make_unique<GamePlayScreen>(&_window);
	_menuScreen = std::make_unique<MenuPlayScreen>(&_window);
	_screenList->addScreen(_menuScreen.get());
	//_screenList->addScreen(_gamePlayScreen.get());

	_screenList->setScreen(_menuScreen->getIndex());
}

void App::onExit()
{
}
