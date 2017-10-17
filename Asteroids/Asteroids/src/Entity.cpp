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
	m_Points[0] = { -1.0f, 1.0f };
	m_Points[1] = { 1.0f, 1.0f };
	m_Points[2] = { 0.0f, -1.0f };

	m_Scaling = Mat3x3::Scaling(m_Length, m_Length);

	m_Position = { x,y };
	m_Translation = Mat3x3::Translation(m_Position.x, m_Position.y);

	m_Angle = 0.0f;
	m_Rotation = Mat3x3::Rotation(m_Angle);
}

/* Movement
***************************************************/
void Player::Move(float dt)
{
	m_Angle += dt;

	m_Rotation = Mat3x3::Rotation(m_Angle);

	m_Translation = Mat3x3::Translation(m_Position.x, m_Position.y);

	//_position.x += 80.0f * dt;
	//m_Rotation = Rotate(&m_Position, m_Angle);
	//m_WorldCoordinates = m_Rotation + m_Position;
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
