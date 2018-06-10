#pragma once
//Object类实现引擎基础功能
#include "Reference.h"
#include "Rtti.h"
#include "EngineMacro.h"
#include "MemoryManager.h"

namespace SWE
{
	class Object: public Reference
	{
		DECLEAR_RTTI
	public:
		Object() = default;
		virtual ~Object() = default;

		//重载new, new[], delete, delete[]让所有Object都使用自己的内存管理器分配内存
		static void* operator new(std::size_t sz)
		{
			return m_memoryManager.Allocate(sz);
		}
		static void* operator new[](std::size_t sz)
		{
			return m_memoryManager.Allocate(sz);
		}
		static void operator delete(void* ptr, std::size_t sz)
		{
			m_memoryManager.Free(ptr, sz);
		}
		static void operator delete[](void* ptr, std::size_t sz)
		{
			m_memoryManager.Free(ptr, sz);
		}

	private:
		static MemoryManager m_memoryManager;
	};
}