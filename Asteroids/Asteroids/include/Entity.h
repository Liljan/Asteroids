#pragma once

#include "SDL.h"
#include "Vector2.h"

class Entity {
public:
	Entity();
	virtual ~Entity();

	void SetPosition(Vector2* p) { m_Position = *p; }
	void SetRotation(float r) { m_Angle = r; }

	virtual void Move(float dt) = 0;
	virtual void Draw(SDL_Renderer* renderer) = 0;

protected:
	Vector2 m_Position;
	Vector2 m_Velocity;

	float m_Angle;
};
