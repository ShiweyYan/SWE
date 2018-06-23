#pragma once
#include "Component.h"
#include <vector>

namespace SWE
{
	class SceneNodeComponent : public Component
	{
		DECLEAR_RTTI
	public:
		SceneNodeComponent() = default;
		~SceneNodeComponent() = default;

		void AttachTo(SceneNodeComponent* pSceneNode);
		void DettachFromFatherNode();
		
		inline virtual ENUM_COMPONENT_TYPE GetComponentType() const { return Component::ECT_SCENE_NODE; }
		virtual void Update(uint32_t uiDeltaTime);

	private:
		void Dettach(SceneNodeComponent* pChildNode);

	private:
		//成员都只能用基类的智能指针,因为没办法包含incomplete对象
		ComponentPtr m_spFatherNode;
		std::vector<ComponentPtr>m_spChildrenVec;
	};

	SMART_POINTER(SceneNodeComponent)
}