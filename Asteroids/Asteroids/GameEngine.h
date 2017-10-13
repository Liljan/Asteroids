#pragma once

#include "SDL.h"
#include "Entity.h"
#include <iostream>
#include <vector>

enum class State
{
	INTRO,
	GAME,
	HI_SCORE
};

class GameState;
class Intro;
class Gameplay;
class HighScore;

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
	Intro* m_IntroState;
	GameState* m_GameplayState;
	GameState* m_HighScoreState;

	GameState* m_currentState;
};
