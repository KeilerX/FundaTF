#pragma once
#include "IGameScreen.h"
#include "Window.h"
#include "SpriteBacth.h"

class MenuPlayScreen : public IGameScreen
{
private:
	Window* _window = nullptr;
	SpriteBacth _spriteBatch;
public:
	MenuPlayScreen(Window* window);
	virtual void build() override;
	virtual void destroy() override;
	virtual void onExit() override;
	virtual void onEntry() override;

	virtual void initGUI()override;
	virtual void draw()override;
	virtual void update()override;
	virtual void initSystem() override;
	virtual int getNextScreen() const override;
	virtual int getPrevScreen() const override;
	virtual void checkInput() override;
	~MenuPlayScreen();
};

