#pragma once

#include "SDL.h"

class Vec2
{
public:
	Vec2() { x = 0; y = 0; };
	Vec2(float x, float y) { this->x = x; this->y = y; }
	~Vec2() {};

	Vec2& operator+(const Vec2 & v);
	Vec2& operator+(const float f);
	Vec2& operator+=(const Vec2 & v);
	Vec2& operator-(const float f);
	Vec2& operator-=(const Vec2 & v);

	Vec2& operator*=(const float & f);
	Vec2& operator*(const float & f);
	
	const Vec2& operator=(const Vec2 & v);

	static Vec2& Rotate(const Vec2& in, float angle);
	static Vec2& Scale(const Vec2& in, float scale);
	static Vec2& Zero();

	float x, y;
};

