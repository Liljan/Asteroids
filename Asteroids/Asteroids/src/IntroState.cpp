#include "IntroState.h"

IntroState::IntroState()
{
}


IntroState::~IntroState()
{
}

void IntroState::Init(GameEngine * gameEngine, SDL_Renderer * renderer)
{
	m_GameEngine = gameEngine;
	m_Renderer = renderer;
}

void IntroState::CleanUp()
{
}

void IntroState::Pause()
{
}

void IntroState::Resume()
{
}

void IntroState::InputEvent(int mod, int state, int key)
{
	if (state == SDL_KEYDOWN)
	{
		switch (key)
		{
		case SDLK_ESCAPE:
			m_GameEngine->SetState(State::GAMEPLAY);
			break;

		default:
			break;
		}
	}
}

void IntroState::Update(float dt)
{
}

void IntroState::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(m_Renderer);

	// Add graphics to render...

	// End of graphics to render...

	SDL_RenderPresent(m_Renderer);
}
