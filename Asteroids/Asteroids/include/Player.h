#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player() = default;
	Player(Vec2* pos);
	Player(Player&) = default;
	Player& operator=(Player&) = default;
	~Player() {};

	void Init(Vec2* pos);
	void Move(float dt);
	void Draw(SDL_Renderer* renderer);

private:
	Vec2 m_Acceleration;

	// Graphics
	SDL_Color m_Color = { 0,255,0,255 };
	Vec2 m_Points[3];
};
