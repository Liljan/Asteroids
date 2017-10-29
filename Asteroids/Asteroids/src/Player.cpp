#include "Player.h"

// ---------- Player specific methods---------- //

/* Constructor
***************************************************/
Player::Player(Vec2* pos)
{
	m_Position = *pos;
	m_Velocity = Vec2::Zero();
	m_Acceleration = Vec2::Zero();

	m_Angle = 0.0f;
}

void Player::Init(Vec2* pos)
{
	// setup graphics
	m_Points[0] = { -50.0f, 50.0f };
	m_Points[1] = { 50.0f, 50.0f };
	m_Points[2] = { 0.0f, -50.0f };

	m_Position = *pos;
	m_Velocity = Vec2::Zero();
	m_Acceleration = Vec2::Zero();

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