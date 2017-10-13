#include "Intro.h"

Intro::Intro()
{
}


Intro::~Intro()
{
}

void Intro::Init(GameEngine * gameEngine, SDL_Renderer * renderer)
{
	_gameEngine = gameEngine;
	_renderer = renderer;
}

void Intro::CleanUp()
{
}

void Intro::Pause()
{
}

void Intro::Resume()
{
}

void Intro::InputEvent(int mod, int state, int key)
{
	if (state == SDL_KEYDOWN)
	{
		switch (key)
		{
		case SDLK_ESCAPE:
			_gameEngine->Quit();
			break;

		default:
			break;
		}
	}
}

void Intro::Update(float dt)
{
}

void Intro::Render()
{
}
