#pragma once
#include "MemObject.h"
#include <assert.h>

namespace SWE
{
	template <typename T>
	class  Singleton
	{
	public:
		static void Release()
		{
			if (m_pSingleton)
			{
				delete m_pSingleton;
				m_pSingleton = nullptr;
			}
		}

		static T* Get(void)
		{
			if (m_pSingleton == nullptr)
			{
				m_pSingleton = new T;
			}
			return m_pSingleton;
		}

	protected:
		Singleton(void) {};
		~Singleton(void) {};

		//µ¥Àý½ûÖ¹¿½±´ºÍ¸³Öµ
		Singleton(const Singleton<T> &) = delete;
		Singleton& operator=(const Singleton<T> &) = delete;

		static T* m_pSingleton;
	};

	template<class T>
	T* Singleton<T>::m_pSingleton = nullptr;
}