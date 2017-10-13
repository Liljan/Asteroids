#include "Entity.h"

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
	m_x = x;
	m_y = y;
}

// ---------- Player specific methods---------- //

/* Constructor
***************************************************/
Player::Player(float x, float y, float speed)
{
	// Set up position properties
	m_x = x;
	m_y = y;

	// Set up movement properties;
	m_vx = 0.0f;
	m_speed = speed;
}

/* Movement
***************************************************/
void Player::Move(float dt)
{
	m_x += m_vx * dt;
}

void Player::Draw(SDL_Renderer * renderer)
{
	//float scaleFactor = 10.0f;
	SDL_SetRenderDrawColor(renderer, m_color.r, m_color.g, m_color.b, m_color.a);

	//SDL_RenderDrawLine(renderer, 0, 0, tics, tics);
}
