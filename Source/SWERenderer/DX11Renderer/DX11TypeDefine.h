#pragma once

#include <memory>
#include <d3d11.h>
//#include "fx11\d3dx11effect.h"
//#include "fx11\d3dxGlobal.h"

namespace SWE
{
	using IDXGIFactoryPtr = std::shared_ptr<IDXGIFactory>;
	using IDXGIAdapterPtr = std::shared_ptr<IDXGIAdapter>;
	using IDXGIOutputPtr = std::shared_ptr<IDXGIOutput>;

	using ID3D11DevicePtr = std::shared_ptr<ID3D11Device>;
	using ID3D11DeviceContextPtr = std::shared_ptr<ID3D11DeviceContext>;
	using IDXGISwapChainPtr = std::shared_ptr<IDXGISwapChain>;
	using ID3D11ClassLinkagePtr = std::shared_ptr<ID3D11ClassLinkage>;

	using ID3D11ResourcePtr = std::shared_ptr<ID3D11Resource>;

	using ID3D11Texture1DPtr = std::shared_ptr<ID3D11Texture1D>;
	using ID3D11Texture2DPtr = std::shared_ptr<ID3D11Texture2D>;
	using ID3D11Texture3DPtr = std::shared_ptr<ID3D11Texture3D>;

	using ID3D10ViewPtr = std::shared_ptr<ID3D10View>;
	using ID3D11RenderTargetViewPtr = std::shared_ptr<ID3D11RenderTargetView>;
	using ID3D11DepthStencilViewPtr = std::shared_ptr<ID3D11DepthStencilView>;
	using ID3D11ShaderResourceViewPtr = std::shared_ptr<ID3D11ShaderResourceView>;

	using ID3D11BlendStatePtr = std::shared_ptr<ID3D11BlendState>;
	using ID3D11DepthStencilStatePtr = std::shared_ptr<ID3D11DepthStencilState>;
	using ID3D11RasterizerStatePtr = std::shared_ptr<ID3D11RasterizerState>;

	using ID3D11InputLayoutPtr = std::shared_ptr<ID3D11InputLayout>;

	using ID3D11BufferPtr = std::shared_ptr<ID3D11Buffer>;

	//using ID3DX11EffectPtr = std::shared_ptr<ID3DX11Effect>;
	//using ID3DX11EffectTechniquePtr = std::shared_ptr<ID3DX11EffectTechnique>;
	//using ID3DX11EffectMatrixPtr = std::shared_ptr<ID3DX11EffectMatrixVariable>;
	//using ID3DX11EffectVectorPtr = std::shared_ptr<ID3DX11EffectVectorVariable>;
	//using ID3DX11EffectScalarPtr = std::shared_ptr<ID3DX11EffectScalarVariable>;
	//using ID3DX11EffectShaderResourcePtr = std::shared_ptr<ID3DX11EffectShaderResourceVariable>;
}