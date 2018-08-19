#pragma once
#include "SWERenderer/Renderer/SWERenderer.h"
#include "SWESystem/Object.h"

namespace SWE
{
	class SWERenderer_API RenderState : public Object
	{
		DECLEAR_RTTI
	public:
		enum ENUM_CULL_MODE
		{
			ECM_NONE,
			ECM_FRONT,
			ECM_BACK,
		};

		enum ENUM_FILL_MODE
		{
			ECM_SOLID,
			EFM_WIREFRAME,
		};

		struct RasterizerState
		{
			ENUM_FILL_MODE FillMode;
			ENUM_CULL_MODE CullMode;
			bool				FrontCounterClockWise;
			bool            FrontCounterClockwise;
			int             DepthBias;
			float           DepthBiasClamp;
			float           SlopeScaledDepthBias;
			bool            DepthClipEnable;
			bool            ScissorEnable;
			bool            MultisampleEnable;
			bool            AntialiasedLineEnable;
		};

		enum ENUM_BLEND
		{
			EB_BLEND_ZERO,
			EB_BLEND_ONE,
			EB_BLEND_SRC_COLOR,
			EB_BLEND_INV_SRC_COLOR,
			EB_BLEND_SRC_ALPHA,
			EB_BLEND_INV_SRC_ALPHA,
			EB_BLEND_DEST_ALPHA,
			EB_BLEND_INV_DEST_ALPHA,
			EB_BLEND_DEST_COLOR,
			EB_BLEND_INV_DEST_COLOR,
			EB_BLEND_SRC_ALPHA_SAT,
			EB_BLEND_BLEND_FACTOR,
			EB_BLEND_INV_BLEND_FACTOR,
			EB_BLEND_SRC1_COLOR,
			EB_BLEND_INV_SRC1_COLOR,
			EB_BLEND_SRC1_ALPHA,
			EB_BLEND_INV_SRC1_ALPHA
		};

		enum ENUM_BLEND_OP
		{
			EBO_BLEND_OP_ADD,
			EBO_BLEND_OP_SUBTRACT,
			EBO_BLEND_OP_REV_SUBTRACT,
			EBO_BLEND_OP_MIN,
			EBO_BLEND_OP_MAX
		};

		struct BlendState
		{
			struct RTBlendState
			{
				bool           BlendEnable;
				ENUM_BLEND    SrcBlend;
				ENUM_BLEND    DestBlend;
				ENUM_BLEND_OP BlendOp;
				ENUM_BLEND    SrcBlendAlpha;
				ENUM_BLEND    DestBlendAlpha;
				ENUM_BLEND_OP BlendOpAlpha;
				uint8_t          RenderTargetWriteMask;
			};
			bool m_bAlphaToCoverageEnable;
			bool m_bIndependentBlendEnable;
			RTBlendState m_kRTBlendStates[8];
		};

		enum ENUM_COMPARISON_FUNC
		{
			ECF_COMPARISON_NEVER,
			ECF_COMPARISON_LESS,
			ECF_COMPARISON_EQUAL,
			ECF_COMPARISON_LESS_EQUAL,
			ECF_COMPARISON_GREATER,
			ECF_COMPARISON_NOT_EQUAL,
			ECF_COMPARISON_GREATER_EQUAL,
			ECF_COMPARISON_ALWAYS
		};

		enum ENUM_STENCIL_OP
		{
			ESO_STENCIL_OP_KEEP,
			ESO_STENCIL_OP_ZERO,
			ESO_STENCIL_OP_REPLACE,
			ESO_STENCIL_OP_INCR_SAT,
			ESO_STENCIL_OP_DECR_SAT,
			ESO_STENCIL_OP_INVERT,
			ESO_STENCIL_OP_INCR,
			ESO_STENCIL_OP_DECR
		};

		struct ENUM_DEPTH_STENCILOP_DESC {
			ENUM_STENCIL_OP      StencilFailOp;
			ENUM_STENCIL_OP      StencilDepthFailOp;
			ENUM_STENCIL_OP      StencilPassOp;
			ENUM_COMPARISON_FUNC StencilFunc;
		};

		struct DepthStencilState
		{
			bool     DepthEnable;
			bool     DepthWriteEnable;
			ENUM_COMPARISON_FUNC      DepthFunc;
			bool      StencilEnable;
			uint8_t    StencilReadMask;
			uint8_t    StencilWriteMask;
			ENUM_DEPTH_STENCILOP_DESC FrontFace;
			ENUM_DEPTH_STENCILOP_DESC BackFace;
		};

		RenderState();
		virtual ~RenderState();

		//渲染器的派生类中实现
		virtual void ApplyRasterizerState() {}
		virtual void ApplyBlendState() {}
		virtual void ApplyDepthStencilState() {}

		//各种设置和获取的接口,后边用的什么补什么吧...有点儿多

	private:
		RasterizerState m_kRasterizerState;
		BlendState m_kBlendState;
		DepthStencilState m_kDepthStencilState;
	};

	SMART_POINTER(RenderState)
}