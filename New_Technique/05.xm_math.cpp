#include "stdafx.h"

//#include <d3d11.h>
//#include <d3dx11.h>
////#include <DirectXMath.h>
////#include <DirectXPackedVector.h>
////using namespace DirectX;
//#include <xnamath.h>
//#include <D3DX10Math.h>
//#include <Windows.h>
//#include <iostream>

#include "Function_Tool.h"


#define OP_NUM		1000000000

int main() {

	cout << sizeof(int) << endl;
	cout << sizeof(_int64) << endl;

	__int64 a = 1000000000000000000;
	int b = 100000000000;
	cout << a << endl;
	cout << b << endl;

	__int64 begCount;
	QueryPerformanceCounter((LARGE_INTEGER*) &begCount);
	cout << begCount << endl;

	__int64 secPerCount;
	QueryPerformanceFrequency((LARGE_INTEGER*) &secPerCount);
	cout << secPerCount << endl;
	cout << 1.0f/secPerCount << endl;

	__int64 endCount;
	QueryPerformanceCounter((LARGE_INTEGER*) &endCount);
	cout << endCount << endl;

	cout << endCount - begCount * 1.0f/secPerCount << endl;;
	cout << endl;


	if(!XMVerifyCPUSupport())
		cout << "SIMD 지원 불가" << endl;
	else
		cout << "SIMD 지원가능" << endl;
	//D3DXMATRIX d3dxmtWorld{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	//D3DXMATRIX d3dxmtTemp;
	//D3DXMatrixIdentity(&d3dxmtTemp);
	//cout << "D3D Library" << endl;
	//BeginTimer();
	//	for(int i=0 ; i<OP_NUM ; ++i)
	//		d3dxmtWorld += d3dxmtTemp;
	//EndTimer();
	//cout << d3dxmtWorld._11 << endl;
	//cout << endl;

	//XMFLOAT4X4 xmfloat4x4World{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	//XMMATRIX xmmtxTemp = XMMatrixIdentity();
	//XMMATRIX xmmtxWorld = XMLoadFloat4x4(&xmfloat4x4World);
	//cout << "XM Library" << endl;
	//BeginTimer();
	//	for (int i = 0; i<OP_NUM; ++i) xmmtxWorld += xmmtxTemp;
	//	XMStoreFloat4x4(&xmfloat4x4World, xmmtxWorld);
	////	XMVectorAdd;
	//EndTimer();
	//cout << xmfloat4x4World._11 << endl;
	//cout << endl;

	#define OP_NUM		1000000000

	D3DXMATRIX d3dxmtWorld( 1, 0, 0, 0, 
							0, 2, 0, 0, 
							0, 0, 4, 0, 
							1, 3, 2, 8);
	D3DXVECTOR3 d3dxVec(10, 10, 10);
	cout << "D3D Library" << endl;
	BeginTimer();
		for(int i=0 ; i<OP_NUM ; ++i)
			D3DXVec3TransformCoord(&d3dxVec, &d3dxVec, &d3dxmtWorld);
	EndTimer();
	cout << endl;

	XMFLOAT4X4 xmfloat4x4World( 1, 0, 0, 0, 
								0, 2, 0, 0, 
								0, 0, 4, 0, 
								1, 3, 2, 8);

	XMMATRIX xmmtxWorld = XMLoadFloat4x4(&xmfloat4x4World);
	XMVECTOR xmVec = XMVectorSet(10, 10, 10, 1);
	cout << "XM Library" << endl;
	BeginTimer();
		for (int i = 0; i<OP_NUM; ++i) 
			xmVec = XMVector3TransformCoord(xmVec, xmmtxWorld);
		XMStoreFloat4x4(&xmfloat4x4World, xmmtxWorld);
	EndTimer();
	cout << endl;

	//D3DXVECTOR4 d3dxvVector{0, 0, 0, 0};
	//D3DXVECTOR4 d3dxvTemp{1, 1, 1, 1};
	//cout << "D3D Library" << endl;
	//BeginTimer();
	//	for (int i = 0; i<OP_NUM; ++i) 
	//		d3dxvVector += d3dxvTemp;
	//EndTimer();
	//cout << d3dxvVector.x << endl << endl;

	//XMFLOAT4 xmfloat4{ 0, 0, 0, 0 };
	//XMVECTOR xmTemp{ 1, 1, 1, 1 };
	//cout << "XM Library" << endl;
	//BeginTimer();
	//	XMVECTOR xmCopy = XMLoadFloat4(&xmfloat4);
	//	for (int i = 0; i<OP_NUM; ++i) 
	//		xmCopy = XMVectorAdd(xmCopy, xmTemp);
	//	XMStoreFloat4(&xmfloat4, xmCopy);
	//EndTimer();
	//cout << xmfloat4.x << endl << endl;


	//volatile D3DXMATRIX d3dxmtxMatrix;
	//cout << "D3DXMATRIX 멤버 요소 접근" << endl;
	//BeginTimer();
	//	for (int i = 0; i<OP_NUM; ++i)
	//		d3dxmtxMatrix._11 += 1;
	//EndTimer();
	//cout << d3dxmtxMatrix._11 << endl;
	//cout << endl;

	//XMMATRIX xmmtxMatrix;
	//cout << "XMMATRIX 멤버 요소 접근" << endl;
	//BeginTimer();
	//	for (int i = 0; i<OP_NUM; ++i)
	//		xmmtxMatrix._11 += 1;
	//EndTimer();
	//cout << XMVectorGetX(xmmtxMatrix.r[0]);
	//cout << endl;
}