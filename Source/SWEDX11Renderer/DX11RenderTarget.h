#pragma once
#include "SWERenderer/DX11Renderer/DX11TypeDefine.h"
#include "SWERenderer/Renderer/IRenderTarget.h"
#include "SWERenderer/Renderer/SWERenderer.h";
#include "SWERenderer/DX11Renderer/DX11RenderTexture.h"

namespace SWE
{
	class DX11DepthStencilBuffer;

	class SWERenderer_API DX11RenderTarget : public IRenderTarget
	{
		DECLEAR_RTTI
	public:
		DX11RenderTarget();
		DX11RenderTarget(unsigned int width, unsigned int height, DXGI_FORMAT RTFormat, DXGI_FORMAT DSFormat, /*D3D11_RESOURCE_MISC_FLAG*/UINT RTMiscFlag = 0, /*D3D11_RESOURCE_MISC_FLAG*/UINT DSMiscFlag = 0, UINT numberRT = 1);
		virtual ~DX11RenderTarget();

		void Init(unsigned int width, unsigned int height, DXGI_FORMAT RTFormat, DXGI_FORMAT DSFormat, /*D3D11_RESOURCE_MISC_FLAG*/UINT RTMiscFlag = 0, /*D3D11_RESOURCE_MISC_FLAG*/UINT DSMiscFlag = 0, UINT numberRT = 1);
		void SetRT(DX11RenderTexture* pkRenderTarget, UINT index);
		void SetDS(DX11DepthStencilBuffer* pkDepthStencilBuffer);

	private:
		unsigned short m_uiRenderTargetNum;
		DX11RenderTexturePtr* m_ppRenderTextures;
		DX11DepthStencilBuffer* m_pDepthStencilBuffer;
	};

	SMART_POINTER(DX11RenderTarget)
}