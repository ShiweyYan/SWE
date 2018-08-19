#include "SWERenderer/DX11Renderer/DX11RenderTexture.h"
#include "SWERenderer/DX11Renderer/DX11RendererUtility.h"
#include "SWERenderer/DX11Renderer/DX11Renderer.h"

using namespace SWE;

IMPLEMENT_RTTI_1(DX11RenderTexture, IRenderTexture)

SWE::DX11RenderTexture::DX11RenderTexture() : m_spRTBuffer(nullptr), m_spRTV(nullptr)
{

}

SWE::DX11RenderTexture::DX11RenderTexture(ID3D11Texture2D* pTexture)
{
	if (pTexture)
	{
		m_spRTBuffer = MakeCOMPtr(pTexture);
		DX11Renderer* pRenderer = DX11Renderer::();
		if (pRenderer && pRenderer->GetDevice() && m_spRTBuffer)
		{
			ID3D11RenderTargetView* pRTV(nullptr);
			HRESULT hr = pRenderer->GetDevice()->CreateRenderTargetView(pTexture, nullptr, &pRTV);
			HRESULT_ASSERT(hr);
			m_spRTV = MakeCOMPtr(pRTV);
		}
	}
}

SWE::DX11RenderTexture::DX11RenderTexture(unsigned int width, unsigned int height, DXGI_FORMAT format, /*D3D11_RESOURCE_MISC_FLAG*/unsigned int miscFlag /*= 0*/)
{
	Init(width, height, format, miscFlag);
}

SWE::DX11RenderTexture::~DX11RenderTexture()
{
	m_spRTBuffer = nullptr;
	m_spRTV = nullptr;
}

void SWE::DX11RenderTexture::Init(unsigned int width, unsigned int height, DXGI_FORMAT format, /*D3D11_RESOURCE_MISC_FLAG*/unsigned int miscFlag /*= 0*/)
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
			texture2DDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_RENDER_TARGET;
			texture2DDesc.CPUAccessFlags = 0;
			texture2DDesc.MiscFlags = miscFlag;

			ID3D11Texture2D  *pTexture2D;
			HRESULT hr = pDevice->CreateTexture2D(&texture2DDesc, nullptr, &pTexture2D);

			if (FAILED(hr))
			{
				assert(false);
				return;
			}
			m_spRTBuffer = MakeCOMPtr(pTexture2D);

			if (m_spRTBuffer && m_spRTV == nullptr)
			{
				ID3D11RenderTargetView* pRTV;
				hr = pDevice->CreateRenderTargetView(pTexture2D, nullptr, &pRTV);
				if (FAILED(hr))
				{
					assert(false);
					return;
				}
				m_spRTV = MakeCOMPtr(pRTV);
			}
		}
	}
}
