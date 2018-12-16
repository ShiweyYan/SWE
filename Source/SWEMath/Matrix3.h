#pragma once
#include"SWEMath.h"

namespace SWE
{
	class SWEMATH_API Matrix3
	{
	public:
		//––”≈œ»¥Ê¥¢
		union 
		{
			float m[9];
			float M[3][3];
			struct  
			{
				float _00; float _01; float _02;
				float _10; float _11; float _12;
				float _20; float _21; float _22;
			};
		};
	public:
		Matrix3() = default;
		Matrix3(float r00, float r01, float r02,
			float r10, float r11, float r12,
			float r20, float r21, float r22);
		~Matrix3() = default;

		inline void SetR0(const float& r00, const float& r01, const float& r02){ _00 = r00; _01 = r01; _02 = r02; }
		inline void SetR1(const float& r10, const float& r11, const float& r12) { _10 = r10; _11 = r11; _12 = r12; }
		inline void SetR2(const float& r20, const float& r21, const float& r22) { _20 = r20; _21 = r21; _22 = r22; }

		void Transpose();
		void Invert();
		Matrix3 GetTransposeMatrix3();
		Matrix3 GetInvertMatrix3();
		float Determinant();

		void MakeRotationX(float theta);
		void MakeRotationY(float theta);
		void MakeRotationZ(float theta);

		Matrix3 operator *(const Matrix3& matrix)const;
	};
}