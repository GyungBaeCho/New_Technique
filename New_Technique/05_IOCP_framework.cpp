//#include "stdafx.h"

#include <iostream>
using namespace std;
#include <winsock2.h>
#include <ws2def.h>
#pragma comment(lib, "ws2_32")
#include <thread>
#include <mutex>
#include <vector>
#include <conio.h>

const unsigned int MAX_BUFF_SIZE = 4000;
mutex text_lock;

enum OVERLAP_OPERATION{
	OP_RENDER,
	OP_UPDATE,

	OP_DESTROY,
};

typedef struct OverlapEx{
	WSAOVERLAPPED	original_overlap;
	int				operation;
	WSABUF			recv_buff;
	unsigned char	socket_buff[MAX_BUFF_SIZE];
	int				packet_size;
}OverlapEx;

#define	FRAMEWORK		CIOFramework::GetInstance()
class CIOFramework{
private:
	static CIOFramework* m_pInstance;
	
	int				m_nSupportedCPU;
	vector<thread*>	m_vpThread;

public:
	HANDLE			m_hIOCP;
	SOCKET			m_ServerSock;
	SOCKET			m_ListenSock;

private:
	CIOFramework(){}
	~CIOFramework(){}

public:
	static void CreateInstance(){		m_pInstance = new CIOFramework;		}
	static CIOFramework* GetInstance(){		return m_pInstance;		}

	void Initialize(){
		m_hIOCP = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, 0);

		SYSTEM_INFO sysinfo;
		GetSystemInfo( &sysinfo );
		m_nSupportedCPU = sysinfo.dwNumberOfProcessors;
//		cout << "dwPageSize"					<< " : " << sysinfo.dwPageSize << endl;
//		cout << "lpMinimumApplicationAddress"	<< " : " << sysinfo.lpMinimumApplicationAddress << endl;
//		cout << "lpMaximumApplicationAddress"	<< " : " << sysinfo.lpMaximumApplicationAddress << endl;
//		cout << "dwActiveProcessorMask"			<< " : " << sysinfo.dwActiveProcessorMask << endl;
//		cout << "dwNumberOfProcessors"			<< " : " << sysinfo.dwNumberOfProcessors << endl;
//		cout << "dwProcessorType"				<< " : " << sysinfo.dwProcessorType << endl;
//		cout << "dwAllocationGranularity"		<< " : " << sysinfo.dwAllocationGranularity << endl;
//		cout << "wProcessorLevel"				<< " : " << sysinfo.wProcessorLevel << endl;
//		cout << "wProcessorRevision"			<< " : " << sysinfo.wProcessorRevision << endl;
//		cout << "-------------------------------------" << endl << endl;

		int idThread = 0;
		m_vpThread.push_back(new thread{AcceptThread, this, idThread++});

		for(int i=0 ; i<m_nSupportedCPU ; ++i) 
			m_vpThread.push_back(new thread{WorkerThread, this, idThread++});

		m_vpThread.push_back(new thread{TimerThread, this, idThread++});

		cout << "IO Framework Ininialize Completed!!" << endl;
	}

	void Destroy(){
		OverlapEx overlap;
		overlap.operation = OVERLAP_OPERATION::OP_DESTROY;

		for(thread* th : m_vpThread){
			PostQueuedCompletionStatus(m_hIOCP, 1, 0, reinterpret_cast<LPOVERLAPPED>(&overlap));
			th->join();
			delete th;
		}
		cout << "IO Framework Destroy Completed!!" << endl;
	}

	void MainLoop(){
		DWORD flags = 0;
		OverlapEx* overlap = new OverlapEx;
		overlap->operation = OVERLAP_OPERATION::OP_RENDER;

		OverlapEx* overlap2 = new OverlapEx;
		overlap2->operation = OVERLAP_OPERATION::OP_UPDATE;

		while(true){
									//IOCP Handle,		Transferred Byte Size,		Completion Key,		Overlap °´Ã¼
			PostQueuedCompletionStatus(m_hIOCP, 1, 0, reinterpret_cast<LPOVERLAPPED>(overlap));
			PostQueuedCompletionStatus(m_hIOCP, 1, 0, reinterpret_cast<LPOVERLAPPED>(overlap2));
			if(_kbhit()){
				switch(_getch()){
				case 'q':
					return;
				}
			}

		}
	}

//Thread Functions
public:
	static void AcceptThread(CIOFramework* pThis, int idThread){
	
	}

	static void WorkerThread(CIOFramework* pThis, int idThread){
		DWORD io_Size;
		DWORD key;
		OverlapEx* overlap;
		bool bResult;

		while(true){
			bResult = GetQueuedCompletionStatus(pThis->m_hIOCP, &io_Size, reinterpret_cast<PULONG_PTR>(&key), reinterpret_cast<LPOVERLAPPED*>(&overlap), INFINITE);

			DWORD errorCode = GetLastError();

			if(bResult == false && errorCode == WAIT_TIMEOUT) continue;

			if(false == bResult){
				//Error Ã³¸®
			}
			switch(overlap->operation){
			case OVERLAP_OPERATION::OP_RENDER:
				text_lock.lock();
				wcout << key << "[" <<idThread << "]" << ": RENDER!" << endl;
				text_lock.unlock();
				break;

			case OVERLAP_OPERATION::OP_UPDATE:
				text_lock.lock();
				wcout << key << "[" <<idThread << "]" << ": UPDATE!" << endl;
				text_lock.unlock();
				break;

			case OVERLAP_OPERATION::OP_DESTROY:
				text_lock.lock();
				cout << idThread << " Destroyed!" << endl;
				text_lock.unlock();
				return;
			}
		}
	}

	static void TimerThread(CIOFramework* pThis, int idThread){

	}

};
__declspec(selectany) CIOFramework* CIOFramework::m_pInstance = nullptr;

int main(){
	FRAMEWORK->CreateInstance();
	FRAMEWORK->Initialize();

	FRAMEWORK->MainLoop();

	FRAMEWORK->Destroy();
}