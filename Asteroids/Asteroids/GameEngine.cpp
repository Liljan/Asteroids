#include "GameEngine.h"

GameEngine::GameEngine()
{
}


GameEngine::~GameEngine()
{
}

void GameEngine::Init(const char * title, int x, int y, int width, int height, bool fullScreen)
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

		SetRunning(true);
	}
	else
	{
		std::cout << "Error in initialization." << std::endl;
		SetRunning(false);
	}
}

void GameEngine::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		SetRunning(false);
		break;

	default:
		break;
	}
}

void GameEngine::Update(float dt)
{

}

void GameEngine::Render()
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(renderer);

	// Add graphics to render...

	// End of graphics to render...

	SDL_RenderPresent(renderer);

}

void GameEngine::SetState(GameState * state)
{
	m_CurrentGameState = state;
}

void GameEngine::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Game cleared." << std::endl;
}
