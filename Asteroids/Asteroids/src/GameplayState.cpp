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

			/*case SDLK_a:
				//m_Player->
				break;

			case SDLK_d:
				//m_Player->
				break;*/

		case SDLK_w:
			//m_Player.GoForward();
			break;

		default:
			break;
		}
	}
}

void GameplayState::Update(float dt)
{
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
