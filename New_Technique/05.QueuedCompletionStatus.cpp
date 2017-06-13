#include "stdafx.h"

#include <iostream>
using namespace std;
#include <winsock2.h>
#pragma comment(lib, "ws2_32")
#include <thread>
#include <mutex>

#include <conio.h>

const unsigned int MAX_BUFF_SIZE = 4000;
mutex text_lock;
HANDLE hIOCP;

enum OVERLAP_OPERATION{
	OP_RENDER,
	OP_UPDATE,
};

typedef struct OverlapEx{
	WSAOVERLAPPED	original_overlap;
	int				operation;
	WSABUF			recv_buff;
	unsigned char	socket_buff[MAX_BUFF_SIZE];
	int				packet_size;
}OverlapEx;

void ThreadFunction(int idThread){
	DWORD io_Size;
	DWORD key;
	OverlapEx* overlap;
	bool bResult;

	while(true){
		bResult = GetQueuedCompletionStatus(hIOCP, &io_Size, reinterpret_cast<PULONG_PTR>(&key), reinterpret_cast<LPOVERLAPPED*>(&overlap), INFINITE);
		if(false == bResult){
			//Error 贸府
		}
		switch(overlap->operation){
		case OVERLAP_OPERATION::OP_RENDER:
			text_lock.lock();
			wcout << key << "[" <<idThread << "]" << ": RENDER!" << endl;
			text_lock.unlock();
			break;
		}
	}
}

int main(){
	WSADATA	wsadata;
//	_wsetlocale(LC_ALL, L"korean");
//	WSAStartup(MAKEWORD(2,2), &wsadata);

	//IOCP按眉 积己
	hIOCP = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, 0);

	thread worker_thread{		ThreadFunction, 0		};
	thread worker_thread2{		ThreadFunction, 1		};
	thread worker_thread3{		ThreadFunction, 2		};
	thread worker_thread4{		ThreadFunction, 3		};
	thread worker_thread5{		ThreadFunction, 4		};
	thread worker_thread6{		ThreadFunction, 5		};

	int id_pivot = 0;
//	CreateIoCompletionPort(reinterpret_cast<HANDLE>(new_client), hIOCP, id_pivot, 0);
//	CreateIoCompletionPort(NULL, hIOCP, id_pivot, 0);


	DWORD flags = 0;
	OverlapEx* overlap = new OverlapEx;
	overlap->operation = OVERLAP_OPERATION::OP_RENDER;
//	WSARecv(NULL, &overlap->recv_buff, 1, NULL, &flags, &overlap->original_overlap, NULL);

	bool bLoop = true;
	while(bLoop){
		PostQueuedCompletionStatus(hIOCP, 1, 0, reinterpret_cast<LPOVERLAPPED>(overlap));

		if(_kbhit()){
			switch(getch()){
			case 'q':
				bLoop = false;
				break;
			}
		}
	}

//	PostQueuedCompletionStatus(hIOCP, 1, NULL, NULL);

////	int packet_size = reinterpret_cast<unsigned char *>(packet)[0];
//	OverlapEx* send_over = new OverlapEx;
//	ZeroMemory(send_over, sizeof(OverlapEx));
//	send_over->operation = OP_SEND;
////	send_over->recv_buff.buf = reinterpret_cast<CHAR*>(send_over->socket_buff);
////	send_over->recv_buff.len = packet_size;
////	memcpy(send_over->socket_buff, packet, packet_size);
//	WSASend(NULL, &send_over->recv_buff, 1, NULL, 0, &send_over->original_overlap, NULL);
//
	//PostQueuedCompletionStatus(hIOCP, 1, curr_event.obj_id, reinterpret_cast<LPOVERLAPPED>(event_over));
	//GetQueuedCompletionStatus();
	//GetQueuedCompletionStatus(hIOCP, &io_Size, reinterpret_cast<PULONG_PTR>(&key), reinterpret_cast<LPOVERLAPPED*>(&overlap), INFINITE);


	worker_thread.join();
}
