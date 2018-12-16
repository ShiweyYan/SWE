#pragma once
//装配到渲染管线的view资源

#include "SWECore/SWECore.h"
#include "SWESystem/Object.h"
#include "Texture.h"

namespace SWE
{
	class RenderView : public Object
	{
		DECLEAR_RTTI

	public:
		RenderView(Texture* pTexture);
		virtual ~RenderView() = default;

	protected:
		TexturePtr m_spTexture;
	};

	SMART_POINTER(RenderView)
}
