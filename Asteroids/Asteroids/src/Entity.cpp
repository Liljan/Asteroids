#include "Entity.h"

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

