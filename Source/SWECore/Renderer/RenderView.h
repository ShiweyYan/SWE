#pragma once
//装配到渲染管线的view资源

#include "SWECore/SWECore.h"
#include "SWESystem/Object.h"

namespace SWE
{
	class RenderView : public Object
	{
		DECLEAR_RTTI

	public:
		RenderView() = default;
		virtual ~RenderView() = default;
	};

	SMART_POINTER(RenderView)
}
