#pragma once
#include "SWECore/SWECore.h"
#include "SWECore/Renderer/RendererDesc.h"
#include "SWESystem/Object.h"

namespace SWE
{
	enum RENDERER_TYPE
	{
		RT_NONE = 0,
		RT_D3D11 = 1,
	};

	class SWECORE_API Renderer: public Object
	{
		DECLEAR_RTTI
	public:
		virtual RENDERER_TYPE GetType() { return RT_NONE; };

		static Renderer* Create(const RendererDesc& desc);
		static bool Release();
		static Renderer* Get() { return m_pRenderer; }

	protected:
		Renderer();
		virtual ~Renderer() = default;
		virtual void Init(RendererDesc desc) {};

		static Renderer* m_pRenderer;
	};

	SMART_POINTER(Renderer)
};