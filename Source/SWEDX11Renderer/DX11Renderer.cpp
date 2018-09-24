#include "SWERenderer/DX11Renderer/DX11Renderer.h"
#include "SWERenderer/DX11Renderer/DX11RenderTarget.h"
#include "SWERenderer/DX11Renderer/DX11DepthStencilBuffer.h"
#include "SWERenderer/DX11Renderer/DX11DepthStencilBuffer.h"
#include "SWERenderer/DX11Renderer/DX11RenderTargetGroup.h"
#include "SWERenderer/DX11Renderer/DX11RendererUtility.h"

using namespace SWE;

DX11Renderer* DX11Renderer::m_pDX11Renderer = nullptr;

DX11Renderer* SWE::DX11Renderer::Create(RendererDesc renderDesc, HWND hwnd)
{
	if (m_pDX11Renderer == nullptr)
	{
		m_pDX11Renderer = new DX11Renderer;
		if (m_pDX11Renderer)
		{
			m_pDX11Renderer->Init(renderDesc, hwnd);
			return m_pDX11Renderer;
		}
		return nullptr;
	}
	else
	{
		return m_pDX11Renderer;
	}
}

DX11Renderer* SWE::DX11Renderer::Get()
{
	return m_pDX11Renderer;
}

SWE::DX11Renderer::DX11Renderer()
{
	ZeroMemory(&m_kSwapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
}

SWE::DX11Renderer::~DX11Renderer()
{

}

void SWE::DX11Renderer::Init(RendererDesc renderDesc, HWND hwnd)
{
	m_kSwapChainDesc.BufferCount = 1;
	m_kSwapChainDesc.BufferDesc.Width = renderDesc.screenWidth;
	m_kSwapChainDesc.BufferDesc.Height = renderDesc.screenHeight;
	DXGI_FORMAT colorBufferFmt = DXGI_FORMAT_UNKNOWN;
	if (renderDesc.redBits == 8 & renderDesc.redBits == renderDesc.blueBits && renderDesc.redBits == renderDesc.greenBits &&  renderDesc.redBits == renderDesc.alphaBits)
	{
		colorBufferFmt = DXGI_FORMAT_R8G8B8A8_UNORM;
	}
	m_kSwapChainDesc.BufferDesc.Format = colorBufferFmt;
	DXGI_RATIONAL refreshRate;
	refreshRate.Numerator = 60;
	refreshRate.Denominator = 1;
	m_kSwapChainDesc.BufferDesc.RefreshRate = refreshRate;
	m_kSwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	m_kSwapChainDesc.OutputWindow = hwnd;
	m_kSwapChainDesc.SampleDesc.Count = renderDesc.msaaSamples;
	m_kSwapChainDesc.SampleDesc.Quality = 0;//这里后边还要看下怎么设置
	m_kSwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	m_kSwapChainDesc.Windowed = !renderDesc.IsFullScreen;

	UINT createDeviceFlags = 0;
#if _DEBUG
	createDeviceFlags = D3D11_CREATE_DEVICE_DEBUG;
#endif

	// These are the feature levels that we will accept.
	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_2,
		D3D_FEATURE_LEVEL_9_1
	};

	IDXGISwapChain* pSwapChain = m_spSwapChain.get();
	ID3D11Device* pDevice = m_spDevice.get();
	ID3D11DeviceContext* pDeviceContext = m_spDeviceContext.get();
	HRESULT result = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, featureLevels, sizeof(featureLevels) / sizeof(D3D_FEATURE_LEVEL),
		D3D11_SDK_VERSION, &m_kSwapChainDesc, &pSwapChain, &pDevice, &m_eFeatureLevel, &pDeviceContext);
	
	HRESULT_ASSERT(result);

	//初始化backbuffer
	ID3D11Texture2D* backBuffer;
	result = m_spSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer);
	HRESULT_ASSERT(result);

	DX11RenderTarget* pkRT = new DX11RenderTarget(backBuffer);
	DX11DepthStencilBuffer* pkDS = new DX11DepthStencilBuffer(renderDesc.screenWidth, renderDesc.screenHeight);
	m_pkRenderTargetGroup = new DX11RenderTargetGroup();
	m_pkRenderTargetGroup->SetRT(pkRT);
	m_pkRenderTargetGroup->SetDS(pkDS);

	SetRenderTargetGroup(m_pkRenderTargetGroup);
}

void SWE::DX11Renderer::SetRenderTargetGroup(DX11RenderTargetGroup* pkRTG)
{
	if (m_spDeviceContext)
	{
		RenderTarget** ppkRenderTarget = pkRTG->GetRenderTargets();
		ID3D11RenderTargetView** ppRTVs = new ID3D11RenderTargetView*[pkRTG->GetRTCount()];
		for (size_t i = 0; i < pkRTG->GetRTCount(); i++)
		{
			ppkRTVs[i] = ((D3D11RenderTarget*)ppkRenderTarget[i])->GetRenderTargetView();
		}
		ID3D11DepthStencilView* pDepthStencilView = nullptr;
		if (pkRTG->GetDepthStencil())
		{
			pDepthStencilView = pkRTG->GetDepthStencil()->GetDepthStencilView();
		}

		m_spDeviceContext->OMSetRenderTargets(pkRTG->GetRTCount(), ppkRTVs, pDepthStencilView);
	}
}