#include "stdafx.h"
#include "Function_Tool.h"

const UINT LOOP_NUM = 1'000'000;
//1'000'000 cost : 0.144806 [0.144806]

//	0.012
//	0.0018

ID3D11Device* gpDevice;
ID3D11DeviceContext* gpDeviceContext;

enum class BRUSH_COLOR : int{
	WHITE,
	BLACK,
	RED,
	GREEN,
	BLUE,
	MAGENTA,
	YELLOW,
	CYAN,
};

void CreateDevice();

int main(){

	CStopWatch watch;
	
	CreateDevice();

	ID2D1Factory		*pD2DFactory;
	ID2D1RenderTarget*	pRenderTarget;

	D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pD2DFactory);

	ID3D11Texture2D *pTexture;
	D3D11_TEXTURE2D_DESC d3dTextureDesc;
	ZeroMemory(&d3dTextureDesc,sizeof(D3D11_TEXTURE2D_DESC));
	d3dTextureDesc.Width = 100;
	d3dTextureDesc.Height = 100;
	d3dTextureDesc.MipLevels = 1;
	d3dTextureDesc.ArraySize = 1;
	d3dTextureDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	d3dTextureDesc.SampleDesc.Count = 1;
	d3dTextureDesc.SampleDesc.Quality = 0;
	d3dTextureDesc.Usage = D3D11_USAGE_DEFAULT;
	d3dTextureDesc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
	d3dTextureDesc.CPUAccessFlags = 0;
	d3dTextureDesc.MiscFlags = 0;
	gpDevice->CreateTexture2D(&d3dTextureDesc, nullptr, &pTexture);

	IDXGISurface *pDxgiSurface = NULL;
	pTexture->QueryInterface(&pDxgiSurface);


	D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
													D2D1_RENDER_TARGET_TYPE_DEFAULT,
													D2D1::PixelFormat(DXGI_FORMAT_UNKNOWN,D2D1_ALPHA_MODE_PREMULTIPLIED),
													96,
													96
												);
	pD2DFactory->CreateDxgiSurfaceRenderTarget(pDxgiSurface,&props,&pRenderTarget);

	ID2D1SolidColorBrush* D2DBrush;
	pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(1,1,1,0.5),&D2DBrush);


	//None						0.001769
	//int						0.001793
	//float						0.002138
	//XMFLOAT4					0.022279
	//XMVECTOR					0.025223
	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
	//	int num = int(5);
		float num = float(5);
	//	XMVECTOR vec = XMVECTOR{1, 2, 3, 5};
	//	XMFLOAT4 vec2 = XMFLOAT4(1, 1, 1, 1);

	//	D2DBrush->SetColor(D2D1_COLOR_F{1, 1, 1, 1});
	//	D2DBrush->SetColor(D2D1::ColorF(1,1,1,1));
	//	int num = static_cast<int>(BRUSH_COLOR::BLACK);
	//	int num = (int)BRUSH_COLOR::BLACK;
	//	int num = 10;
//		pRenderTarget->BeginDraw();
//		pRenderTarget->EndDraw();
	}
	watch.EndTimer();

} 

void CreateDevice(){
		UINT dwCreateDeviceFlags = 0;
#ifdef _DEBUG
		dwCreateDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
		dwCreateDeviceFlags |= D3D11_CREATE_DEVICE_BGRA_SUPPORT;

	D3D_DRIVER_TYPE DriverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE
	};
	UINT nDriverTypes = sizeof(DriverTypes) / sizeof(D3D_DRIVER_TYPE);

	D3D_FEATURE_LEVEL pFeatureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0
	};
	UINT nFeatureLevels = sizeof(pFeatureLevels) / sizeof(D3D_FEATURE_LEVEL);

	D3D_DRIVER_TYPE nDriverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL nFeatureLevel = D3D_FEATURE_LEVEL_11_0;
	HRESULT hResult = S_OK;

	for (UINT i = 0; i < nDriverTypes; i++)
	{
		nDriverType = DriverTypes[i];
		if (SUCCEEDED(hResult = D3D11CreateDevice(NULL, nDriverType, NULL, dwCreateDeviceFlags, pFeatureLevels, nFeatureLevels, D3D11_SDK_VERSION, &gpDevice, &nFeatureLevel, &gpDeviceContext))) break;
	}

	gpDevice->CreateDeferredContext(0, &gpDeviceContext);
}