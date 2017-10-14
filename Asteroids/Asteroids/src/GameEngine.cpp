#include "GameEngine.h"

#include "IntroState.h"
#include "GameplayState.h"
#include "HighscoreState.h"

GameEngine::GameEngine()
{
	m_IntroState = new IntroState();
	m_GameplayState = new GameplayState();
	m_HighScoreState = new HighscoreState();
}

GameEngine::~GameEngine()
{
	delete m_IntroState;
	delete m_GameplayState;
	delete m_HighScoreState;
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

		m_IntroState->Init(this, m_Renderer);
		m_GameplayState->Init(this, m_Renderer);
		m_HighScoreState->Init(this, m_Renderer);
		m_currentState = m_IntroState;

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
	m_currentState->Update(dt);
}

void GameEngine::Render()
{
	m_currentState->Render();
}

void GameEngine::SetState(State gameState)
{
	switch (gameState)
	{
	case State::INTRO:
		m_currentState = m_IntroState;
		break;
	case State::GAMEPLAY:
		m_currentState = m_GameplayState;
		break;
	case State::HIGHSCORE:
		m_currentState = m_HighScoreState;
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
