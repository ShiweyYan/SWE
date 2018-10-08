#pragma once

//graphic buffer ����VB,IB������������GPU��buffer

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