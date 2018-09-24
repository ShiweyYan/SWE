#pragma once
#include "MemObject.h"

namespace SWE
{
	template <typename T>
	class SWESYSTEM_API Singleton : public MemObject
	{
	public:
		~Singleton(void)
		{
			assert(m_pSingleton);
			m_pSingleton = nullptr;
		}

		static T* CreateSingleton(void)
		{
			assert(!m_pSingleton)

			m_pSingleton = new T();

			return static_cast<T*>(m_pSingleton);
		}

		static T* GetSingleton(void)
		{
			assert(m_pSingleton);
			return m_pSingleton;
		}

	protected:
		Singleton(void) = default;

		//������ֹ�����͸�ֵ
		Singleton(const Singleton<T> &) = delete;
		Singleton& operator=(const Singleton<T> &) = delete;

	protected:
		static T* m_pSingleton;
	};
}