#pragma once
//Object��ʵ�������������
#include "Reference.h"
#include "Rtti.h"
#include "EngineMacro.h"

namespace SWE
{
	class Object: public Reference
	{
		DECLEAR_RTTI
	public:
		Object();
		virtual ~Object();
		
		//void Object(const Object& obj);
		//void operator=(const Object& obj);
	};
}