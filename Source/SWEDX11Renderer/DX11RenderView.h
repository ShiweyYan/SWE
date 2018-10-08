#pragma once
#include "SWEDX11Renderer/SWEDX11Renderer.h"
#include "SWEDX11Renderer/DX11TypeDefine.h"
#include "SWECore/Renderer/RenderView.h"

namespace SWE
{
	class SWEDX11_API DX11RenderView : public RenderView
	{
		DECLEAR_RTTI
	public:
		DX11RenderView() = default;
		virtual ~DX11RenderView() = default;
	};

	SMART_POINTER(DX11RenderView)
}