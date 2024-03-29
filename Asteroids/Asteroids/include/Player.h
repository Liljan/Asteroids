#pragma once

#include "Entity.h"
#include "KeyState.h"

class Player : public Entity
{
public:
	Player() = default;
	Player(Vector2* pos);
	Player(Player&) = default;
	Player& operator=(Player&) = default;
	~Player() {};

	void Init(Vector2* pos);
	void PreMove(float dt, KeyState* keyState);
	void Move(float dt);
	void PostMove();
	void Draw(SDL_Renderer* renderer);

private:

	// Graphics
	SDL_Color m_Color = { 0,255,0,255 };
	Vector2 m_Points[3];
};
