#include "Object.h"
#include "SmartPointer.h"
#include <iostream>
#include "Singleton.h"
#include "../SWEMath/Float3.h"

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
	A::CreateSingleton();
	A::Release();

	return 0;
}