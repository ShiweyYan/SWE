#pragma once
#include "SWEDX11Renderer/SWEDX11Renderer.h"
#include "SWEDX11Renderer/DX11TypeDefine.h"
#include "SWECore/Renderer/RenderState.h"

namespace SWE
{
	class SWEDX11_API DX11RenderState : public RenderState
	{
		DECLEAR_RTTI
	public:
		DX11RenderState() = default;
		virtual ~DX11RenderState() = default;
	};

	SMART_POINTER(DX11RenderState)
}
