#pragma once

namespace SWE
{
	class Reference
	{
	public:
		Reference();
		virtual ~Reference();
	
		inline unsigned int GetReferenceCount() const { return m_uiRefCount; }
		inline void IncRef() { m_uiRefCount++; }
		inline void DecRef() { m_uiRefCount--; }

	private:
		unsigned int m_uiRefCount;
	};
}