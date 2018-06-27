#pragma once
//Object��ʵ�������������
#include "SWESystem.h"
#include "Reference.h"
#include "Rtti.h"
#include "EngineMacro.h"
#include "MemoryManager.h"

namespace SWE
{
	class SWESYSTEM_API Object: public Reference
	{
		DECLEAR_RTTI
	public:
		Object() = default;
		virtual ~Object() = default;

		//����new, new[], delete, delete[]������Object��ʹ���Լ����ڴ�����������ڴ�
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