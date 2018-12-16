#include "Object.h"
#include "SmartPointer.h"
#include <iostream>
#include "Singleton.h"
#include "../SWEMath/Float3.h"
#include "../SWEMath/Matrix3.h"
#include <chrono>

using namespace SWE;

class A : public Singleton<A>
{
	friend Singleton<A>;
protected:
	A() {
		std::cout << "created" << std::endl;
	};
	virtual ~A() {
		std::cout << "destroied" << std::endl;
	};
};

int main()
{
	A::Get();
	A::Release();
	Matrix3 a, b, c;
	a.MakeRotationX(1.5f);
	b.MakeRotationY(1.1);

	std::chrono::system_clock::time_point t1 = std::chrono::system_clock::now();

	for (size_t i = 0; i< 2000; i++)
	{
		c = a * b;
	}

	std::chrono::system_clock::time_point t2 = std::chrono::system_clock::now();

	std::cout<<std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << "microseconds" << std::endl;

	return 0;
}