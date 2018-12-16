#include "SWEDX11Renderer/DX11Texture.h"
#include "SWESystem/Utility.h"
#include "SWEDX11Renderer/DX11Renderer.h"
#include <D3D11.h>

using namespace SWE;

IMPLEMENT_RTTI_1(DX11Texture, Texture)
IMPLEMENT_RTTI_1(DX11Texture2D, DX11Texture)

//------------------------------DX11Texture begin------------------------------

SWE::DX11Texture::DX11Texture(ENUM_TEXTURE_TYPE type, const TextureDesc& textureDesc):
	Texture(type, textureDesc),
	m_eUsage((D3D11_USAGE)textureDesc.usage),
	m_eBindFlag((D3D11_BIND_FLAG)textureDesc.bindFlag),
	m_eCPUAccessFlag((D3D11_CPU_ACCESS_FLAG)textureDesc.cpuAccessFlags),
	m_eResourceMiscFlag((D3D11_RESOURCE_MISC_FLAG)textureDesc.miscFlag)
{

}

SWE::DX11Texture::~DX11Texture()
{

}

uint32_t SWE::DX11Texture::Width(uint32_t mipMapLevel /*= 0*/)
{
	assert(mipMapLevel < m_uiMipMapsNumbers);
	return 1;
}

uint32_t SWE::DX11Texture::Height(uint32_t mipMapLevel /*= 0*/)
{
	assert(mipMapLevel < m_uiMipMapsNumbers);
	return 1;
}

uint32_t SWE::DX11Texture::Depth(uint32_t mipMapLevel /*= 0*/)
{
	assert(mipMapLevel < m_uiMipMapsNumbers);
	return 1;
}

bool SWE::DX11Texture::CreateGPUTexture()
{
	return false;
}

D3D11_TEXTURE2D_DESC SWE::DX11Texture::FillTexture2DDesc()
{
	D3D11_TEXTURE2D_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	return desc;
}

//------------------------------DX11Texture end------------------------------

//------------------------------DX11Texture2D begin------------------------------

SWE::DX11Texture2D::DX11Texture2D(const TextureDesc& textureDesc):
	DX11Texture(ENUM_TEXTURE_TYPE::ETT_2D, textureDesc),
	m_uiWidth(textureDesc.width),
	m_uiHeight(textureDesc.height)
{
}

SWE::DX11Texture2D::~DX11Texture2D()
{

}

D3D11_TEXTURE2D_DESC SWE::DX11Texture2D::FillTexture2DDesc()
{
	D3D11_TEXTURE2D_DESC texture2DDesc;
	texture2DDesc.Width = m_uiWidth;
	texture2DDesc.Height = m_uiHeight;
	texture2DDesc.MipLevels = m_uiMipMapsNumbers;
	texture2DDesc.ArraySize = m_uiArraySize;
	texture2DDesc.Format = (::DXGI_FORMAT)m_textureFormat;
	texture2DDesc.SampleDesc.Count = m_uiSampleCount;
	texture2DDesc.SampleDesc.Quality = m_uiSampleQuality;
	texture2DDesc.Usage = m_eUsage;
	texture2DDesc.BindFlags = m_eBindFlag;
	texture2DDesc.CPUAccessFlags = m_eCPUAccessFlag;
	texture2DDesc.MiscFlags = m_eResourceMiscFlag;

	return texture2DDesc;
}

bool SWE::DX11Texture2D::CreateGPUTexture()
{
	D3D11_TEXTURE2D_DESC texture2DDesc = FillTexture2DDesc();

	ID3D11Texture2D* ptx = nullptr;
	if (DX11Renderer::Get() && DX11Renderer::Get()->GetDevice())
	{
		HRESULT result =  DX11Renderer::Get()->GetDevice()->CreateTexture2D(&texture2DDesc, nullptr, &ptx);
		if (FAILED(result))
		{
			return false;
		}
		m_spD3d11Resource = MakeCOMPtr(ptx);
		return true;
	}

	return false;
}

uint32_t SWE::DX11Texture2D::Width(uint32_t mipMapLevel /*= 0*/)
{
	assert(mipMapLevel < m_uiMipMapsNumbers);
	return m_uiWidth >> mipMapLevel;
}

uint32_t SWE::DX11Texture2D::Height(uint32_t mipMapLevel /*= 0*/)
{
	assert(mipMapLevel < m_uiMipMapsNumbers);
	return m_uiHeight >> mipMapLevel;
}

//------------------------------DX11Texture2D end------------------------------
