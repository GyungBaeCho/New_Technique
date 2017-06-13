#include "stdafx.h"
#include "Function_Tool.h"

const int LoopNum = 1000000;

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

struct SPointLight{
	D3DXVECTOR4		m_vPosition;
	float			m_fRange;
	D3DXVECTOR4		m_vColor;
	float			m_fSpecularPower;
	float			m_fPower;

};

struct CB_SONAR{
	D3DXVECTOR4		m_vPositionLen[10000000];
};

struct CB_LIGHT{
	UINT		m_nPointLightNum;
	SPointLight m_arrPointLight[10000];
};

int main(){
	CreateDevice();

	CStopWatch stopWatch;

	int arrSize = 1;
	cout << arrSize * sizeof(CB_LIGHT) << endl;

	CB_LIGHT *pLight = new CB_LIGHT;

	ID3D11Buffer* pcLight = nullptr;
	D3D11_BUFFER_DESC BufferDesc;
	ZeroMemory(&BufferDesc, sizeof(D3D11_BUFFER_DESC));
	BufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	BufferDesc.StructureByteStride = sizeof(CB_LIGHT);
	BufferDesc.ByteWidth = sizeof(CB_LIGHT) * 100;
	BufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	BufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	D3D11_SUBRESOURCE_DATA BufferData;
	ZeroMemory(&BufferData, sizeof(D3D11_SUBRESOURCE_DATA));
	BufferData.pSysMem = pLight;

	ID3D11Buffer *pBuffer = NULL;
//	HRESULT hr = gpDevice->CreateBuffer(&BufferDesc, &BufferData, &pBuffer);
	DXGetErrorString(gpDevice->CreateBuffer(&BufferDesc, &BufferData, &pBuffer));
	
	cout << "-- VS CB Set --" << endl;
	stopWatch.BeginTimer();
	for(int i=0 ; i<LoopNum ; ++i){
		gpDeviceContext->VSSetConstantBuffers(0, 1, &pcLight);
	}
	stopWatch.EndTimer();

	cout << "-- PS CB Set --" << endl;
	stopWatch.BeginTimer();
	for(int i=0 ; i<LoopNum ; ++i){
		gpDeviceContext->PSSetConstantBuffers(0, 1, &pcLight);
	}
	stopWatch.EndTimer();

	cout << "-- GS CB Set --" << endl;
	stopWatch.BeginTimer();
	for(int i=0 ; i<LoopNum ; ++i){
		gpDeviceContext->GSSetConstantBuffers(0, 1, &pcLight);
	}
	stopWatch.EndTimer();

	cout << "-- HS CB Set --" << endl;
	stopWatch.BeginTimer();
	for(int i=0 ; i<LoopNum ; ++i){
		gpDeviceContext->HSSetConstantBuffers(0, 1, &pcLight);
	}
	stopWatch.EndTimer();

	cout << "-- DS CB Set --" << endl;
	stopWatch.BeginTimer();
	for(int i=0 ; i<LoopNum ; ++i){
		gpDeviceContext->DSSetConstantBuffers(0, 1, &pcLight);
	}
	stopWatch.EndTimer();

	cout << "-- CS CB Set --" << endl;
	stopWatch.BeginTimer();
	for(int i=0 ; i<LoopNum ; ++i){
		gpDeviceContext->CSSetConstantBuffers(0, 1, &pcLight);
	}
	stopWatch.EndTimer();



} 

//libfbxsdk-md.lib
//libfbxsdk.lib