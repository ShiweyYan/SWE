#pragma once
#include "SWESystem/Object.h"
#include "SWECore/Renderer/Texture.h"
#include "SWEDX11Renderer/DX11TypeDefine.h"
#include "SWEDX11Renderer/SWEDX11Renderer.h"

namespace SWE
{
	class SWEDX11_API DX11Texture : public Texture
	{
		DECLEAR_RTTI
	public:
		DX11Texture(ENUM_TEXTURE_TYPE type, const TextureDesc& textureDesc);
		virtual ~DX11Texture();

		ID3D11Resource* GetResource() { return m_spD3d11Resource.get(); }

		virtual uint32_t Width(uint32_t mipMapLevel = 0);
		virtual uint32_t Height(uint32_t mipMapLevel = 0);
		virtual uint32_t Depth(uint32_t mipMapLevel = 0);
		
		virtual D3D11_TEXTURE2D_DESC FillTexture2DDesc();
		virtual bool CreateGPUTexture();

	protected:
		D3D11_USAGE m_eUsage;
		D3D11_BIND_FLAG m_eBindFlag;
		D3D11_CPU_ACCESS_FLAG m_eCPUAccessFlag;
		D3D11_RESOURCE_MISC_FLAG m_eResourceMiscFlag;

		ID3D11ResourcePtr m_spD3d11Resource;
		ID3D11RenderTargetViewPtr m_spRTV;
		ID3D11ShaderResourceViewPtr m_spSRV;
		ID3D11DepthStencilViewPtr m_spDSV;
	};

	class SWEDX11_API DX11Texture2D :public DX11Texture
	{
		DECLEAR_RTTI
	public:
		DX11Texture2D(const TextureDesc& textureDesc);
		~DX11Texture2D();

		virtual D3D11_TEXTURE2D_DESC FillTexture2DDesc();
		virtual bool CreateGPUTexture();

		virtual uint32_t Width(uint32_t mipMapLevel = 0);
		virtual uint32_t Height(uint32_t mipMapLevel = 0);

	private:
		uint32_t m_uiWidth;
		uint32_t m_uiHeight;
	};

	SMART_POINTER(DX11Texture)
	SMART_POINTER(DX11Texture2D)
}