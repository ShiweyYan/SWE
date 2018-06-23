#pragma once
#include "Object.h"
#include "Component.h"
#include "SmartPointer.h"

namespace SWE
{
	class GameObject : public Object
	{
		DECLEAR_RTTI
	public:
		GameObject();
		~GameObject() = default;

		//如果该类型的组件已经存在,再次添加会失败(return false),需要先remove
		bool AddComponent(Component* pComponent);
		void RemoveComponent(Component::ENUM_COMPONENT_TYPE eType);

	private:
		//一个槽对应一个类型的组建,每个类型的组建只能有一个
		ComponentPtr m_spComponentsArray[Component::ECT_COUNT];
	};

	SMART_POINTER(GameObject)
}