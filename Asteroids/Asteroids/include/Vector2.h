#pragma once

struct Vector2
{
	float x, y;

	Vector2 & operator+(const Vector2 & v) {
		x += v.x;
		y += v.y;

		return *this;
	}

	static Vector2 & Rotate(const Vector2 & in, float angle)
	{
		Vector2 out;
		out.x = cos(angle) * in.x - SDL_sin(angle) * in.y;
		out.y = sin(angle) * in.x + SDL_cos(angle) * in.y;

		return out;
	}

};