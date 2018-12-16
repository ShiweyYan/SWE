#include "SWECore/Renderer/RenderView.h"

using namespace SWE;

IMPLEMENT_RTTI_1(RenderView, Object)

SWE::RenderView::RenderView(Texture* pTexture):
	m_spTexture(pTexture)
{

}
