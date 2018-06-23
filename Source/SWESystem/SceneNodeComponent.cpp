#include "SceneNodeComponent.h"

using namespace SWE;

IMPLEMENT_RTTI_1(SceneNodeComponent, Component)

void SWE::SceneNodeComponent::AttachTo(SceneNodeComponent* pSceneNode)
{
	m_spFatherNode = pSceneNode;
	pSceneNode->m_spChildrenVec.push_back(this);
}

void SWE::SceneNodeComponent::DettachFromFatherNode()
{
	if (m_spFatherNode)
	{
		static_cast<SceneNodeComponent*>(m_spFatherNode.GetRaw())->Dettach(this);
		m_spFatherNode = nullptr;
	}
}

void SWE::SceneNodeComponent::Update(uint32_t uiDeltaTime)
{

}

void SWE::SceneNodeComponent::Dettach(SceneNodeComponent* pChildNode)
{
	for (auto iter = m_spChildrenVec.begin(); iter != m_spChildrenVec.end(); iter++)
	{
		if ((*iter) == pChildNode)
		{
			m_spChildrenVec.erase(iter);
			break;
		}
	}
}
