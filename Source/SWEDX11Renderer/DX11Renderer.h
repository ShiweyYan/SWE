#pragma once
#include "SWEDX11Renderer/SWEDX11Renderer.h"
#include "SWEDX11Renderer/DX11TypeDefine.h"
#include "SWECore/Renderer/Renderer.h"
#include "SWECore/Renderer/RendererDesc.h"

namespace SWE
{
	class SWEDX11_API DX11Renderer : public Renderer
	{
		DECLEAR_RTTI
	public:
		virtual void Init(RendererDesc renderDesc);
		virtual RENDERER_TYPE GetType()const { return RT_D3D11; }

		ID3D11Device* GetDevice() const { return m_spDevice.get(); }
		ID3D11DeviceContext* GetDeviceContext() const { return m_spDeviceContext.get(); }

		void SetRenderTargetGroup(DX11RenderTargetGroup* pkRTG);

	protected:
		DX11Renderer();
		virtual ~DX11Renderer();

	private:
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