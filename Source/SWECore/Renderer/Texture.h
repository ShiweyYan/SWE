#pragma once
#include "SWECore/SWECore.h"
#include "SWESystem/Object.h"

namespace SWE
{
	class SWECORE_API Texture : public Object
	{
		DECLEAR_RTTI
	public:
		enum class ENUM_TEXTURE_TYPE
		{
			ETT_1D,
			ETT_2D,
			ETT_3D,
			ETT_CUBE,
		};

		Texture(ENUM_TEXTURE_TYPE type, uint32_t sampleCount, uint32_t sampleQuality);
		virtual ~Texture();

		uint32_t ArraySize() const { return m_uiArraySize; }

		uint32_t SampleCount() const { return m_uiSampleCount; }

		uint32_t SampleQuality() const { return m_uiSampleQuality; }

		virtual ENUM_TEXTURE_TYPE GetTextureType() const { return m_eTextureType; }

		uint32_t NumMipMaps() const { return m_uiMipMapsNumbers; }

		virtual uint32_t Width(uint32_t mipMapLevel = 0) = 0;
		virtual uint32_t Height(uint32_t mipMapLevel = 0) = 0;
		virtual uint32_t Depth(uint32_t mipMapLevel = 0) = 0;

	protected:
		ENUM_TEXTURE_TYPE m_eTextureType;

		uint32_t m_uiMipMapsNumbers;

		//采样数量和质量
		uint32_t m_uiSampleCount;
		uint32_t m_uiSampleQuality;

		//纹理数组大小
		uint32_t m_uiArraySize;
	};

	SMART_POINTER(Texture)
}