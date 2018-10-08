#pragma once
#include "SWECore/SWECore.h"
#include "SWESystem/Object.h"
#include "SWESystem/Singleton.h"

namespace SWE
{
	class SWECORE_API RenderFactory : public Object, public Singleton<RenderFactory>
	{
		DECLEAR_RTTI
		friend Singleton<RenderFactory>;
	protected:
		RenderFactory();
		virtual ~RenderFactory();

	};

	SMART_POINTER(RenderFactory)
}