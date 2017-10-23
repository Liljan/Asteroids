#pragma once

#include "Entity.h"

enum Direction
{
	LEFT, RIGHT
};

class Player : public Entity
{
public:
	Player() = default;
	Player(float x, float y, float speed);
	Player(Player&) = default;
	Player& operator=(Player&) = default;
	~Player() {};

	void Init(float x, float y, float maxSpeed);
	void Move(float dt);
	void Draw(SDL_Renderer* renderer);

	// Gameplay commands
	void Turn(float dt, Direction dir);
	void GoForward();
	//void Stop();

private:
	Vec2 m_Velocity;
	float m_Angle = 0.0f;

	// Gameplay
	float m_turnSpeed = 1.0f; // Rad/s

	float m_Speed;
	const float m_Slowdown = 0.99f;

	// Graphics
	SDL_Color m_Color = { 0,255,0,255 };
	Vec2 m_Points[3];
	const float m_Length = 50.0f;
};
