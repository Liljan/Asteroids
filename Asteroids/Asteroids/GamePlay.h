#pragma once

#include "GameState.h"

class Gameplay : public GameState
{
public:
	Gameplay();
	~Gameplay();

	void Init(GameEngine* gameEngine, SDL_Renderer* renderer);
	void CleanUp();

	void Pause();
	void Resume();

	void InputEvent(int mod, int state, int key);
	void Update(float dt);
	void Render();
};
