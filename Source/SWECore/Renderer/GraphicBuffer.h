#pragma once

//graphic buffer 包括VB,IB和者其他传给GPU的buffer

#include "SWECore/SWECore.h"
#include "SWESystem/Object.h"

namespace SWE
{
	class GraphicBuffer : public Object
	{
		DECLEAR_RTTI

	public:
		GraphicBuffer() = default;
		virtual ~GraphicBuffer() = default;
	};

	SMART_POINTER(GraphicBuffer)
}