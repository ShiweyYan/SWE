#pragma once
#include "SWERenderer/Renderer/SWERenderer.h"
#include "SWESystem/Object.h"

namespace SWE
{
	class SWERenderer_API Texture : public Object
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

		Texture(ENUM_TEXTURE_TYPE type, unsigned int sampleCount, unsigned int sampleQuality);
		virtual ~Texture();

		unsigned int ArraySize() const { return m_uiArraySize; }

		unsigned int SampleCount() const { return m_uiSampleCount; }

		unsigned int SampleQuality() const { return m_uiSampleQuality; }

		ENUM_TEXTURE_TYPE GetTextureType() const { return m_eTextureType; }

		unsigned int NumMipMaps() const { return m_uiMipMapsNumbers; }

		virtual unsigned int Width(unsigned int mipMapLevel) = 0;
		virtual unsigned int Height(unsigned int mipMapLevel) = 0;

	protected:
		ENUM_TEXTURE_TYPE m_eTextureType;

		unsigned int m_uiMipMapsNumbers;

		//采样数量和质量
		unsigned int m_uiSampleCount;
		unsigned int m_uiSampleQuality;

		//纹理数组大小
		unsigned int m_uiArraySize;
	};

	SMART_POINTER(Texture)
}