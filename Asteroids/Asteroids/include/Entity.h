#pragma once

#include "SDL.h"

#include "glm.hpp"

class Entity {
public:
	Entity();
	virtual ~Entity();

	void SetPosition(float x, float y);

	virtual void Move(float dt) = 0;
	virtual void Draw(SDL_Renderer* renderer) = 0;

protected:
	glm::vec3 _position;
};

class Player : public Entity
{
public:
	Player() {};
	Player(float x, float y, float speed);
	~Player() {};

	void Init(float x, float y, float maxSpeed);

	void Move(float dt);
	void Draw(SDL_Renderer* renderer);

private:
	glm::vec2 _velocity;
	float angle = 0.0f;

	// Transform: position, rotation
	glm::mat4 pos_matrix, rot_matrix, transform_matrix;

	// Graphics
	SDL_Color m_color = { 0,255,0,255 };
	glm::vec4 m_Points[3];
	float scale = 50.0f;
};