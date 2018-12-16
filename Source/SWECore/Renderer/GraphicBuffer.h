#pragma once

//graphic buffer 包括VB,IB和者其他传给GPU的buffer

#include "SWECore/SWECore.h"
#include "SWECore/Renderer/GpuResource.h"

namespace SWE
{
	class SWECORE_API GraphicBuffer : public GpuResource
	{
		DECLEAR_RTTI

	public:
		GraphicBuffer() = default;
		virtual ~GraphicBuffer() = default;
	};

	SMART_POINTER(GraphicBuffer)
}