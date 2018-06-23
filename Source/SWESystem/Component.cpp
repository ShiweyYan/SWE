#include "Component.h"

using namespace SWE;

IMPLEMENT_RTTI_1(Component, Object)

SWE::Component::Component():
	m_pOwner(nullptr)
{

}

SWE::Component::~Component()
{
	m_pOwner = nullptr;
}
