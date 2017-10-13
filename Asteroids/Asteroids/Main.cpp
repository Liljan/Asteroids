#include "SDL.h"
#include "GameEngine.h"

GameEngine* gameEngine = nullptr;

int main(int argc, char* argv[])
{
	int currentFrameTime, lastFrameTime = 0;
	float dt;

	gameEngine = new GameEngine();
	gameEngine->Init("Assdroids", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

	while (gameEngine->IsRunning())
	{
		currentFrameTime = SDL_GetTicks();
		dt = (currentFrameTime - lastFrameTime) * 0.001f;

		gameEngine->HandleEvents();
		gameEngine->Update(dt);
		gameEngine->Render();

		lastFrameTime = SDL_GetTicks();
	}

	gameEngine->Clean();
	delete gameEngine;

	return 0;
}