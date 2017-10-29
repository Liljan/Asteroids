#pragma once

#include "SDL.h"

class Vec2
{
public:
	Vec2() { x = 0; y = 0; };
	Vec2(float x, float y) { this->x = x; this->y = y; }
	~Vec2() {};

	Vec2& operator+(const Vec2 & v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	Vec2& operator+(const float f)
	{
		x += f;
		y += f;
		return *this;
	};

	Vec2& operator+=(const Vec2& v)
	{
		x += v.x;
		y += v.y;
		return *this;
	};

	Vec2& operator-(const float f)
	{
		x -= f;
		y -= f;
		return *this;
	};

	Vec2& operator-=(const Vec2& v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	};

	const Vec2& operator=(const Vec2 & v)
	{
		x = v.x;
		y = v.y;
		return *this;
	};

	static Vec2& Rotate(const Vec2& in, float angle)
	{
		Vec2 out;
		out.x = cos(angle) * in.x - SDL_sin(angle) * in.y;
		out.y = sin(angle) * in.x + SDL_cos(angle) * in.y;

		return out;
	}

	static Vec2& Scale(const Vec2& in, float scale)
	{
		Vec2 out;
		out.x *= scale;
		out.y *= scale;

		return out;
	}

	static Vec2& Zero()
	{
		Vec2 out;
		out.x = 0.0f;
		out.y = 0.0f;

		return out;
	}

	float x, y;
};

