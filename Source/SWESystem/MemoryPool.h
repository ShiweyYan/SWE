#pragma once
#include <cstdint>
//copy from http://allenchou.net/2013/05/memory-management-part-1-of-3-the-allocator/, https://zhuanlan.zhihu.com/p/29023579
//expand some func by shiweyyan

namespace SWE
{
	class MemoryPool
	{
	public:
		// debug patterns
		static const uint8_t PATTERN_ALIGN = 0xFC;
		static const uint8_t PATTERN_ALLOC = 0xFD;
		static const uint8_t PATTERN_FREE = 0xFE;

		struct BlockHeader {
			// union-ed with data 在free状态下,维护pNext,在allocated状态下,全部用来store data
			BlockHeader* pNext;
		};

		struct PageHeader {
			PageHeader* pNext;
			BlockHeader* Blocks() {
				return reinterpret_cast<BlockHeader*>(this + 1);
			}
		};

	public:
		MemoryPool() = default;
		MemoryPool(size_t dataSize, size_t pageSize, size_t alignment);
		~MemoryPool();

		// resets the allocator to a new configuration
		void Reset(size_t dataSize, size_t pageSize, size_t alignment);

		void* Allocate();
		void Free(void* pVoid);
		void FreeAll();

	private:
		BlockHeader * NextBlock(BlockHeader *pBlock);
#if defined(_DEBUG)
		// fill a free page with debug patterns
		void FillFreePage(PageHeader* pPage);

		// fill a block with debug patterns
		void FillFreeBlock(BlockHeader* pBlock);

		// fill an allocated block with debug patterns
		void FillAllocatedBlock(BlockHeader* pBlock);
#endif

	private:
		PageHeader * m_pPageList;
		BlockHeader* m_pFreeList;

		size_t      m_szDataSize;
		size_t      m_szPageSize;
		size_t      m_szAlignmentSize;
		size_t      m_szBlockSize;
		uint32_t    m_nBlocksPerPage;

		// statistics
		uint32_t    m_nPages;
		uint32_t    m_nBlocks;
		uint32_t    m_nFreeBlocks;
	};
}