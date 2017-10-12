#pragma once

#include "SDL.h"

class Entity {
public:
	Entity();
	virtual ~Entity();

	float GetX() { return m_X; }
	float GetY() { return m_Y; }

	void SetPosition(float x, float y);

	virtual void Move(float dt) = 0;
	virtual void Draw(SDL_Renderer* renderer) = 0;

protected:
	float m_X, m_Y;
};

class Player : public Entity
{
public:
	Player(float x, float y, float speed);
	~Player() {};

	float GetVx() { return m_Vx; }
	void Move(float dt);
	void Draw(SDL_Renderer* renderer);

private:
	float m_Speed;
	float m_Vx, m_Vy;

	// Graphics
	SDL_Color _color = { 0,255,0,255 };
	float sc = 15.0f;
};