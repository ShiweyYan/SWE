#pragma once
//Object��ӵ������ײ㹦��֧�ֵĻ�����,����֧��������ڴ����,���ü���
#include "SWESystem.h"
#include "Reference.h"
#include "Rtti.h"
#include "EngineMacro.h"
#include "SmartPointer.h"

namespace SWE
{
	class SWESYSTEM_API  Object : public Reference
	{
		DECLEAR_RTTI
	public:
		Object() = default;
		~Object() = default;
	};

	SMART_POINTER(Object);
 }