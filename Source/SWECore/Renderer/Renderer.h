#pragma once
#include "SWERenderer/Renderer/SWERenderer.h"
#include "SWESystem/Object.h"

namespace SWE
{
	enum RENDERER_TYPE
	{
		RT_D3D11 = 0,
	};

	class SWERenderer_API Renderer : public Object
	{
		DECLEAR_RTTI
	public:
		virtual ~Renderer() {}

		virtual RENDERER_TYPE GetType() const = 0;

	};

	SMART_POINTER(Renderer)
};