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

		void Transpose();
		void Invert();
		Matrix3 GetTransposeMatrix3();
		Matrix3 GetInvertMatrix3();
		float Determinant();

		void MakeRotationX(float theta);
		void MakeRotationY(float theta);
		void MakeRotationZ(float theta);
	};
}