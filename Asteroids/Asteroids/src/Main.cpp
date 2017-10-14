#include "SDL.h"
#include "GameEngine.h"

namespace SETTINGS {
	const unsigned int TARGET_FPS = 60;
	const unsigned int WIDTH = 1280, HEIGHT = 720;
	const bool FULLSCREEN_ENABLED = false;
}

const int TARGET_FPS = 60;

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int currentFrameTime, lastFrameTime = 0;
	float dt;

	const int FPS_MS = 1000 / SETTINGS::TARGET_FPS;

	GameEngine* gameEngine = nullptr;

	gameEngine = new GameEngine();
	gameEngine->Init("Assdroids", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SETTINGS::WIDTH, SETTINGS::HEIGHT, SETTINGS::FULLSCREEN_ENABLED);

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