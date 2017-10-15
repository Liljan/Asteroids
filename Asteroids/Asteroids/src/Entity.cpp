#include "Entity.h"

// ---------- Entity base class ---------- //

/* Default destructor
***************************************************/
Entity::Entity()
{
}
Entity::~Entity() { }

void Entity::SetPosition(Vec2 * p)
{
	m_Position = *p;
}

// ---------- Player specific methods---------- //

/* Constructor
***************************************************/
Player::Player(float x, float y, float speed)
{
	// Set up position properties
	m_Position = { x,y };
	m_Angle = 0.0f;
}

void Player::Init(float x, float y, float maxSpeed)
{
	// setup graphics
	m_Points[0] = { -m_Scale, m_Scale };
	m_Points[1] = { m_Scale, m_Scale };
	m_Points[2] = { 0, -m_Scale };

	m_Position = { x,y };

	m_Angle = 0.0f;
}

/* Movement
***************************************************/
void Player::Move(float dt)
{
	m_Angle += dt;
	//_position.x += 80.0f * dt;
	//m_Rotation = Rotate(&m_Position, m_Angle);
	//m_WorldCoordinates = m_Rotation + m_Position;
}

void Player::Draw(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, m_Color.a);

	// Test
	Vec2 p0, p1, p2;

	p0 = Vec2::Rotate(m_Points[0], m_Angle) + m_Position;
	p1 = Vec2::Rotate(m_Points[1], m_Angle) + m_Position;
	p2 = Vec2::Rotate(m_Points[2], m_Angle) + m_Position;

	SDL_RenderDrawLine(renderer, p0.x, p0.y, p1.x, p1.y);
	SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
	SDL_RenderDrawLine(renderer, p2.x, p2.y, p0.x, p0.y);
}
