#include "GamePlay.h"

Gameplay::Gameplay()
{
}


Gameplay::~Gameplay()
{
}

void Gameplay::Init(GameEngine * gameEngine, SDL_Renderer * renderer)
{
	m_GameEngine = gameEngine;
	m_Renderer = renderer;
}

void Gameplay::CleanUp()
{
}

void Gameplay::Pause()
{
}

void Gameplay::Resume()
{
}

void Gameplay::InputEvent(int mod, int state, int key)
{
	if (state == SDL_KEYDOWN)
	{
		switch (key)
		{
		case SDLK_ESCAPE:
			m_GameEngine->SetState(State::INTRO);
			break;

		default:
			break;
		}
	}
}

void Gameplay::Update(float dt)
{
}

void Gameplay::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 0x00, 255, 0x00, 0xFF);
	SDL_RenderClear(m_Renderer);

	// Add graphics to render...

	// End of graphics to render...

	SDL_RenderPresent(m_Renderer);
}
