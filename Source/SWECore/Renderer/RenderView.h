#pragma once
//װ�䵽��Ⱦ���ߵ�view��Դ

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
