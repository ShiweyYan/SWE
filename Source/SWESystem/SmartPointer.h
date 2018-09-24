#pragma once
//只有继承了Reference的类才能使用该智能指针
#include "MemObject.h"

namespace SWE
{
	template<class T>
	class  SmartPointer : public MemObject//SWESYSTEM_API
	{
	public:
		SmartPointer(T* pRaw = nullptr):
			m_pRawPointer(pRaw)
		{
			if (m_pRawPointer)
			{
				m_pRawPointer->IncRef();
			}
		}

		~SmartPointer()
		{
			if (m_pRawPointer)
			{
				m_pRawPointer->DecRef();
				if (m_pRawPointer->GetReferenceCount() == 0)
				{
					delete m_pRawPointer;
					m_pRawPointer = nullptr;
				}
			}
		}

		inline T* GetRaw() const { return m_pRawPointer; }

		void operator()(const SmartPointer<T>& spOther)
		{
			m_pRawPointer = spOther.m_pRawPointer;
			if (m_pRawPointer)
			{
				m_pRawPointer->IncRef();
			}
		}

		SmartPointer<T>& operator=(const SmartPointer<T>& spOther)
		{
			if (this == &spOther)
			{
				return *this;
			}

			if (m_pRawPointer)
			{
				m_pRawPointer->DecRef();
				if (m_pRawPointer->GetReferenceCount() == 0)
				{
					delete m_pRawPointer;
					m_pRawPointer = nullptr;
				}
			}

			m_pRawPointer = spOther.m_pRawPointer;
			if (m_pRawPointer)
			{
				m_pRawPointer->IncRef();
			}
			
			return *this;
		}

		bool operator == (SmartPointer<T>& spOther)
		{
			if (m_pRawPointer == spOther.m_pRawPointer)
			{
				return true;
			}

			return false;
		}

		T& operator * () { return *m_pRawPointer; }
		T* operator -> () { return m_pRawPointer; }
		operator T* () { return m_pRawPointer;}
		operator bool () { return m_pRawPointer == nullptr ? false : true;}

	private:
		T * m_pRawPointer;
	};
}