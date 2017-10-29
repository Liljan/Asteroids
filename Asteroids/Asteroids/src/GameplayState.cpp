#include "GameplayState.h"

GameplayState::GameplayState()
{
	//m_Player = new Player();
	m_Player.Init(&Vec2(300, 300));
}

GameplayState::~GameplayState()
{
	//delete m_Player;
}

void GameplayState::Init(GameEngine * gameEngine, SDL_Renderer * renderer)
{
	m_GameEngine = gameEngine;
	m_Renderer = renderer;

	m_InputKeyState = { false, false,false };

}

void GameplayState::CleanUp()
{
}

void GameplayState::Pause()
{
}

void GameplayState::Resume()
{
}

void GameplayState::InputEvent(int mod, int state, int key)
{
	if (state == SDL_KEYDOWN)
	{
		switch (key)
		{
		case SDLK_ESCAPE:
			m_GameEngine->SetState(State::INTRO);
			break;

		case SDLK_SPACE:
			m_GameEngine->SetState(State::HIGHSCORE);
			break;

		case SDLK_a:
			m_InputKeyState.left = true;
			break;

		case SDLK_d:
			m_InputKeyState.right = true;
			break;

		case SDLK_w:
			m_InputKeyState.up = true;
			break;

		default:
			break;
		}
	}
	else if (state == SDL_KEYUP)
	{
		switch (key)
		{
		case SDLK_a:
			m_InputKeyState.left = false;
			break;

		case SDLK_d:
			m_InputKeyState.right = false;
			break;

		case SDLK_w:
			m_InputKeyState.up = false;
			break;
		}
	}

}

void GameplayState::Update(float dt)
{
	m_Player.PreMove(dt, &m_InputKeyState);
	m_Player.Move(dt);
}

void GameplayState::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(m_Renderer);

	// Add graphics to render...
	m_Player.Draw(m_Renderer);

	// End of graphics to render...

	SDL_RenderPresent(m_Renderer);
}
