#include "stdafx.h"
#include "Function_Tool.h"

const int LoopNum = 1'000'000;
/*
-- Rasterizer State Set --
사용된 시간 : 0.006997 [0.0069966]

-- Blend State Set --
사용된 시간 : 0.007752 [0.0077516]

-- DepthStencil State Set --
사용된 시간 : 0.005384 [0.0053839]
*/


ID3D11Device* gpDevice;
ID3D11DeviceContext* gpDeviceContext;

void CreateDevice(){
		UINT dwCreateDeviceFlags = 0;
#ifdef _DEBUG
		dwCreateDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

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

int main(){
	CreateDevice();

	CStopWatch stopWatch;

	ID3D11RasterizerState* pRasteraizeState;
	D3D11_RASTERIZER_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_RASTERIZER_DESC));
	gpDevice->CreateRasterizerState(&desc, &pRasteraizeState);

	ID3D11BlendState* pBlendState;
	D3D11_BLEND_DESC blendDesc;
	ZeroMemory(&desc, sizeof(D3D11_BLEND_DESC));
	gpDevice->CreateBlendState(&blendDesc, &pBlendState);

	ID3D11DepthStencilState* pDepthStencilState;
	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
	ZeroMemory(&depthStencilDesc, sizeof(D3D11_DEPTH_STENCIL_DESC));
	gpDevice->CreateDepthStencilState(&depthStencilDesc, &pDepthStencilState);

	cout << "-- Rasterizer State Set --" << endl;
	stopWatch.BeginTimer();
	for(int i=0 ; i<LoopNum ; ++i){
		gpDeviceContext->RSSetState(pRasteraizeState);
	}
	stopWatch.EndTimer();

	cout << "-- Blend State Set --" << endl;
	stopWatch.BeginTimer();
	for(int i=0 ; i<LoopNum ; ++i){
		gpDeviceContext->OMSetBlendState(pBlendState, 0, 0);
	}
	stopWatch.EndTimer();

	cout << "-- DepthStencil State Set --" << endl;
	stopWatch.BeginTimer();
	for(int i=0 ; i<LoopNum ; ++i){
		gpDeviceContext->OMSetDepthStencilState(pDepthStencilState, 0);
	}
	stopWatch.EndTimer();
} 

//libfbxsdk-md.lib
//libfbxsdk.lib