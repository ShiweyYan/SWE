#include "MemoryManager.h"
#include "Utility.h"
#include <malloc.h>

using namespace SWE;

namespace SWE {
	static const uint32_t kBlockSizes[] = {
		// 4-increments
		4,  8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48,
		52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96,

		// 32-increments
		128, 160, 192, 224, 256, 288, 320, 352, 384,
		416, 448, 480, 512, 544, 576, 608, 640,

		// 64-increments
		704, 768, 832, 896, 960, 1024
	};

	void MemoryManager::Init()
	{
		static bool bInited = false;
		if (!bInited)
		{
			// 初始化block size查找表
			m_pBlockSizeLookUpTable = new size_t[m_kMaxBlockSize + 1];
			size_t j = 0;
			for (size_t i = 0; i <= m_kMaxBlockSize; i++) {
				if (i > kBlockSizes[j]) ++j;
				m_pBlockSizeLookUpTable[i] = j;
			}

			//初始化内存池
			m_pMemoryPools = new MemoryPool[m_kNumBlockSizes];
			for (size_t i = 0; i < m_kNumBlockSizes; i++) {
				m_pMemoryPools[i].Reset(kBlockSizes[i], m_kPageSize, m_kAlignment);
			}

			bInited = true;
		}
	}

	void MemoryManager::Release()
	{
		SafeDeleteArray(m_pBlockSizeLookUpTable);
		SafeDeleteArray(m_pMemoryPools);
	}

	MemoryManager::MemoryManager(uint32_t uiPageSize, uint32_t uiAlignSize):
		m_kPageSize(uiPageSize),
		m_kAlignment(uiAlignSize),
		m_kNumBlockSizes(sizeof(kBlockSizes) / sizeof(kBlockSizes[0])),
		m_kMaxBlockSize(kBlockSizes[m_kNumBlockSizes - 1])
	{
		Init();
	}

	MemoryManager::MemoryManager():
		m_kPageSize(8192),
		m_kAlignment(4),
		m_kNumBlockSizes(sizeof(kBlockSizes) / sizeof(kBlockSizes[0])),
		m_kMaxBlockSize(kBlockSizes[m_kNumBlockSizes - 1])
	{
		Init();
	}

	MemoryManager::~MemoryManager()
	{
		Release();
	}

	void* MemoryManager::Allocate(size_t szSize)
	{
		MemoryPool* pMemoryPool = LookupMemoryPool(szSize);
		if (pMemoryPool)
			return pMemoryPool->Allocate();
		else
			return std::malloc(szSize);
	}

	void MemoryManager::Free(void* pVoid, size_t szSize)
	{
		MemoryPool* pMemoryPool = LookupMemoryPool(szSize);
		if (pMemoryPool)
			pMemoryPool->Free(pVoid);
		else
			std::free(pVoid);
	}

	SWE::MemoryPool* MemoryManager::LookupMemoryPool(size_t szSize)
	{
		if (szSize <= m_kMaxBlockSize)
			return m_pMemoryPools + m_pBlockSizeLookUpTable[szSize];//&m_pMemoryPools[m_pBlockSizeLookUpTable[szSize]];
		else
			return nullptr;
	}

}