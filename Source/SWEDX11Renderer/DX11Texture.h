#pragma once
#include "SWESystem/Object.h"
#include "SWECore/Renderer/Texture.h"
#include "SWEDX11Renderer/DX11TypeDefine.h"
#include "SWEDX11Renderer/SWEDX11Renderer.h"

namespace SWE
{
	class DX11Texture : public Texture
	{
		DECLEAR_RTTI
	public:
		DX11Texture(ENUM_TEXTURE_TYPE type, unsigned short sampleCount, unsigned short sampleQuality);
		virtual ~DX11Texture();

		ID3D11Resource* GetResource() { return m_spD3d11Resource.get(); }

		virtual uint32_t Width(uint32_t mipMapLevel = 0);
		virtual uint32_t Height(uint32_t mipMapLevel = 0);
		virtual uint32_t Depth(uint32_t mipMapLevel = 0);

	protected:
		ID3D11Device * m_pDevice;
		ID3D11DeviceContext*	m_pDeviceContext;

		ID3D11ResourcePtr m_spD3d11Resource;
		ID3D11RenderTargetViewPtr m_spRTV;
		ID3D11ShaderResourceViewPtr m_spSRV;
		ID3D11DepthStencilViewPtr m_spDSV;
	};

	class DX11Texture2D :public DX11Texture
	{
		DECLEAR_RTTI
	public:
		DX11Texture2D(unsigned short sampleCount, unsigned short sampleQuality);
		DX11Texture2D(ID3D11Texture2DPtr texture2d);
		//bool CreateTexture2D(UINT width, UINT height, DXGI_FORMAT format, /*D3D11_RESOURCE_MISC_FLAG*/UINT miscFlag = 0);
		~DX11Texture2D();

		virtual ENUM_TEXTURE_TYPE GetTextureType() const { return m_eTextureType; }
		ID3D11Texture2DPtr GetTexure2D() const { return texture2D_; }
		//ID3D11ShaderResourceViewPtr GetTexture2DView();
		virtual uint32_t Width(uint32_t mipMapLevel = 0);
		virtual uint32_t Height(uint32_t mipMapLevel = 0);
		DXGI_FORMAT GetTextureFormat();

	private:
		//unsigned char* m_pRawData{ nullptr };
		ID3D11Texture2DPtr m_spTexture2D{ nullptr };
		ID3D11ShaderResourceViewPtr m_spSRV{ nullptr };

		uint32_t m_uiWidth;
		uint32_t m_uiHeight;
	};

	SMART_POINTER(DX11Texture)
	SMART_POINTER(DX11Texture2D)
}