#include "stdafx.h"
#include "Function_Tool.h"

const int LoopNum = 1000;

ID3D11Device* gpDevice;
ID3D11DeviceContext* gpDeviceContext;

void CreateDevice();

int main(){
	CreateDevice(); 

	CStopWatch stopWatch;

	cout << "-- VS Shader State Set --" << endl;
	stopWatch.BeginTimer();
	for(int i=0 ; i<LoopNum ; ++i){
		gpDeviceContext->VSSetShader(nullptr, NULL, NULL);
	}
	stopWatch.EndTimer();

	cout << "-- GS Shader State Set --" << endl;
	stopWatch.BeginTimer();
	for(int i=0 ; i<LoopNum ; ++i){
		gpDeviceContext->GSSetShader(nullptr, NULL, NULL);
	}
	stopWatch.EndTimer();

	cout << "-- HS Shader State Set --" << endl;
	stopWatch.BeginTimer();
	for(int i=0 ; i<LoopNum ; ++i){
		gpDeviceContext->HSSetShader(nullptr, NULL, NULL);
	}
	stopWatch.EndTimer();

	cout << "-- DS Shader State Set --" << endl;
	stopWatch.BeginTimer();
	for(int i=0 ; i<LoopNum ; ++i){
		gpDeviceContext->DSSetShader(nullptr, NULL, NULL);
	}
	stopWatch.EndTimer();

	cout << "-- PS Shader State Set --" << endl;
	stopWatch.BeginTimer();
	for(int i=0 ; i<LoopNum ; ++i){
		gpDeviceContext->PSSetShader(nullptr, NULL, NULL);
	}
	stopWatch.EndTimer();

	cout << "-- CS Shader State Set --" << endl;
	stopWatch.BeginTimer();
	for(int i=0 ; i<LoopNum ; ++i){
		gpDeviceContext->CSSetShader(nullptr, NULL, NULL);
	}
	stopWatch.EndTimer();
} 

//libfbxsdk-md.lib
//libfbxsdk.lib

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