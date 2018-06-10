#pragma once
//只有继承了Reference的类才能使用该智能指针

namespace SWE
{
	template<class T>
	class SmartPoint
	{
	public:
		SmartPoint(T* pRaw):
			m_pRawPoint(pRaw)
		{
			m_pRawPoint->IncRef();
		}

		void operator()(const SmartPoint<T>& spOther)
		{
			m_pRawPoint = spOther.m_pRawPoint;
			m_pRawPoint->IncRef();
		}

		SmartPoint<T>& operator=(const SmartPoint<T>& spOther)
		{
			if (this == &spOther)
			{
				return *this;
			}

			m_pRawPoint = spOther.m_pRawPoint;
			m_pRawPoint->IncRef();
			return *this;
		}

		operatorT*()
		{
			return m_pRawPoint;
		}

		~SmartPoint()
		{
			m_pRawPoint->DecRef();
			if (m_pRawPoint->GetReferenceCount() == 0)
			{
				delete m_pRawPoint;
				m_pRawPoint = nullptr;
			}
		}

	private:
		T * m_pRawPoint;
	};
}