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
	m_X = x;
	m_Y = y;
}

// ---------- Player specific methods---------- //

/* Constructor
***************************************************/
Player::Player(float x, float y, float speed)
{
	// Set up position properties
	m_X = x;
	m_Y = y;

	// Set up movement properties;
	m_Vx = 0.0f;
	m_Speed = speed;
}

/* Movement
***************************************************/
void Player::Move(float dt)
{
	m_X += m_Vx * dt;
}

void Player::Draw(SDL_Renderer * renderer)
{
	//float scaleFactor = 10.0f;
	SDL_SetRenderDrawColor(renderer, _color.r, _color.g, _color.b, _color.a);

	//SDL_RenderDrawLine(renderer, 0, 0, tics, tics);
}
