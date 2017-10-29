#pragma once

#include "GameState.h"
#include "Player.h"
#include "KeyState.h"

class GameplayState : public GameState
{
public:
	GameplayState();
	~GameplayState();

	void Init(GameEngine* gameEngine, SDL_Renderer* renderer);
	void CleanUp();

	void Pause();
	void Resume();

	void InputEvent(int mod, int state, int key);
	void Update(float dt);
	void Render();

private:
	Player m_Player;

	KeyState m_InputKeyState;
};
