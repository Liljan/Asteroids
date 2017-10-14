#pragma once

#include "SDL.h"
#include "Entity.h"
#include <iostream>
#include <vector>

enum class State
{
	INTRO,
	GAMEPLAY,
	HIGHSCORE
};

class GameState;
class IntroState;
class GameplayState;
class HighscoreState;

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

	void SetState(State gameState);

	void SetRunning(bool b) { m_IsRunning = b; }
	void Quit() { m_IsRunning = false; }
	bool IsRunning() { return m_IsRunning; }

private:
	bool m_IsRunning;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	// GameStates
	IntroState* m_IntroState;
	GameplayState* m_GameplayState;
	HighscoreState* m_HighScoreState;

	GameState* m_currentState;
};
