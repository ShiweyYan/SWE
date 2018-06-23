#include "GameObject.h"

using namespace SWE;

IMPLEMENT_RTTI_1(GameObject, Object)

SWE::GameObject::GameObject()
{
	for (size_t i = 0; i < Component::ECT_COUNT; i++)
	{
		m_spComponentsArray[i] = nullptr;
	}
}

bool SWE::GameObject::AddComponent(Component* pComponent)
{
	Component::ENUM_COMPONENT_TYPE eType = pComponent->GetComponentType();
	if (m_spComponentsArray[eType] == nullptr)
	{
		m_spComponentsArray[eType] = pComponent;
		pComponent->Register(this);
		return true;
	}

	return false;
}

void SWE::GameObject::RemoveComponent(Component::ENUM_COMPONENT_TYPE eType)
{
	if (m_spComponentsArray[eType])
	{
		m_spComponentsArray[eType]->Unregister();
		m_spComponentsArray[eType] = nullptr;
	}
}
