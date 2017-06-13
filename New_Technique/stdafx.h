#pragma once

//Windows Assist
#include <Windows.h>

//Input Output
#include <iostream>
#include <fstream>
#include <memory>
#include <conio.h>
#include <string>

//Timer
#include <chrono>

//STL Container
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <vector>
#include <set>
#include <array>
//Multithread
#include <thread>
#include <atomic>
#include <mutex>

//Direct2D
#include <d2d1_2.h>
#include <dwrite.h>
#pragma comment(lib, "D2D1.lib")
#pragma comment(lib, "dwrite.lib")


//DirectX3D
#include <wrl.h>
using Microsoft::WRL::ComPtr;
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <DirectXCollision.h>
#include <DirectXColors.h>
using namespace DirectX;
using namespace DirectX::PackedVector;
#define XMASSERT assert 
#define XMVectorPermute( a, b, c) XMVectorPermute(a,b, c.i[0], c.i[1], c.i[2], c.i[3] )
#define _DECLSPEC_ALIGN_16_ __declspec(align(16))
#include <d3d11_4.h>
#include <d3dcompiler.h> 
#include <dxgi1_4.h>
//#include <DxErr.h>
//#include <DirectXTex.h>
//#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")
//#pragma comment(lib, "DXErr.lib")
#pragma comment(lib, "dxgi.lib")
#ifdef _DEBUG
//#pragma comment(lib, "DirectXTex_Debug.lib")
#else
//#pragma comment(lib, "DirectXTex.lib")
#endif


#if defined(DEBUG) | defined(_DEBUG)
	#ifndef HR
	#define HR(x)                                              \
	{                                                          \
		HRESULT hr = (x);                                      \
		if(FAILED(hr))                                         \
		{                                                      \
			DXTrace(__FILE__, (DWORD)__LINE__, hr, L#x, true); \
			exit(-1);										   \
		}                                                      \
	}
	#endif

#else
	#ifndef HR
	#define HR(x) (x)
	#endif
#endif 


#define SYSTEM_WARNNING

using namespace std;
using namespace std::chrono;
