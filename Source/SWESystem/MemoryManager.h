#pragma once
#include "MemoryPool.h"
//���ܻ���ڶ����ͬ���ڴ������,�������⻯���ڴ�ͳ��,�������м̳���object�Ķ���ӵ��һ���ڴ������,��ͨ��ӵ����һ���ڴ��������

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
		//�������ͷ��ڴ�صĺ���,������Ϸ��������ֻ�����һ��
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