#pragma once
//Object是拥有引擎底层功能支持的基础类,例如支持引擎的内存管理,引用计数
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