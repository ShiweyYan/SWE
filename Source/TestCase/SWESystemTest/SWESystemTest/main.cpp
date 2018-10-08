#include "Object.h"
#include "SmartPointer.h"
#include <iostream>
#include "Singleton.h"

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
	std::cout << "Hello World!\n";
	return 0;
}