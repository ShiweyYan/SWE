#pragma once
#include <vector>
#include "SWESystem.h"
#include "Component.h"

namespace SWE
{
	class SWESYSTEM_API SceneNodeComponent : public Component
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
#pragma warning(push)
#pragma warning(disable:4251)//关闭由STL引起的4251,但是使用SWESystem的客户端必须和SWESYSTEM使用相同的STL版本,否则会引起崩溃
		std::vector<ComponentPtr>m_spChildrenVec;
#pragma warning(pop)
	};

	SMART_POINTER(SceneNodeComponent)
}