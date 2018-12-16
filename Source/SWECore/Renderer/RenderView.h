#pragma once
//װ�䵽��Ⱦ���ߵ�view��Դ

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
