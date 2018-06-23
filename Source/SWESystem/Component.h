#pragma once
#include "Object.h"
#include "SmartPointer.h"

namespace SWE
{
	class GameObject;

	class Component : public Object
	{
		DECLEAR_RTTI
	public:
		enum ENUM_COMPONENT_TYPE
		{
			ECT_SCENE_NODE,
			ECT_COUNT
		};

	public:
		Component();
		~Component();

		inline void Register(GameObject* pGameObject) { m_pOwner = pGameObject; }
		inline void Unregister() { m_pOwner = nullptr; }

		virtual ENUM_COMPONENT_TYPE GetComponentType() const = 0;
		virtual void Update(uint32_t uiDeltaTime) = 0;

	private:
		GameObject* m_pOwner;
	};

	SMART_POINTER(Component)
}