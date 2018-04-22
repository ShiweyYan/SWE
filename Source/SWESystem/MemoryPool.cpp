#include "MemoryPool.h"
#include <assert.h>
#include <memory.h>

using namespace SWE;

#ifndef ALIGN
#define ALIGN(x, a)         (((x) + ((a) - 1)) & ~((a) - 1))
#endif

SWE::MemoryPool::MemoryPool(size_t dataSize, size_t pageSize, size_t alignment):
	m_pFreeList(nullptr),
	m_pPageList(nullptr)
{
	Reset(dataSize, pageSize, alignment);
}

SWE::MemoryPool::~MemoryPool()
{
	FreeAll();
}

void SWE::MemoryPool::Reset(size_t dataSize, size_t pageSize, size_t alignment)
{
	FreeAll();

	m_szDataSize = dataSize;
	m_szPageSize = pageSize;

	size_t minimalSize = (sizeof(BlockHeader) > m_szDataSize) ? sizeof(BlockHeader) : m_szDataSize;

#if defined(_DEBUG)
	//对齐大小不是2^n, assert
	assert(alignment > 0 && ((alignment & (alignment - 1))) == 0);
#endif
	m_szBlockSize = ALIGN(minimalSize, alignment);

	m_szAlignmentSize = m_szBlockSize - minimalSize;

	m_nBlocksPerPage = (uint32_t)( (m_szPageSize - sizeof(PageHeader)) / m_szBlockSize );
}

void* SWE::MemoryPool::Allocate()
{
	//如果没有空闲内存,创建新的内存page
	if (!m_pFreeList) 
	{
		// allocate a new page
		PageHeader* pNewPage = reinterpret_cast<PageHeader*>(new uint8_t[m_szPageSize]);
		++m_nPages;
		m_nBlocks += m_nBlocksPerPage;
		m_nFreeBlocks += m_nBlocksPerPage;

#if defined(_DEBUG)
		FillFreePage(pNewPage);
#endif

		if (m_pPageList) 
		{
			pNewPage->pNext = m_pPageList;
		}

		m_pPageList = pNewPage;

		BlockHeader* pBlock = pNewPage->Blocks();
		// link each block in the page
		for (uint32_t i = 0; i < m_nBlocksPerPage; i++) 
		{
			pBlock->pNext = NextBlock(pBlock);
			pBlock = NextBlock(pBlock);
		}
		pBlock->pNext = nullptr;

		m_pFreeList = pNewPage->Blocks();
	}

	//返回链表中最前的内存block
	BlockHeader* pFreeBlock = m_pFreeList;
	m_pFreeList = m_pFreeList->pNext;
	--m_nFreeBlocks;

#if defined(_DEBUG)
	FillAllocatedBlock(pFreeBlock);
#endif

	return reinterpret_cast<void*>(pFreeBlock);
}

void SWE::MemoryPool::Free(void* pVoid)
{
	BlockHeader* block = reinterpret_cast<BlockHeader*>(pVoid);

#if defined(_DEBUG)
	FillFreeBlock(block);
#endif

	block->pNext = m_pFreeList;
	m_pFreeList = block;
	++m_nFreeBlocks;
}

void SWE::MemoryPool::FreeAll()
{
	PageHeader* pPage = m_pPageList;
	while (pPage) {
		PageHeader* _p = pPage;
		pPage = pPage->pNext;

		delete[] reinterpret_cast<uint8_t*>(_p);
	}

	m_pPageList = nullptr;
	m_pFreeList = nullptr;

	m_nPages = 0;
	m_nBlocks = 0;
	m_nFreeBlocks = 0;
}

SWE::MemoryPool::BlockHeader * SWE::MemoryPool::NextBlock(BlockHeader *pBlock)
{
	return reinterpret_cast<BlockHeader *>(reinterpret_cast<uint8_t*>(pBlock) + m_szBlockSize);
}

#if defined(_DEBUG)
void SWE::MemoryPool::FillFreePage(PageHeader* pPage)
{
	// page header
	pPage->pNext = nullptr;

	// blocks
	BlockHeader *currBlock = pPage->Blocks();
	for (unsigned i = 0; i < m_nBlocksPerPage; ++i)
	{
		FillFreeBlock(currBlock);
		currBlock = NextBlock(currBlock);
	}
}

void SWE::MemoryPool::FillFreeBlock(BlockHeader* pBlock)
{
	// block header + data
	memset(pBlock, PATTERN_FREE, m_szBlockSize - m_szAlignmentSize);

	// alignment
	memset(reinterpret_cast<char *>(pBlock) + m_szBlockSize - m_szAlignmentSize, PATTERN_ALIGN, m_szAlignmentSize);
}

void SWE::MemoryPool::FillAllocatedBlock(BlockHeader* pBlock)
{
	// block header + data
	memset(pBlock, PATTERN_ALLOC, m_szBlockSize - m_szAlignmentSize);

	// alignment
	memset(reinterpret_cast<char *>(pBlock) + m_szBlockSize - m_szAlignmentSize, PATTERN_ALIGN, m_szAlignmentSize);
}
#endif
