#include "SDL.h"
#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	int currentFrameTime, lastFrameTime = 0;
	float dt;

	game = new Game();
	game->init("Assdroids", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

	while (game->isRunning())
	{
		currentFrameTime = SDL_GetTicks();
		dt = (currentFrameTime - lastFrameTime) * 0.001f;

		game->handleEvents();
		game->update(dt);
		game->render();

		lastFrameTime = SDL_GetTicks();
	}

	game->clean();
	delete game;

	return 0;
}