#include "SWEDX11Renderer/DX11RenderView.h"
#include "SWEDX11Renderer/DX11Renderer.h"
#include "SWEDX11Renderer/DX11Texture.h"
#include "SWEDX11Renderer/DX11RendererUtility.h"

using namespace SWE;

IMPLEMENT_RTTI_1(DX11RenderView, RenderView)

SWE::DX11RenderView::DX11RenderView(Texture* pTexture):
	RenderView(pTexture)
{

}

SWE::ID3D11RenderTargetViewPtr SWE::DX11RenderView::GetRenderTargetView()
{
	if (m_spRenderTargetView == nullptr)
	{
		DX11Texture* pTexture = DYNAMIC_CAST(DX11Texture, m_spTexture);
		if (pTexture)
		{
			D3D11_RENDER_TARGET_VIEW_DESC rtvDesc = FillRenderTargetViewDesc();
			ID3D11Resource *pResource = pTexture->GetResource();
			ID3D11RenderTargetView *pRenderTargetView = { nullptr };
			HRESULT hResult = DX11Renderer::Get()->GetDevice()->CreateRenderTargetView(pResource, &rtvDesc, &pRenderTargetView);
			if (FAILED(hResult))
			{
				return nullptr;
			}
			m_spShaderResourceView = MakeCOMPtr(pRenderTargetView);

			// Generate mipmaps for this texture.
			//GetD3D11()->GetDeviceContextPtr()->GenerateMips(pShaderResourceView);
		}
		else
		{
			return nullptr;
		}
	}

	return m_spRenderTargetView;
}

SWE::ID3D11DepthStencilViewPtr SWE::DX11RenderView::GetDepthStencilView()
{
	if (m_spDepthStencilView == nullptr)
	{
		DX11Texture* pTexture = DYNAMIC_CAST(DX11Texture, m_spTexture);
		if (pTexture)
		{
			D3D11_DEPTH_STENCIL_VIEW_DESC dsvDesc = FillDepthStencilViewDesc();
			ID3D11Resource *pResource = pTexture->GetResource();
			ID3D11DepthStencilView *pDepthStenciltView = { nullptr };
			HRESULT hResult = DX11Renderer::Get()->GetDevice()->CreateDepthStencilView(pResource, &dsvDesc, &pDepthStenciltView);
			if (FAILED(hResult))
			{
				return nullptr;
			}
			m_spDepthStencilView = MakeCOMPtr(pDepthStenciltView);

			// Generate mipmaps for this texture.
			//GetD3D11()->GetDeviceContextPtr()->GenerateMips(pShaderResourceView);
		}
		else
		{
			return nullptr;
		}
	}

	return m_spDepthStencilView;
}

SWE::ID3D11ShaderResourceViewPtr SWE::DX11RenderView::GetShaderResourceView()
{
	if (m_spShaderResourceView == nullptr)
	{
		DX11Texture* pTexture = DYNAMIC_CAST(DX11Texture, m_spTexture);
		if (pTexture)
		{
			D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc = FillShaderResourceViewDesc();
			ID3D11Resource *pResource = pTexture->GetResource();
			ID3D11ShaderResourceView *pShaderResourceView = { nullptr };
			HRESULT hResult = DX11Renderer::Get()->GetDevice()->CreateShaderResourceView(pResource, &srvDesc, &pShaderResourceView);
			if (FAILED(hResult))
			{
				return nullptr;
			}
			m_spShaderResourceView = MakeCOMPtr(pShaderResourceView);

			// Generate mipmaps for this texture.
			//GetD3D11()->GetDeviceContextPtr()->GenerateMips(pShaderResourceView);
		}
		else
		{
			return nullptr;
		}
	}

	return m_spShaderResourceView;
}

D3D11_SHADER_RESOURCE_VIEW_DESC SWE::DX11RenderView::FillShaderResourceViewDesc()
{
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;

	srvDesc.Format = (DXGI_FORMAT)(m_spTexture->GetTextureFormat());
	if (m_spTexture->GetTextureType() == Texture::ENUM_TEXTURE_TYPE::ETT_2D)
	{
		srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	}
	else//后续补充
	{
	}
	
	srvDesc.Texture2D.MostDetailedMip = 0;
	srvDesc.Texture2D.MipLevels = -1;

	return srvDesc;
}

D3D11_RENDER_TARGET_VIEW_DESC SWE::DX11RenderView::FillRenderTargetViewDesc()
{
	D3D11_RENDER_TARGET_VIEW_DESC rtvDesc;

	rtvDesc.Format = (DXGI_FORMAT)(m_spTexture->GetTextureFormat());
	if (m_spTexture->GetTextureType() == Texture::ENUM_TEXTURE_TYPE::ETT_2D)
	{
		rtvDesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
		rtvDesc.Texture2D.MipSlice = 0;
	}
	else//后续补充
	{
	}

	return rtvDesc;
}

D3D11_DEPTH_STENCIL_VIEW_DESC SWE::DX11RenderView::FillDepthStencilViewDesc()
{
	D3D11_DEPTH_STENCIL_VIEW_DESC dsvDesc;

	dsvDesc.Format = (DXGI_FORMAT)(m_spTexture->GetTextureFormat());
	dsvDesc.Flags = 0;//0表示非只读,其他情况以后再拓展
	if (m_spTexture->GetTextureType() == Texture::ENUM_TEXTURE_TYPE::ETT_2D)
	{
		dsvDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		dsvDesc.Texture2D.MipSlice = 0;
	}
	else//后续补充
	{
	}

	return dsvDesc;
}
