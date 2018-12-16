#include "Matrix3.h"
#include <math.h>
#include <assert.h>
#include <xmmintrin.h>

using namespace SWE;

SWE::Matrix3::Matrix3(float r00, float r01, float r02, float r10, float r11, float r12, float r20, float r21, float r22):
	_00(r00), _01(r01), _02(r02),
	_10(r10), _11(r11), _12(r12),
	_20(r20), _21(r21), _22(r22)
{

}

void SWE::Matrix3::Transpose()
{
	float temp;

	temp = _10;
	_10 = _01;
	_01 = temp;

	temp = _20;
	_20 = _02;
	_02 = temp;

	temp = _21;
	_21 = _12;
	_12 = temp;
}

void SWE::Matrix3::Invert()
{
	float det = Determinant();

	if (fabs(det) < EPSILON_E4)
		return;

	float detInv = 1.0f / det;

	M[0][0] = detInv * (M[1][1] * M[2][2] - M[2][1] * M[1][2]);
	M[1][0] = -detInv * (M[1][0] * M[2][2] - M[2][0] * M[1][2]);
	M[2][0] = detInv * (M[1][0] * M[2][1] - M[2][0] * M[1][1]);

	M[0][1] = -detInv * (M[0][1] * M[2][2] - M[2][1] * M[0][2]);
	M[1][1] = detInv * (M[0][0] * M[2][2] - M[2][0] * M[0][2]);
	M[2][1] = -detInv * (M[0][0] * M[2][1] - M[2][0] * M[0][1]);

	M[0][2] = detInv * (M[0][1] * M[1][2] - M[1][1] * M[0][2]);
	M[1][2] = -detInv * (M[0][0] * M[1][2] - M[1][0] * M[0][2]);
	M[2][2] = detInv * (M[0][0] * M[1][1] - M[1][0] * M[0][1]);
}

SWE::Matrix3 SWE::Matrix3::GetTransposeMatrix3()
{
	Matrix3 result;

	result._00 = _00;
	result._10 = _01;
	result._20 = _02;

	result._01 = _10;
	result._11 = _11;
	result._21 = _12;

	result._02 = _20;
	result._12 = _21;
	result._22 = _22;

	return result;
}

SWE::Matrix3 SWE::Matrix3::GetInvertMatrix3()
{
	float det = Determinant();

	if (fabs(det) < EPSILON_E4)
	{
#ifdef _DEBUG
		assert(false);
#endif
		return *this;
	}

	float detInv = 1.0f / det;

	Matrix3 resutl;

	resutl.M[0][0] = detInv * (M[1][1] * M[2][2] - M[2][1] * M[1][2]);
	resutl.M[1][0] = -detInv * (M[1][0] * M[2][2] - M[2][0] * M[1][2]);
	resutl.M[2][0] = detInv * (M[1][0] * M[2][1] - M[2][0] * M[1][1]);

	resutl.M[0][1] = -detInv * (M[0][1] * M[2][2] - M[2][1] * M[0][2]);
	resutl.M[1][1] = detInv * (M[0][0] * M[2][2] - M[2][0] * M[0][2]);
	resutl.M[2][1] = -detInv * (M[0][0] * M[2][1] - M[2][0] * M[0][1]);

	resutl.M[0][2] = detInv * (M[0][1] * M[1][2] - M[1][1] * M[0][2]);
	resutl.M[1][2] = -detInv * (M[0][0] * M[1][2] - M[1][0] * M[0][2]);
	resutl.M[2][2] = detInv * (M[0][0] * M[1][1] - M[1][0] * M[0][1]);

	return resutl;
}

float SWE::Matrix3::Determinant()
{
	return (M[0][0] * (M[1][1] * M[2][2] - M[2][1] * M[1][2]) -
		M[0][1] * (M[1][0] * M[2][2] - M[2][0] * M[1][2]) +
		M[0][2] * (M[1][0] * M[2][1] - M[2][0] * M[1][1]));
}

