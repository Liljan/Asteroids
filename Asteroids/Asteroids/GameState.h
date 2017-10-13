#pragma once

#include "GameEngine.h"

class GameState
{
public:
	virtual void Init() = 0;
	virtual void CleanUp() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void InputEvent(int mod, int state, int key);
	virtual void Update(float dt);
	virtual void Render() = 0;

	virtual void ChangeState(GameEngine* gameEngine, GameState* state)
	{
		gameEngine->
	}

protected:
	GameState() {};

	// For state change
	GameEngine _gameEngine;

	// For rendering
	SDL_Renderer* _renderer;
};

