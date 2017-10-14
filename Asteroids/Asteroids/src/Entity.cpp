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
	_position = glm::vec2(x, y);
}

// ---------- Player specific methods---------- //

/* Constructor
***************************************************/
Player::Player(float x, float y, float speed)
{
	// Set up position properties
	_position = glm::vec2(x, y);
}

void Player::Init(float x, float y, float maxSpeed)
{
	// setup graphics
	m_Points[0] = glm::vec2(-scale, scale);
	m_Points[1] = glm::vec2(scale, scale);
	m_Points[2] = glm::vec2(0, -scale);

	SetPosition(x, y);
}

/* Movement
***************************************************/
void Player::Move(float dt)
{
	
}

void Player::Draw(SDL_Renderer * renderer)
{
	//float scaleFactor = 10.0f;
	SDL_SetRenderDrawColor(renderer, m_color.r, m_color.g, m_color.b, m_color.a);

	SDL_RenderDrawLine(renderer,
		_position.x + m_Points[0].x, _position.y + m_Points[0].y,
		_position.x + m_Points[1].x, _position.y + m_Points[1].y);

	SDL_RenderDrawLine(renderer,
		_position.x + m_Points[1].x, _position.y + m_Points[1].y,
		_position.x + m_Points[2].x, _position.y + m_Points[2].y);

	SDL_RenderDrawLine(renderer,
		_position.x + m_Points[2].x, _position.y + m_Points[2].y,
		_position.x + m_Points[0].x, _position.y + m_Points[0].y);
}
