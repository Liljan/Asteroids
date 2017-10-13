#pragma once

#include "SDL.h"
#include "Entity.h"
#include <iostream>

class GameState;

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void Init(const char* title, int x, int y, int width, int height, bool fullScreen);
	void Clean();

	void HandleEvents();
	void Update(float dt);
	void Render();

	void SetState(GameState* state);

	void SetRunning(bool b) { m_IsRunning = b; }
	bool IsRunning() { return m_IsRunning; }

private:
	bool m_IsRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

	GameState* m_CurrentGameState;
};
