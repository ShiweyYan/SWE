#pragma once
#include "SWERenderer/DX11Renderer/DX11TypeDefine.h"
#include "SWERenderer/Renderer/SWERenderer.h"
#include "SWERenderer/Renderer/RendererDesc.h"
#include "SWERenderer/Renderer/IRenderer.h"

namespace SWE
{
	class DX11RenderTargetGroup;

	class SWERenderer_API DX11Renderer : public IRenderer
	{
		DECLEAR_RTTI
	public:
		static DX11Renderer* Create(RendererDesc renderDesc, HWND hwnd);
		static DX11Renderer* Get();
		virtual ~DX11Renderer();

		virtual RENDERER_TYPE GetType()const { return RT_D3D11; }

		ID3D11Device* GetDevice() const { return m_spDevice.get(); }
		ID3D11DeviceContext* GetDeviceContext() const { return m_spDeviceContext.get(); }

		void SetRenderTargetGroup(DX11RenderTargetGroup* pkRTG);

	private:
		DX11Renderer();
		void Init(RendererDesc renderDesc, HWND hwnd);

	private:
		static DX11Renderer* m_pDX11Renderer;
		D3D_FEATURE_LEVEL m_eFeatureLevel;

		//设备和设备上下文
		ID3D11DevicePtr m_spDevice;
		ID3D11DeviceContextPtr m_spDeviceContext;

		//交换链及其描述
		IDXGISwapChainPtr m_spSwapChain;
		DXGI_SWAP_CHAIN_DESC m_kSwapChainDesc;

		DX11RenderTargetGroup* m_pkRenderTargetGroup;
	};

	SMART_POINTER(DX11Renderer)
};