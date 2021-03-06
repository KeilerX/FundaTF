#include "ScreenList.h"
#include "IGameScreen.h"

ScreenList::ScreenList(Game* game) : _game(game)
{
}

ScreenList::~ScreenList()
{
    destroy();
}

IGameScreen* ScreenList::moveNext()
{
    IGameScreen* currentScreen = getCurrent();
    if (currentScreen->getNextScreen() != -1) {
        _currentIndex = currentScreen->getNextScreen();
    }
    return getCurrent();
}

IGameScreen* ScreenList::movePrev()
{
    IGameScreen* currentScreen = getCurrent();
    if (currentScreen->getPrevScreen() != -1) {
        _currentIndex = currentScreen->getPrevScreen();
    }
    return getCurrent();
}

void ScreenList::setScreen(int nextScreen)
{
    _currentIndex = nextScreen;
}

void ScreenList::addScreen(IGameScreen* newScreen)
{
    newScreen->_screenIndex = _screens.size();
    _screens.push_back(newScreen);
    newScreen->build();
    newScreen->setParent(_game);
}

void ScreenList::destroy()
{
    for (size_t i = 0; i < _screens.size(); i++) {
        _screens[i]->destroy();
    }
    _currentIndex = -1;
    _screens.resize(0);
}

IGameScreen* ScreenList::getCurrent()
{
    if (_currentIndex == -1) {
        return nullptr;
    }
    return _screens[_currentIndex];
}
