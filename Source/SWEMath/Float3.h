#pragma once

#include "../SWEMath/SWEMath.h"

namespace SWE
{
	class SWEMATH_API Float3
	{
	public:
		union
		{
			float v[3];
			struct
			{
				float x, y, z;
			};
		};

		Float3(void);
		Float3(const float& x, const float& y, const float& z);
		~Float3() = default;

		inline void Set(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }

		float Length();
		void Normalize();

		Float3& operator += (const Float3 &v);
		Float3& operator -= (const Float3 &v);

		Float3 operator + (const Float3 &v)const;
		Float3 operator - (const Float3 &v)const;

		Float3& operator *= (float f);
		Float3& operator /= (float f);
		Float3& operator += (float f);
		Float3& operator -= (float f);
		Float3 operator * (float f)const;
		Float3 operator / (float f)const;
		Float3 operator + (float f)const;
		Float3 operator - (float f)const;

		float Dot(const Float3 &v)const;
		Float3 Cross(const Float3 &v)const;
		bool operator ==(const Float3 &v)const;
	};
}