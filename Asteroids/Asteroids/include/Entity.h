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

	Mat3x3 m_Scaling, m_Rotation, m_Translation;
};