void SWE::Matrix3::MakeRotationX(float theta)
{
	float fCos = cosf(theta);
	float fSin = sinf(theta);

	_00 = 1;	_01 = 0;		_02 = 0;
	_10 = 0;	_11 = fCos;	_12 = fSin;
	_20 = 0;	_21 = -fSin;	_22 = fCos;
}

void SWE::Matrix3::MakeRotationY(float theta)
{
	float fCos = cosf(theta);
	float fSin = sinf(theta);

	_00 = fCos;	_01 = 0;	_02 = -fSin;
	_10 = 0;		_11 = 1;	_12 = 0;
	_20 = fSin;	_21 = 0;	_22 = fCos;
}

void SWE::Matrix3::MakeRotationZ(float theta)
{
	float fCos = cosf(theta);
	float fSin = sinf(theta);

	_00 = fCos;	_01 = fSin;	 _02 = 0;
	_10 = -fSin;	_11 = fCos;	 _12 = 0;
	_20 = 0;		_21 = 0;		_22 = 1;
}

SWE::Matrix3 SWE::Matrix3::operator*(const Matrix3& matrix) const
{
	Matrix3 result;
	result.M[0][0] = 0;
	result.M[1][1] = 0;
	result.M[2][2] = 0;
#ifdef SWE_SSE
	{
		__m128 _v1 = _mm_set_ps(M[0][0], M[0][1], M[0][2], 0.0f);
		__m128 _v2 = _mm_set_ps(M[1][0], M[1][1], M[1][2], 0.0f);
		__m128 _v3 = _mm_set_ps(M[2][0], M[2][1], M[2][2], 0.0f);

		__m128 _s1 = _mm_set_ps(matrix.M[0][0], matrix.M[1][0], matrix.M[2][0], 0.0f);
		__m128 _s2 = _mm_set_ps(matrix.M[0][1], matrix.M[1][1], matrix.M[2][1], 0.0f);
		__m128 _s3 = _mm_set_ps(matrix.M[0][2], matrix.M[1][2], matrix.M[2][2], 0.0f);

		__m128 _v = _mm_mul_ps(_v1, _s1);
		result.M[0][0] = _v.m128_f32[3] + _v.m128_f32[2] + _v.m128_f32[1];
		_v = _mm_mul_ps(_v1, _s2);
		result.M[0][1] = _v.m128_f32[3] + _v.m128_f32[2] + _v.m128_f32[1];
		_v = _mm_mul_ps(_v1, _s3);
		result.M[0][2] = _v.m128_f32[3] + _v.m128_f32[2] + _v.m128_f32[1];

		_v = _mm_mul_ps(_v2, _s1);
		result.M[1][0] = _v.m128_f32[3] + _v.m128_f32[2] + _v.m128_f32[1];
		_v = _mm_mul_ps(_v2, _s2);
		result.M[1][1] = _v.m128_f32[3] + _v.m128_f32[2] + _v.m128_f32[1];
		_v = _mm_mul_ps(_v2, _s3);
		result.M[1][2] = _v.m128_f32[3] + _v.m128_f32[2] + _v.m128_f32[1];

		_v = _mm_mul_ps(_v3, _s1);
		result.M[2][0] = _v.m128_f32[3] + _v.m128_f32[2] + _v.m128_f32[1];
		_v = _mm_mul_ps(_v3, _s2);
		result.M[2][1] = _v.m128_f32[3] + _v.m128_f32[2] + _v.m128_f32[1];
		_v = _mm_mul_ps(_v3, _s3);
		result.M[2][2] = _v.m128_f32[3] + _v.m128_f32[2] + _v.m128_f32[1];

}
#else
	{
		for (unsigned char i = 0; i < 3; i++)
			for (unsigned char j = 0; j < 3; j++)
				for (unsigned int k = 0; k < 3; k++)
					result.M[i][j] += M[i][k] * matrix.M[k][j];
	}
#endif
	return result;
}
