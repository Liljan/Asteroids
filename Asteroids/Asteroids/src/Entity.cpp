#include "Entity.h"

#include "gtx\transform.hpp"

// ---------- Entity base class ---------- //

/* Default destructor
***************************************************/
Entity::Entity()
{
}
Entity::~Entity() { }

/* Position setter which also updates hitbox
***************************************************/
void Entity::SetPosition(float x, float y)
{
	_position = glm::vec3(x, y, 0);
}

// ---------- Player specific methods---------- //

/* Constructor
***************************************************/
Player::Player(float x, float y, float speed)
{
	// Set up position properties
	_position = glm::vec3(x, y, 0);
	angle = 0.0f;
}

void Player::Init(float x, float y, float maxSpeed)
{
	// setup graphics
	m_Points[0] = glm::vec4(-scale, scale, 0, 1);
	m_Points[1] = glm::vec4(scale, scale, 0, 1);
	m_Points[2] = glm::vec4(0, -scale, 0, 1);

	SetPosition(x, y);

	angle = 0.0f;
}

/* Movement
***************************************************/
void Player::Move(float dt)
{
	angle += dt;
	//_position.x += 80.0f * dt;
}

void Player::Draw(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, m_color.r, m_color.g, m_color.b, m_color.a);

	transform_matrix = glm::mat4();
	rot_matrix = glm::rotate(angle, glm::vec3(0, 0, 1));
	pos_matrix = glm::translate(_position);

	transform_matrix *= pos_matrix * rot_matrix;

	glm::vec4 p0 = transform_matrix * m_Points[0];
	glm::vec4 p1 = transform_matrix * m_Points[1];
	glm::vec4 p2 = transform_matrix * m_Points[2];

	SDL_RenderDrawLine(renderer, p0.x, p0.y, p1.x, p1.y);
	SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
	SDL_RenderDrawLine(renderer, p2.x, p2.y, p0.x, p0.y);
}
