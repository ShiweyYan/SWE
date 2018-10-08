#pragma once
#include "MemObject.h"
#include <assert.h>

namespace SWE
{
	template <typename T>
	class  Singleton : public MemObject
	{
	public:

		static T* CreateSingleton(void)
		{
			assert(!m_pSingleton);

			m_pSingleton = new T();

			return static_cast<T*>(m_pSingleton);
		}

		static void Release()
		{
			if (m_pSingleton)
			{
				delete m_pSingleton;
				m_pSingleton = nullptr;
			}
		}

		static T* GetSingleton(void)
		{
			assert(m_pSingleton);
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