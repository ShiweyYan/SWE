#pragma once
#include "SWESystem/Object.h"
#include "SWERenderer/Renderer/Texture.h"
#include "SWERenderer/DX11Renderer/DX11TypeDefine.h"

namespace SWE
{
	class DX11Texture : public Texture
	{
	public:
		DX11Texture(ENUM_TEXTURE_TYPE type, unsigned short sampleCount, unsigned short sampleQuality);
		virtual ~DX11Texture();

		ID3D11Resource* GetResource() { return m_spD3d11Resource.get(); }

	protected:
		ID3D11Device * m_pDevice;
		ID3D11DeviceContext*		m_pDeviceContext;

		ID3D11ResourcePtr m_spD3d11Resource;
	};

	class DX11Texture2D :public DX11Texture
	{
	public:
		DX11Texture2D(unsigned short sampleCount, unsigned short sampleQuality);
		DX11Texture2D(ID3D11Texture2DPtr texture2d);
		bool CreateTexture2D(UINT width, UINT height, DXGI_FORMAT format, /*D3D11_RESOURCE_MISC_FLAG*/UINT miscFlag = 0);
		~DX11Texture2D();

		ID3D11Texture2DPtr GetTexure2D() const { return texture2D_; }
		ID3D11ShaderResourceViewPtr GetTexture2DView();
		//virtual UINT Width(UINT mipMapLevel);
		//virtual UINT Height(UINT mipMapLevel);
		DXGI_FORMAT GetTextureFormat();

	private:
		unsigned char* m_pRawData{ nullptr };
		ID3D11Texture2DPtr m_spTexture2D{ nullptr };
		ID3D11ShaderResourceViewPtr m_spSRV{ nullptr };
	};
}