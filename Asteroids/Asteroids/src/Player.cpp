#include "Player.h"

#include <iostream>

// ---------- Player specific methods---------- //

/* Constructor
***************************************************/
Player::Player(Vec2* pos)
{
	m_Position = *pos;
	m_Velocity = Vec2::Zero();

	x = pos->x;
	y = pos->y;
	vx = 0.0f;
	vy = 0.0f;
}


void Player::Init(Vec2* pos)
{
	// setup graphics
	m_Points[0] = { -50.0f, 50.0f };
	m_Points[1] = { 50.0f, 0.0f };
	m_Points[2] = { -50.0f, -50.0f };

	m_Position = *pos;
	m_Velocity = Vec2::Zero();
	m_Acceleration = Vec2::Zero();

	m_Angle = 0.0f;

	x = pos->x;
	y = pos->y;
	vx = 0.0f;
	vy = 0.0f;
}


void Player::PreMove(float dt, KeyState * keyState)
{
	float THRUST_MAG = 1.0f;
	float FRICTION_MAG = 0.02f;

	if (keyState->left)
		m_Angle -= 6.0f * dt;
	else if (keyState->right)
		m_Angle += 6.0f * dt;

	//m_Acceleration = Vec2::Zero();

	if (keyState->up)
	{
		//m_Velocity += Vec2(SDL_cos(m_Angle), SDL_sin(m_Angle)) * THRUST_MAG;
		vx += SDL_cos(m_Angle) * THRUST_MAG;
		vy += SDL_sin(m_Angle) * THRUST_MAG;
	}
}


/* Movement
***************************************************/
void Player::Move(float dt)
{
	//m_Position += m_Velocity * dt;
	x += vx * dt;
	y += vy * dt;
}


void Player::PostMove()
{

}


void Player::Draw(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, m_Color.a);

	m_Position = Vec2(x, y);

	// Test
	Vec2 p0, p1, p2;

	p0 = Vec2::Rotate(m_Points[0], m_Angle) + m_Position;
	p1 = Vec2::Rotate(m_Points[1], m_Angle) + m_Position;
	p2 = Vec2::Rotate(m_Points[2], m_Angle) + m_Position;

	SDL_RenderDrawLine(renderer, p0.x, p0.y, p1.x, p1.y);
	SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
	SDL_RenderDrawLine(renderer, p2.x, p2.y, p0.x, p0.y);
}
