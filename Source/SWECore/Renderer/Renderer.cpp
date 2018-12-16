#include "SWECore/Renderer/Renderer.h"
#include <assert.h>

using namespace SWE;

IMPLEMENT_RTTI_1(Renderer, Object)

Renderer* Renderer::m_pRenderer = nullptr;

Renderer* Renderer::Create(const RendererDesc& desc)
{
	assert(m_pRenderer == nullptr);
	return m_pRenderer;
}

Renderer::Renderer()
{

}

bool SWE::Renderer::Release()
{
	if (m_pRenderer)
	{
		delete m_pRenderer;
		m_pRenderer = nullptr;
		return true;
	}

	return false;
}
