#include "SDL.h"
#include "GameEngine.h"

GameEngine* gameEngine = nullptr;

const int TARGET_FPS = 60;

int main(int argc, char* argv[])
{
	int currentFrameTime, lastFrameTime = 0;
	float dt;

	const int FPS_MS = 1000 / TARGET_FPS;

	gameEngine = new GameEngine();
	gameEngine->Init("Assdroids", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

	while (gameEngine->IsRunning())
	{
		currentFrameTime = SDL_GetTicks();
		dt = (currentFrameTime - lastFrameTime) * 0.001f;

		gameEngine->HandleEvents();
		gameEngine->Update(dt);
		gameEngine->Render();

		SDL_Delay(FPS_MS);

		lastFrameTime = SDL_GetTicks();
	}

	gameEngine->Clean();
	delete gameEngine;

	return 0;
}