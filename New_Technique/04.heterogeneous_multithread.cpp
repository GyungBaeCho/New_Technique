#include "stdafx.h"

#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

#include "Function_Tool.h"

//using namespace std;
//
//class CFramework{
//public:
//	thread* m_pUpdateThread;
//	thread* m_pRenderThread;
//
//	volatile byte m_UpdateFlag;
//	volatile byte m_RenderFlag;
//
//public:
//	CFramework(){
//		m_UpdateFlag = 0;
//		m_RenderFlag = 0;
//	}
//
//	static void Update(CFramework* pThis){
//		CStopWatch watch;
//
//		while(true){
//			watch.BeginTimer();
//				while(pThis->m_UpdateFlag == 1);
//				printLock.lock();
//					cout << "Update" << endl;
//				printLock.unlock();
//				
//				Sleep(rand()%5000 + 100);
//				atomic_thread_fence(std::memory_order_seq_cst);
//			watch.LockEndTimer();
//			pThis->m_UpdateFlag = 1;
//		}
//	}
//	
//	static void Render(CFramework* pThis){
//		CStopWatch watch;
//		while(true){
//			watch.BeginTimer();
//				while(pThis->m_RenderFlag == 1);
//				printLock.lock();
//					cout << "Render" << endl;
//				printLock.unlock();
//				
//				Sleep(rand()%5000 + 100);
//				atomic_thread_fence(std::memory_order_seq_cst);
//			watch.LockEndTimer();
//			pThis->m_RenderFlag = 1;
//		}
//	}
//	
//	void CreateThread(){
//		m_pUpdateThread = new thread(&Update, this);
//		m_pRenderThread = new thread(&Render, this);
//	}
//
//	void FrameAdvance(){
//		printLock.lock();
//			cout << "------------" << endl;
//		printLock.unlock();
//		m_UpdateFlag = m_RenderFlag = 0;
//		while(true)if(m_UpdateFlag && m_RenderFlag) break;
//	}
//};
//
//int main(){
//	CFramework framework;
//	framework.CreateThread();
//
//	CStopWatch watch;
//	while(true){
//		watch.BeginTimer();
//			framework.FrameAdvance();
//		watch.LockEndTimer();
//	}
//}

using namespace std;

class CFramework{
public:
	thread* m_pUpdateThread;
	thread* m_pRenderThread;

	volatile byte m_UpdateFlag;
	volatile byte m_RenderFlag;

public:
	CFramework(){
		m_UpdateFlag = 0;
		m_RenderFlag = 0;
	}

	static void Update(CFramework* pThis){
		while(true){
			while(pThis->m_UpdateFlag == 1);
				cout << "Update" << endl;
				
			atomic_thread_fence(std::memory_order_seq_cst);
			pThis->m_UpdateFlag = 1;
		}
	}
	
	static void Render(CFramework* pThis){
		while(true){
			while(pThis->m_RenderFlag == 1);
			cout << "Update" << endl;

			atomic_thread_fence(std::memory_order_seq_cst);
			pThis->m_RenderFlag = 1;
		}
	}
	
	void CreateThread(){
		m_pUpdateThread = new thread(&Update, this);
		m_pRenderThread = new thread(&Render, this);
	}

	void FrameAdvance(){
		m_UpdateFlag = m_RenderFlag = 0;
		while(true)if(m_UpdateFlag && m_RenderFlag) break;
	}
};

int main(){
	CFramework framework;
	framework.CreateThread();

	CStopWatch watch;
	while(true) framework.FrameAdvance();
}