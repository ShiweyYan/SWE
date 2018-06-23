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

		//��������͵�����Ѿ�����,�ٴ���ӻ�ʧ��(return false),��Ҫ��remove
		bool AddComponent(Component* pComponent);
		void RemoveComponent(Component::ENUM_COMPONENT_TYPE eType);

	private:
		//һ���۶�Ӧһ�����͵��齨,ÿ�����͵��齨ֻ����һ��
		ComponentPtr m_spComponentsArray[Component::ECT_COUNT];
	};

	SMART_POINTER(GameObject)
}