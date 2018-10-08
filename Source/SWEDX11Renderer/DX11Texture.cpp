#include "SWEDX11Renderer/DX11Texture.h"
#include "SWESystem/Utility.h"

using namespace SWE;

IMPLEMENT_RTTI_1(DX11Texture, Texture)

SWE::DX11Texture::~DX11Texture()
{
	m_pDevice = nullptr;
	m_pDeviceContext = nullptr;
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

SWE::DX11Texture2D::~DX11Texture2D()
{
	//SafeDelete(m_pRawData);
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
