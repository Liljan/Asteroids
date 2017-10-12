#pragma once

#include "SDL.h"
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int x, int y, int width, int height, bool fullScreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool isRunning() { return isGameRunning; }

private:
	bool isGameRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

