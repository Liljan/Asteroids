#pragma once

#include "SDL.h"
#include "Vec2.h"

class Entity {
public:
	Entity();
	virtual ~Entity();

	void SetPosition(Vec2* p);

	virtual void Move(float dt) = 0;
	virtual void Draw(SDL_Renderer* renderer) = 0;

protected:
	Vec2 m_Position;
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

private:
	Vec2 m_Velocity;
	float m_Angle = 0.0f;

	// Transform: position, rotation
	Vec2 m_WorldCoordinates, m_Rotation, m_Translation;

	// Graphics
	SDL_Color m_Color = { 0,255,0,255 };
	Vec2 m_Points[3];
	const float m_Scale = 50.0f;
};