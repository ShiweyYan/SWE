#pragma once
#include <string>

namespace SWE
{
	class Rtti
	{
	public:
		Rtti(std::string strName, unsigned int  uiBaseClassesNum = 0, ...);
		~Rtti();

		std::string GetName() const { return m_strName; }
		Rtti** GetParent() const { return m_ppBaseClasses; }
		unsigned int GetParentNum() const { return m_uiBaseClassesNum; }
		bool IsExactType(const Rtti& type) const;
		bool IsKindOf(const Rtti& type) const;

	private:
		std::string m_strName;
		unsigned int m_uiBaseClassesNum;
		Rtti** m_ppBaseClasses;
	};
}