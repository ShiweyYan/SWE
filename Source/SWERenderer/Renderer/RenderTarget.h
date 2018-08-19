#pragma once
#include "SWERenderer/Renderer/SWERenderer.h"
#include "SWESystem/Object.h"

namespace SWE
{
	//RenderTargetGroup描述结构
	struct RTGDesc
	{
		unsigned int width;
		unsigned int height;
		//格式(color buffer的和depth stencil的)
		//

	};

	class SWERenderer_API RenderTarget : public Object
	{
		DECLEAR_RTTI
	public:
		RenderTarget() {}
		virtual ~RenderTarget() {}
	};

	SMART_POINTER(RenderTarget)
}