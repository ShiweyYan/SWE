#pragma once
#include "SWECore/SWECore.h"
#include "SWESystem/Object.h"

namespace SWE
{
	//RenderTargetGroup�����ṹ
	struct RTGDesc
	{
		unsigned int width;
		unsigned int height;
		//��ʽ(color buffer�ĺ�depth stencil��)
		//

	};

	class SWECORE_API RenderTarget : public Object
	{
		DECLEAR_RTTI
	public:
		RenderTarget() {}
		virtual ~RenderTarget() {}
	};

	SMART_POINTER(RenderTarget)
}