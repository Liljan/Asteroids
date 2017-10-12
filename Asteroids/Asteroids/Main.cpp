#include "SDL.h"
#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	game = new Game();
	game->init("Assdroids", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

	while (game->isRunning())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();
	delete game;

	return 0;
}