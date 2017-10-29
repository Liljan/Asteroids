#pragma once

#include "SDL.h"
#include "Vec2.h"

class Entity {
public:
	Entity();
	virtual ~Entity();

	void SetPosition(Vec2* p) { m_Position = *p; }
	void SetRotation(float r) { m_Angle = r; }

	virtual void Move(float dt) = 0;
	virtual void Draw(SDL_Renderer* renderer) = 0;

protected:
	Vec2 m_Position;
	Vec2 m_Velocity;

	float m_Angle;
};
