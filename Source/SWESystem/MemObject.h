#pragma once
/*所有继承MemObject的类将使用引擎的内存管理器*/
#include "SWESystem.h"
#include "MemoryManager.h"
#include <cstdlib>

namespace SWE
{
	class SWESYSTEM_API MemObject
	{
	public:
		MemObject() = default;
		virtual ~MemObject() = default;

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