#include "Game.h"

Game::Game()
{
}


Game::~Game()
{
}

void Game::init(const char * title, int x, int y, int width, int height, bool fullScreen)
{
	int flags = 0;

	if (fullScreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "All subsystems initialized..." << std::endl;

		window = SDL_CreateWindow(title, x, y, width, height, flags);
		if (window)
			std::cout << "Window created" << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			std::cout << "Renderer created" << std::endl;
		}

		isGameRunning = true;
	}
	else
	{
		std::cout << "Error in initialization." << std::endl;
		isGameRunning = false;
	}
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isGameRunning = false;
		break;

	default:
		break;
	}
}

void Game::update()
{
}

void Game::render()
{
	SDL_RenderClear(renderer);

	// Add graphics to render...

	// End of graphics to render...

	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Game cleared." << std::endl;
}
