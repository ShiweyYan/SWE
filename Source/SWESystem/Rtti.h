#pragma once
#include <string>
#include "MemObject.h"

namespace SWE
{
	class SWESYSTEM_API Rtti : public MemObject
	{
	public:
		Rtti(std::string strName, unsigned int  uiBaseClassesNum = 0, ...);
		~Rtti();

		inline std::string GetName() const { return m_strName; }
		inline Rtti** GetParent() const { return m_ppBaseClasses; }
		inline unsigned int GetParentNum() const { return m_uiBaseClassesNum; }
		bool IsExactType(const Rtti& type) const;
		bool IsKindOf(const Rtti& type) const;
		template <class T> T* DynamicCast(const Rtti& type, void* pObj) const;

	private:
#pragma warning(push)
#pragma warning(disable:4251)//关闭由STL引起的4251,但是使用SWESystem的客户端必须和SWESYSTEM使用相同的STL版本,否则会引起崩溃
		std::string m_strName;
#pragma warning(pop)
		unsigned int m_uiBaseClassesNum;
		Rtti** m_ppBaseClasses;
	};

	template <class T>
	T*	Rtti::DynamicCast(const Rtti& type, void* pObj) const
	{
		if (IsKindOf(type))
		{
			return static_cast<T*>(pObj);
		}

		return nullptr;
	}
}