#include "Player.h"

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
	m_Points[0] = { -1.0f, 1.0f };
	m_Points[1] = { 1.0f, 0.0f };
	m_Points[2] = { -1.0f, -1.0f };

	m_Scaling = Mat3x3::Scaling(m_Length, m_Length);

	m_Position = { x,y };
	m_Translation = Mat3x3::Translation(m_Position.x, m_Position.y);

	m_Angle = 0.0f;
	m_Rotation = Mat3x3::Rotation(m_Angle);

	m_CurrentAcceleration = 0.0f;
}


/* Movement
***************************************************/
void Player::Move(float dt)
{

	//_position.x += 80.0f * dt;
	//m_Rotation = Rotate(&m_Position, m_Angle);
	//m_WorldCoordinates = m_Rotation + m_Position;

	float dx = SDL_cos(m_Angle) * 0.5f * m_CurrentAcceleration * dt*dt;
	float dy = SDL_sin(m_Angle) * 0.5f * m_CurrentAcceleration * dt*dt;

	m_Position.x += dx;
	m_Position.y += dy;

	m_CurrentAcceleration *= m_Slowdown;

	//m_Rotation = Mat3x3::Rotation(m_Angle);
	m_Translation = Mat3x3::Translation(m_Position.x, m_Position.y);
}


void Player::Draw(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, m_Color.a);

	Vec2 p0, p1, p2;

	Mat3x3 scalingRotation = m_Rotation*m_Scaling;
	Mat3x3 transform = m_Translation * scalingRotation;

	p0 = transform*m_Points[0];
	p1 = transform*m_Points[1];
	p2 = transform*m_Points[2];

	SDL_RenderDrawLine(renderer, p0.x, p0.y, p1.x, p1.y);
	SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
	SDL_RenderDrawLine(renderer, p2.x, p2.y, p0.x, p0.y);
}

void Player::Turn(float dt, Direction dir)
{
	if (dir == Direction::LEFT)
		m_Angle += m_turnSpeed * dt;
	else if (dir == Direction::RIGHT)
		m_Angle -= m_turnSpeed * dt;
}

void Player::Accelerate()
{
	m_CurrentAcceleration = 12000.0f;
	float f = 321;
}
