#pragma once

#include "SDL.h"

class Entity {
public:
	Entity();
	virtual ~Entity();

	float GetX() { return m_x; }
	float GetY() { return m_y; }

	void SetPosition(float x, float y);

	virtual void Move(float dt) = 0;
	virtual void Draw(SDL_Renderer* renderer) = 0;

protected:
	float m_x, m_y;
};

class Player : public Entity
{
public:
	Player(float x, float y, float speed);
	~Player() {};

	float GetVx() { return m_vx; }
	void Move(float dt);
	void Draw(SDL_Renderer* renderer);

private:
	float m_speed;
	float m_vx, m_vy;

	// Graphics
	SDL_Color m_color = { 0,255,0,255 };
};