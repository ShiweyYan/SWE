#pragma once
#include "SWERenderer/DX11Renderer/DX11TypeDefine.h"
#include "SWERenderer/Renderer/SWERenderer.h"

namespace SWE
{
	class SWERenderer_API DX11DepthStencilBuffer
	{
	public:
		DX11DepthStencilBuffer();
		explicit DX11DepthStencilBuffer(ID3D11Texture2D* pTex2D);
		DX11DepthStencilBuffer(UINT width, UINT height, DXGI_FORMAT format = DXGI_FORMAT_D24_UNORM_S8_UINT, /*D3D11_RESOURCE_MISC_FLAG*/UINT miscFlag = 0);
		virtual ~DX11DepthStencilBuffer();

		//����������޲εĹ��캯��,����Ҫ�ֶ����ó�ʼ��
		void Init(UINT width, UINT height, DXGI_FORMAT format = DXGI_FORMAT_D24_UNORM_S8_UINT, /*D3D11_RESOURCE_MISC_FLAG*/UINT miscFlag = 0);

		ID3D11DepthStencilView* GetDepthStencilView() const { return m_spDSV.get(); }
	private:
		ID3D11Texture2DPtr m_spDepthStencilBuffer;
		ID3D11DepthStencilViewPtr m_spDSV;
	};
}