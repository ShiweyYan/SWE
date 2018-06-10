#pragma once
#include "MemoryPool.h"
//可能会存在多个不同的内存管理器,方便特殊化和内存统计,例如所有继承自object的对象拥有一个内存管理器,普通类拥有另一个内存管理器等

namespace SWE
{
	class MemoryManager
	{
	public:
		MemoryManager();
		MemoryManager(uint32_t uiPageSize, uint32_t uiAlignSize);
		~MemoryManager();

		void* Allocate(size_t szSize);
		void Free(void* pVoid, size_t szSize);

	private:
		//构建和释放内存池的函数,整个游戏生命周期只会调用一次
		void Init();
		void Release();

		MemoryPool* LookupMemoryPool(size_t szSize);
		
	private:
		MemoryPool* m_pMemoryPools;
		size_t * m_pBlockSizeLookUpTable;

		const uint32_t m_kPageSize;
		const uint32_t m_kAlignment;

		const uint32_t m_kNumBlockSizes;
		const uint32_t m_kMaxBlockSize;
	};
}