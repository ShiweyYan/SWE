#pragma once

namespace SWE
{
	class Reference
	{
	public:
		Reference();
		virtual ~Reference();
	
		unsigned int GetReferenceCount() const { return m_uiRefCount; }
		void IncRef() { m_uiRefCount++; }
		void DecRef() { m_uiRefCount--; }

	private:
		unsigned int m_uiRefCount;
	};
}