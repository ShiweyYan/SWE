#include "SWECore/Renderer/Texture.h"

using namespace SWE;

IMPLEMENT_RTTI_1(Texture, Object)

SWE::Texture::Texture(ENUM_TEXTURE_TYPE type, const TextureDesc& textureDesc) :
	m_eTextureType(type),
	m_uiArraySize(textureDesc.arraySize),
	m_uiSampleCount(textureDesc.sampleCount),
	m_uiSampleQuality(textureDesc.sampleQuality),
	m_uiMipMapsNumbers(textureDesc.mipLevels),
	m_textureFormat(textureDesc.format)
{

}

SWE::Texture::~Texture()
{

}
