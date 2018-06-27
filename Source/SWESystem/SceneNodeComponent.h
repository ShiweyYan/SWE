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
		//��Ա��ֻ���û��������ָ��,��Ϊû�취����incomplete����
		ComponentPtr m_spFatherNode;
#pragma warning(push)
#pragma warning(disable:4251)//�ر���STL�����4251,����ʹ��SWESystem�Ŀͻ��˱����SWESYSTEMʹ����ͬ��STL�汾,������������
		std::vector<ComponentPtr>m_spChildrenVec;
#pragma warning(pop)
	};

	SMART_POINTER(SceneNodeComponent)
}