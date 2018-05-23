#include "Rtti.h"
#include <stdarg.h>
#include "Utility.h"

using namespace SWE;

SWE::Rtti::Rtti(std::string strName, unsigned int uiBaseClassesNum /*= 0*/, ...)
{
	m_strName = strName;
	m_uiBaseClassesNum = uiBaseClassesNum;

	if (uiBaseClassesNum == 0)
	{
		m_ppBaseClasses = NULL;
	}
	else
	{
		m_ppBaseClasses = new Rtti*[uiBaseClassesNum];
		va_list list;
		va_start(list, uiBaseClassesNum);
		for (size_t i = 0; i < uiBaseClassesNum; i++)
		{
			m_ppBaseClasses[i] = va_arg(list, Rtti*);
		}
		va_end(list);
	}
}

SWE::Rtti::~Rtti()
{
	SafeDeleteArray(m_ppBaseClasses);
}

bool SWE::Rtti::IsExactType(const Rtti& type) const
{
	return &type == this;
}

bool SWE::Rtti::IsKindOf(const Rtti& type) const
{
	if (&type == this)
	{
		return true;
	}
	else
	{
		for (size_t i = 0; i < m_uiBaseClassesNum; i++)
		{
			if (m_ppBaseClasses[i]->IsKindOf(type))
			{
				return true;
			}
		}
	}

	return false;
}