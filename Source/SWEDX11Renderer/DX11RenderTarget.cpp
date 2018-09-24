#include "SWERenderer/DX11Renderer/DX11RenderTexture.h"
#include "SWERenderer/DX11Renderer/DX11RendererUtility.h"
#include "SWERenderer/DX11Renderer/DX11RenderTarget.h"
#include "SWERenderer/DX11Renderer/DX11DepthStencilBuffer.h"

using namespace SWE;

IMPLEMENT_RTTI_1(DX11RenderTarget, IRenderTarget)

SWE::DX11RenderTarget::DX11RenderTarget():
	m_uiRenderTargetNum(0),
	m_ppRenderTextures(nullptr),
	m_pDepthStencilBuffer(nullptr)
{

}

SWE::DX11RenderTarget::~DX11RenderTarget()
{
	//暂时先释放
	//todo : 用pool管理起来
	SafeDelete(m_pDepthStencilBuffer);
	SafeDeleteArray(m_ppRenderTextures);
	m_uiRenderTargetNum = 0;
}

void SWE::DX11RenderTarget::Init(unsigned int width, unsigned int height, DXGI_FORMAT RTFormat, DXGI_FORMAT DSFormat, /*D3D11_RESOURCE_MISC_FLAG*/UINT RTMiscFlag /*= 0*/, /*D3D11_RESOURCE_MISC_FLAG*/UINT DSMiscFlag /*= 0*/, UINT numberRT /*= 1*/)
{
	//现在这里创建
	//todo : 从pool里取
	if (numberRT < 1)
	{
		assert(false);
	}

	m_uiRenderTargetNum = numberRT;

	m_ppRenderTextures = new DX11RenderTexturePtr[numberRT];
	for (size_t i = 0; i < numberRT; i++)
	{
		m_ppRenderTextures[i] = new DX11RenderTexture(width, height, RTFormat, RTMiscFlag);
	}

	m_pDepthStencilBuffer = new DX11DepthStencilBuffer(width, height, DSFormat, DSMiscFlag);
}

void SWE::DX11RenderTarget::SetRT(DX11RenderTexture* pkRenderTarget, UINT index)
{
	if (index < m_uiRenderTargetNum)
	{
		m_ppRenderTextures[index] = nullptr;//todo : 归还RT
		m_ppRenderTextures[index] = pkRenderTarget;
	}
}

void SWE::DX11RenderTarget::SetDS(DX11DepthStencilBuffer* pkDepthStencilBuffer)
{
	SafeDelete(m_pDepthStencilBuffer);
	m_pDepthStencilBuffer = pkDepthStencilBuffer;
}

SWE::DX11RenderTarget::DX11RenderTarget(unsigned int width, unsigned int height, DXGI_FORMAT RTFormat, DXGI_FORMAT DSFormat, /*D3D11_RESOURCE_MISC_FLAG*/UINT RTMiscFlag /*= 0*/, /*D3D11_RESOURCE_MISC_FLAG*/UINT DSMiscFlag /*= 0*/, UINT numberRT /*= 1*/)
{
	Init(width, height, RTFormat, DSFormat, RTMiscFlag, DSMiscFlag, numberRT);
}
