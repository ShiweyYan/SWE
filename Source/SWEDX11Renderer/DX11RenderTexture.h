#pragma once
#include "SWERenderer/Renderer/SWERenderer.h"
#include "SWERenderer/DX11Renderer/DX11TypeDefine.h"
#include "SWERenderer/Renderer/IRenderTexture.h"

namespace SWE
{
	class SWERenderer_API DX11RenderTexture :public IRenderTexture
	{
		DECLEAR_RTTI
	public:
		DX11RenderTexture();
		explicit DX11RenderTexture(ID3D11Texture2D* pTexture);
		DX11RenderTexture(unsigned int width, unsigned int height, DXGI_FORMAT format, /*D3D11_RESOURCE_MISC_FLAG*/unsigned int miscFlag = 0);
		virtual ~DX11RenderTexture();

		void Init(unsigned int width, unsigned int height, DXGI_FORMAT format, /*D3D11_RESOURCE_MISC_FLAG*/unsigned int miscFlag = 0);

		ID3D11RenderTargetView* GetRenderTargetView() const { return m_spRTV.get(); }

	private:
		ID3D11Texture2DPtr m_spRTBuffer;
		ID3D11RenderTargetViewPtr m_spRTV;
	};

	SMART_POINTER(DX11RenderTexture)
}