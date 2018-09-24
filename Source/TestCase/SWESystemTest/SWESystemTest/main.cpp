#include "Object.h"
#include "SmartPointer.h"
#include <iostream>

using namespace SWE;

class TestObject : public Object
{
public:
	TestObject()
	{
		std::cout << "constructed"<<std::endl;
	}

	~TestObject()
	{
		std::cout << "destructed" << std::endl;
	}
};

SMART_POINTER(TestObject)

void main()
{
	TestObjectPtr spTestObj = new TestObject;
	//TestObjectPtr spTestObj1 = spTestObj;
	spTestObj = NULL;
	std::cout << "end" << std::endl;
}