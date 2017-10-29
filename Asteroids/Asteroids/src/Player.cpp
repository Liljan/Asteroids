#include "Player.h"

#include <iostream>

// ---------- Player specific methods---------- //

/* Constructor
***************************************************/
Player::Player(Vector2* pos)
{
	m_Position = *pos;
	m_Velocity = { 0.f,0.f };
}


void Player::Init(Vector2* pos)
{
	// setup graphics
	m_Points[0] = { -10.0f, 10.0f };
	m_Points[1] = { 10.0f, 0.0f };
	m_Points[2] = { -10.0f, -10.0f };

	m_Position = *pos;
	m_Velocity = { 0.0f,0.0f };

	m_Angle = 0.0f;
}


void Player::PreMove(float dt, KeyState * keyState)
{
	float THRUST_MAG = 3.0f;
	float FRICTION_MAG = 0.02f;

	if (keyState->left)
		m_Angle -= 6.0f * dt;
	else if (keyState->right)
		m_Angle += 6.0f * dt;

	//m_Acceleration = Vec2::Zero();

	if (keyState->up)
	{
		m_Velocity.x += SDL_cos(m_Angle) * THRUST_MAG;
		m_Velocity.y += SDL_sin(m_Angle) * THRUST_MAG;
	}
}


/* Movement
***************************************************/
void Player::Move(float dt)
{
	m_Position.x += m_Velocity.x * dt;
	m_Position.y += m_Velocity.y * dt;
}


void Player::PostMove()
{

}


void Player::Draw(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, m_Color.a);

	Vector2 o1 = { 0.f,0.f };
	Vector2 ooo = { 231.0f,123.f };

	// Test
	Vector2 p0, p1, p2;

	p0 = Vector2::Rotate(m_Points[0], m_Angle) + m_Position;
	p1 = Vector2::Rotate(m_Points[1], m_Angle) + m_Position;
	p2 = Vector2::Rotate(m_Points[2], m_Angle) + m_Position;

	SDL_RenderDrawLine(renderer, p0.x, p0.y, p1.x, p1.y);
	SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
	SDL_RenderDrawLine(renderer, p2.x, p2.y, p0.x, p0.y);
}
