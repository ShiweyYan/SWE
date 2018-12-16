#pragma once

//graphic buffer ����VB,IB������������GPU��buffer

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