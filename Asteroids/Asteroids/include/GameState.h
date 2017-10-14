#pragma once

#include "GameEngine.h"

class GameState
{
public:
	virtual void Init(GameEngine* gameEngine, SDL_Renderer* renderer) = 0;
	virtual void CleanUp() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void InputEvent(int mod, int state, int key) = 0;
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;

	virtual void ChangeState(GameEngine* gameEngine, State gameState)
	{
		gameEngine->SetState(gameState);
	}

protected:
	GameState() {};

	// For state change
	GameEngine* m_GameEngine;

	// For rendering
	SDL_Renderer* m_Renderer;
};

