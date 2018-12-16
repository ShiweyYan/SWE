#pragma once
#include "SWEDX11Renderer/SWEDX11Renderer.h"
#include "SWEDX11Renderer/DX11TypeDefine.h"
#include "SWECore/Renderer/RenderView.h"

namespace SWE
{
	class SWEDX11_API DX11RenderView : public RenderView
	{
		DECLEAR_RTTI
	public:
		DX11RenderView(Texture* pTexture);
		virtual ~DX11RenderView() = default;

		ID3D11RenderTargetViewPtr GetRenderTargetView();
		ID3D11DepthStencilViewPtr GetDepthStencilView();
		ID3D11ShaderResourceViewPtr GetShaderResourceView();

		D3D11_SHADER_RESOURCE_VIEW_DESC FillShaderResourceViewDesc();
		D3D11_RENDER_TARGET_VIEW_DESC FillRenderTargetViewDesc();
		D3D11_DEPTH_STENCIL_VIEW_DESC FillDepthStencilViewDesc();

	private:
		ID3D11RenderTargetViewPtr m_spRenderTargetView;
		ID3D11DepthStencilViewPtr m_spDepthStencilView;
		ID3D11ShaderResourceViewPtr m_spShaderResourceView;
	};

	SMART_POINTER(DX11RenderView)
}