#include <Vec2.h>

Vec2 & Vec2::operator+(const Vec2 & v)
{
	x += v.x;
	y += v.y;
	return *this;
}

Vec2 & Vec2::operator+(const float f)
{
	x += f;
	y += f;
	return *this;
};

Vec2 & Vec2::operator+=(const Vec2 & v)
{
	x += v.x;
	y += v.y;
	return *this;
}
Vec2 & Vec2::operator-(const float f)
{
	x -= f;
	y -= f;
	return *this;
}
Vec2 & Vec2::operator-=(const Vec2 & v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}
Vec2 & Vec2::operator*(const Mat3x3 & m)
{
	Vec2 out;

	/*11 12 13	x
	21 22 23	y
	31 32 33	0 */

	out.x = x*m.m_11 + y*m.m_12;
	out.y = x*m.m_21 + y*m.m_22;

	return out;
}
const Vec2 & Vec2::operator=(const Vec2 & v)
{
	x = v.x;
	y = v.y;
	return *this;
}
inline Vec2 & Vec2::Rotate(const Vec2 & in, float angle)
{
	Vec2 out;
	out.x = cos(angle) * in.x - SDL_sin(angle) * in.y;
	out.y = sin(angle) * in.x + SDL_cos(angle) * in.y;

	return out;
}

inline Vec2 & Vec2::Scale(const Vec2 & in, float scale)
{
	Vec2 out;
	out.x *= scale;
	out.y *= scale;

	return out;
}

//* Matrix *//

Mat3x3::Mat3x3()
{
	m_11 = 1.0f;
	m_12 = 0.0f;
	m_13 = 0.0f;

	m_21 = 0.0f;
	m_22 = 1.0f;
	m_23 = 0.0f;

	m_31 = 0.0f;
	m_32 = 0.0f;
	m_33 = 1.0f;
}

Mat3x3::Mat3x3(float f11, float f12, float f21, float f22)
{
	m_11 = f11;
	m_12 = f12;
	m_13 = 0.0f;

	m_21 = f21;
	m_22 = f22;
	m_23 = 0.0f;

	m_31 = 0.0f;
	m_32 = 0.0f;
	m_33 = 1.0f;
}


Mat3x3 & Mat3x3::operator*(const Mat3x3 & m)
{
	Mat3x3 out;

	/*11 12 13	m11 m12 m13
	21 22 23	m21 m22 m23
	31 32 33	m31 m32 m33 */

	out.m_11 = m_11*m.m_11 + m_12*m.m_21 + m_13*m.m_31;
	out.m_12 = m_11*m.m_12 + m_12*m.m_22 + m_13*m.m_32;
	out.m_13 = m_11*m.m_13 + m_12*m.m_23 + m_13*m.m_33;

	out.m_21 = m_21*m.m_11 + m_22*m.m_21 + m_23*m.m_31;
	out.m_22 = m_21*m.m_12 + m_22*m.m_22 + m_23*m.m_32;
	out.m_23 = m_21*m.m_13 + m_22*m.m_23 + m_23*m.m_33;

	out.m_31 = m_31*m.m_11 + m_32*m.m_21 + m_33*m.m_31;
	out.m_32 = m_31*m.m_12 + m_32*m.m_22 + m_33*m.m_32;
	out.m_33 = m_31*m.m_13 + m_32*m.m_23 + m_33*m.m_33;

	return out;
}

Mat3x3 & Mat3x3::operator*(const float & f)
{
	m_11 *= f;
	m_12 *= f;
	m_13 *= f;

	m_21 *= f;
	m_22 *= f;
	m_23 *= f;

	m_31 *= f;
	m_32 *= f;
	m_33 *= f;

	return *this;
}

Vec2 & Mat3x3::operator*(const Vec2 & v)
{
	Vec2 out;

	/*11 12 13	x
	21 22 23	y
	31 32 33	1 */

	out.x = v.x*m_11 + v.y*m_12 + m_13;
	out.y = v.x*m_21 + v.y*m_22 + m_23;

	return out;
}

Mat3x3 & Mat3x3::operator+(const Vec2 & v)
{
	m_13 += v.x;
	m_23 += v.y;

	return *this;
}

Mat3x3 & Mat3x3::operator+=(const Vec2 & v)
{
	m_13 += v.x;
	m_23 += v.y;

	return *this;
}

Mat3x3 & Mat3x3::operator-(const Vec2 & v)
{
	m_13 -= v.x;
	m_23 -= v.y;

	return *this;
}

Mat3x3 & Mat3x3::operator-=(const Vec2 & v)
{
	m_13 -= v.x;
	m_23 -= v.y;

	return *this;
}

const Mat3x3 & Mat3x3::operator=(const Mat3x3 & m)
{
	m_11 = m.m_11;
	m_12 = m.m_12;
	m_13 = m.m_13;

	m_21 = m.m_21;
	m_22 = m.m_22;
	m_23 = m.m_23;

	m_31 = m.m_31;
	m_32 = m.m_32;
	m_33 = m.m_33;

	return *this;
}

Mat3x3 & Mat3x3::Unit()
{
	return Mat3x3();
}

Mat3x3 & Mat3x3::Rotation(float angle)
{
	Mat3x3 out;

	/*c -s 00	m11 m12 m13
	s  c  00	m21 m22 m23
	00 00 01	m31 m32 m33 */

	float s = SDL_sin(angle);
	float c = SDL_cos(angle);

	out.m_11 = c;
	out.m_12 = -s;
	out.m_13 = 0.0f;

	out.m_21 = s;
	out.m_22 = c;
	out.m_23 = 0.0f;

	out.m_31 = 0.0f;
	out.m_32 = 0.0f;
	out.m_33 = 1.0f;

	return out;
}

Mat3x3 & Mat3x3::Scaling(float sx, float sy)
{
	Mat3x3 out;

	/*sx 00 00	m11 m12 m13
	00 sy 00	m21 m22 m23
	00 00 01	m31 m32 m33 */

	out.m_11 = sx;
	out.m_12 = 0.0f;
	out.m_13 = 0.0f;

	out.m_21 = 0.0f;
	out.m_22 = sy;
	out.m_23 = 0.0f;

	out.m_31 = 0.0f;
	out.m_32 = 0.0f;
	out.m_33 = 1.0f;

	return out;
}

Mat3x3 & Mat3x3::Translation(float x, float y)
{
	Mat3x3 out;

	/*00 00 tx	m11 m12 m13
	00 sy ty	m21 m22 m23
	00 00 01	m31 m32 m33 */

	out.m_11 = 1.0f;
	out.m_12 = 0.0f;
	out.m_13 = x;

	out.m_21 = 0.0f;
	out.m_22 = 1.0f;
	out.m_23 = y;

	out.m_31 = 0.0f;
	out.m_32 = 0.0f;
	out.m_33 = 1.0f;

	return out;
}
