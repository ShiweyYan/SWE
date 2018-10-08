#pragma once
#include "SWECore/SWECore.h"
#include "SWECore/Renderer/RendererDesc.h"
#include "SWESystem/Object.h"
#include "SWESystem/Singleton.h"

namespace SWE
{
	enum RENDERER_TYPE
	{
		RT_NONE = 0,
		RT_D3D11 = 1,
	};

	class SWECORE_API Renderer : public Object, public Singleton<Renderer>
	{
		DECLEAR_RTTI
		friend Singleton<Renderer>;
	public:
		virtual void Init(RendererDesc desc) {};
		virtual RENDERER_TYPE GetType() { return RT_NONE; };

	protected:
		Renderer() = default;
		virtual ~Renderer() {}
	};

	SMART_POINTER(Renderer)
};