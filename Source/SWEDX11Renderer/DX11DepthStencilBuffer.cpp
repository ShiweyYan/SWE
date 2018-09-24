#include "SWERenderer/DX11Renderer/DX11DepthStencilBuffer.h"
#include"SWERenderer/DX11Renderer/DX11Renderer.h"
#include "SWERenderer/DX11Renderer/DX11RendererUtility.h"

using namespace SWE;

SWE::DX11DepthStencilBuffer::DX11DepthStencilBuffer():
	m_spDepthStencilBuffer(nullptr),
	m_spDSV(nullptr)
{

}

SWE::DX11DepthStencilBuffer::DX11DepthStencilBuffer(ID3D11Texture2D* pTex2D)
{
	if (pTex2D)
	{
		m_spDepthStencilBuffer = MakeCOMPtr(pTex2D);

		DX11Renderer* pRenderer = DX11Renderer::Get();
		if (pRenderer)
		{
			ID3D11Device* pDevice = pRenderer->GetDevice();
			if (m_spDepthStencilBuffer && m_spDSV == nullptr && pDevice)
			{
				ID3D11DepthStencilView* pDSV(nullptr);
				HRESULT  hr = pDevice->CreateDepthStencilView(pTex2D, nullptr, &pDSV);
				HRESULT_ASSERT(hr);
				m_spDSV = MakeCOMPtr(pDSV);
			}
		}
	}
}

SWE::DX11DepthStencilBuffer::~DX11DepthStencilBuffer()
{
	m_spDepthStencilBuffer = nullptr;
	m_spDSV = nullptr;
}

void SWE::DX11DepthStencilBuffer::Init(UINT width, UINT height, DXGI_FORMAT format /*= DXGI_FORMAT_D24_UNORM_S8_UINT*/, /*D3D11_RESOURCE_MISC_FLAG*/UINT miscFlag /*= 0*/)
{
	if (m_spDepthStencilBuffer == nullptr)
	{
		DX11Renderer* pRenderer = DX11Renderer::Get();
		if (pRenderer)
		{
			ID3D11Device* pDevice = pRenderer->GetDevice();
			if (pDevice)
			{
				D3D11_TEXTURE2D_DESC texture2DDesc;
				ZeroMemory(&texture2DDesc, sizeof(texture2DDesc));

				texture2DDesc.Width = width;
				texture2DDesc.Height = height;
				texture2DDesc.MipLevels = 0;
				texture2DDesc.ArraySize = 1;
				texture2DDesc.Format = format;
				texture2DDesc.SampleDesc.Count = 1;
				texture2DDesc.SampleDesc.Quality = 0;
				texture2DDesc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT;
				texture2DDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_DEPTH_STENCIL;
				texture2DDesc.CPUAccessFlags = 0;// No CPU access required.
				texture2DDesc.MiscFlags = miscFlag;

				ID3D11Texture2D  *pTexture2D(nullptr);
				HRESULT hr = pDevice->CreateTexture2D(&texture2DDesc, nullptr, &pTexture2D);

				HRESULT_ASSERT(hr);

				m_spDepthStencilBuffer = MakeCOMPtr(pTexture2D);

				if (m_spDepthStencilBuffer && m_spDSV == nullptr)
				{
					ID3D11DepthStencilView* pDSV(nullptr);
					hr = pDevice->CreateDepthStencilView(pTexture2D, nullptr, &pDSV);
					HRESULT_ASSERT(hr);
					m_spDSV = MakeCOMPtr(pDSV);
				}
			}
		}
	}
}

SWE::DX11DepthStencilBuffer::DX11DepthStencilBuffer(UINT width, UINT height, DXGI_FORMAT format /*= DXGI_FORMAT_D24_UNORM_S8_UINT*/, /*D3D11_RESOURCE_MISC_FLAG*/UINT miscFlag /*= 0*/)
{
	Init(width, height, format, miscFlag);
}
