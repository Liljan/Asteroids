#pragma once

#include "SDL.h"

class Mat3x3;

class Vec2
{
public:
	Vec2() { x = 0.0f; y = 0.0f; }
	Vec2(float x, float y) { this->x = x; this->y = y; }
	~Vec2() {};

	Vec2& operator+(const Vec2 & v);
	Vec2& operator+(const float f);
	Vec2& operator+=(const Vec2 & v);
	Vec2& operator-(const float f);
	Vec2& operator-=(const Vec2 & v);

	Vec2& operator*(const Mat3x3 & m);
	//Vec2& operator*=(const Mat3x3 & m);

	const Vec2& operator=(const Vec2 & v);

	static inline Vec2& Rotate(const Vec2& in, float angle);

	static inline Vec2& Scale(const Vec2& in, float scale);

	float x, y;
};

class Mat3x3
{
public:
	Mat3x3();
	Mat3x3(float f11, float f12, float f21, float f22);
	~Mat3x3() = default;

	Mat3x3& operator*(const Mat3x3 & m);
	Mat3x3& operator*(const float & f);

	Mat3x3& operator+(const Vec2 & v);
	Mat3x3& operator+=(const Vec2 & v);
	Mat3x3& operator-(const Vec2 & v);
	Mat3x3& operator-=(const Vec2 & v);

	const Mat3x3& operator=(const Mat3x3 & m);

	static inline Mat3x3& Unit();
	static inline Mat3x3& Rotation(float angle);
	static inline Mat3x3& Scaling(float sx, float sy);
	static inline Mat3x3& Translation(float x, float y);

	float m_11, m_12, m_13,
		m_21, m_22, m_23,
		m_31, m_32, m_33;
};