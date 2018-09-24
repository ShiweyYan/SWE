#pragma once
/*���м̳�MemObject���ཫʹ��������ڴ������*/
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