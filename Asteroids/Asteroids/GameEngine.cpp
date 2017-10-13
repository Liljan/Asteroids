#include "GameEngine.h"

#include "Intro.h"

GameEngine::GameEngine()
{
	m_IntroState = new Intro();
	m_IntroState->Init(this, m_Renderer);

	m_currentState = m_IntroState;
}


GameEngine::~GameEngine()
{
	delete m_IntroState;
}

void GameEngine::Init(const char * title, int x, int y, int width, int height, bool fullScreen)
{
	int flags = 0;

	if (fullScreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "All subsystems initialized..." << std::endl;

		m_Window = SDL_CreateWindow(title, x, y, width, height, flags);
		if (m_Window)
			std::cout << "Window created" << std::endl;

		m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
		if (m_Renderer)
		{
			SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
			std::cout << "Renderer created" << std::endl;
		}

		// Init Game States

		SetRunning(true);
	}
	else
	{
		std::cout << "Error in initialization." << std::endl;
		Quit();
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

	case SDL_KEYDOWN:
		m_currentState->InputEvent(event.key.keysym.mod, SDL_KEYDOWN, event.key.keysym.sym);
		break;

	case SDL_KEYUP:
		m_currentState->InputEvent(event.key.keysym.mod, SDL_KEYUP, event.key.keysym.sym);
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
	SDL_SetRenderDrawColor(m_Renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(m_Renderer);

	// Add graphics to render...

	// End of graphics to render...

	SDL_RenderPresent(m_Renderer);

}

void GameEngine::SetState(State gameState)
{
	switch (gameState)
	{
	case State::INTRO:
		break;
	case State::GAME:
		break;
	case State::HI_SCORE:
		break;
	default:
		break;
	}
}

void GameEngine::Clean()
{
	SDL_DestroyWindow(m_Window);
	SDL_DestroyRenderer(m_Renderer);
	SDL_Quit();

	std::cout << "GameEngine cleared." << std::endl;
}
