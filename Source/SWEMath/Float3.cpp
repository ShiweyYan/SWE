#include "Float3.h"
#include <math.h>
#include <assert.h>

using namespace SWE;

SWE::Float3::Float3(void):
x(0),
y(0),
z(0)
{
}

float SWE::Float3::Length()
{
	return sqrtf(x * x + y * y + z * z);
}

void SWE::Float3::Normalize()
{
	float length = Length();
	assert(length);
	x = x / length;
	y = y / length;
	z = z / length;
}

SWE::Float3 SWE::Float3::operator+(const Float3 &v) const
{
	Float3 result(x + v.x, y + v.y, z + v.z);

	return result;
}

SWE::Float3 SWE::Float3::operator-(const Float3 &v) const
{
	Float3 result(x - v.x, y - v.y, z - v.z);

	return result;
}

SWE::Float3 SWE::Float3::operator*(float f) const
{
	Float3 result(x * f, y * f, z * f);

	return result;
}

SWE::Float3 SWE::Float3::operator/(float f) const
{
	assert(f);
	Float3 result(x / f, y / f, z / f);

	return result;
}

SWE::Float3 SWE::Float3::operator+(float f) const
{
	Float3 result(x + f, y + f, z + f);

	return result;
}

SWE::Float3 SWE::Float3::operator-(float f) const
{
	Float3 result(x - f, y - f, z - f);

	return result;
}

float SWE::Float3::Dot(const Float3 &v) const
{
	return (v.x*x + v.y*y + v.z*z);
}

SWE::Float3 SWE::Float3::Cross(const Float3 &v) const
{
	Float3 result;
	result.x = y * v.z - z * v.y;
	result.y = z * v.x - x * v.z;
	result.z = x * v.y - y * v.x;

	return result;
}

bool SWE::Float3::operator==(const Float3 &v) const
{
	for (unsigned int i = 0; i < 3; i++)
	{
		if (fabs(this->v[i] - v.v[i]) > EPSILON_E4)
		{
			return false;
		}
	}
	return true;
}

SWE::Float3& SWE::Float3::operator-=(float f)
{
		x -= f;
		y -= f;
		z -= f;
		return *this;
}

SWE::Float3& SWE::Float3::operator+=(float f)
{
	x += f;
	y += f;
	z += f;
	return *this;
}

SWE::Float3& SWE::Float3::operator/=(float f)
{
	assert(f);
	x /= f;
	y /= f;
	z /= f;
	return *this;
}

SWE::Float3& SWE::Float3::operator*=(float f)
{
	x *= f;
	y *= f;
	z *= f;
	return *this;
}

Float3& SWE::Float3::operator-=(const Float3 &v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Float3& SWE::Float3::operator+=(const Float3 &v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

SWE::Float3::Float3(const float& x, const float& y, const float& z):
	x(x),
	y(y),
	z(z)
{
}
