#pragma once
#include "SWECore/SWECore.h"
#include "SWESystem/Object.h"

namespace SWE
{
	class SWECORE_API RenderState : public Object
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

		struct RasterizerState
		{
			ENUM_FILL_MODE FillMode;
			ENUM_CULL_MODE CullMode;
			bool            FrontCounterClockwise;
			int             DepthBias;
			float           DepthBiasClamp;
			float           SlopeScaledDepthBias;
			bool            DepthClipEnable;
			bool            ScissorEnable;
			bool            MultisampleEnable;
			bool            AntialiasedLineEnable;
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

		struct DepthStencilOPDesc {
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
			DepthStencilOPDesc FrontFace;
			DepthStencilOPDesc BackFace;
		};

		RenderState();
		virtual ~RenderState();

		//渲染器的派生类中实现
		//virtual void ApplyRasterizerState() {}
		//virtual void ApplyBlendState() {}
		//virtual void ApplyDepthStencilState() {}

		//各种设置和获取的接口,后边用的什么补什么吧...有点儿多
		//**Depth**//
		virtual void SetDepthTestEnable(bool bIsEnable) = 0;
		virtual void SetDepthWriteEnable(bool bIsEnable) = 0;
		virtual void SetDepthFunc(ENUM_COMPARISON_FUNC eComparisonFunc) = 0;
		//**Stencil**//
		virtual void SetStencilTestEnable(bool bIsEnable) = 0;
		virtual void SetStencilReadMask(uint8_t uiMask) = 0;
		virtual void SetStencilWriteMask(uint8_t uiMask) = 0;

		virtual void SetFrontFaceStencilFailOp(ENUM_STENCIL_OP eStencilOP) = 0;
		virtual void SetFrontFaceStencilDepthFailOp(ENUM_STENCIL_OP eStencilOP) = 0;
		virtual void SetFrontFaceStencilPassOp(ENUM_STENCIL_OP eStencilOP) = 0;
		virtual void SetFrontFaceStencilFunc(ENUM_COMPARISON_FUNC eComparisonFunc) = 0;

		virtual void SetBackFaceStencilFailOp(ENUM_STENCIL_OP eStencilOP) = 0;
		virtual void SetBackFaceStencilDepthFailOp(ENUM_STENCIL_OP eStencilOP) = 0;
		virtual void SetBackFaceStencilPassOp(ENUM_STENCIL_OP eStencilOP) = 0;
		virtual void SetBackFaceStencilFunc(ENUM_COMPARISON_FUNC eComparisonFunc) = 0;

		//**Blend**//
		virtual void SetAlphaToCoverageEnable(bool bAlphaToCoverageEnable) = 0;
		virtual void SetIndependentBlendEnable(bool bIndependentBlendEnable) = 0;
		virtual void SetBlendEnable(bool bBlendEnable) = 0;
		virtual void SetSrcBlend(ENUM_BLEND eSourceBlend) = 0;
		virtual void SetDestBlend(ENUM_BLEND eDestBlend) = 0;
		virtual void SetBlendOp(ENUM_BLEND_OP eBlendOp) = 0;
		virtual void SetSrcBlendAlpha(ENUM_BLEND eSourceBlend) = 0;
		virtual void SetDestBlendAlpha(ENUM_BLEND eDestBlend) = 0;
		virtual void SetBlendOpAlpha(ENUM_BLEND_OP eBlendOp) = 0;
		virtual void SetRenderTargetWriteMask(uint8_t uiRTWriteMask) = 0;

		//**Rasterizer**//
		virtual void SetFillMode(ENUM_FILL_MODE eFillMode) = 0;
		virtual void SetCullMode(ENUM_CULL_MODE eCullMode) = 0;
		virtual void SetFrontCounterClockWise(bool bIsFrontCounterClockwise) = 0;
		virtual void SetDepthBias(int depthBias) = 0;
		virtual void SetDepthBiasClamp(float depthBiasClamp) = 0;
		virtual void SetSlopeScaledDepthBias(float slopeScaledDepthBias) = 0;
		virtual void SetDepthClipEnable(bool bDepthClipEnable) = 0;
		virtual void SetScissorEnable(bool bScissorEnable) = 0;
		virtual void SetMultisampleEnable(bool bMultisampleEnable) = 0;
		virtual void SetAntialiasedLineEnable(bool bAntialiasedLineEnable) = 0;

		//**Sampler**//
		

	private:
		RasterizerState m_kRasterizerState;
		BlendState m_kBlendState;
		DepthStencilState m_kDepthStencilState;
	};

	SMART_POINTER(RenderState)
}