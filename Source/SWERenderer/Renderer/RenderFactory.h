#pragma once
#include "SWERenderer/Renderer/SWERenderer.h"
#include "SWESystem/Object.h"
#include "SWESystem/Singleton.h"

namespace SWE
{
	class SWERenderer_API RenderFactory : public Object, public Singleton<RenderFactory>
	{
		DECLEAR_RTTI
	private:
		RenderFactory();
		virtual ~RenderFactory();

	};

	SMART_POINTER(RenderFactory)
}