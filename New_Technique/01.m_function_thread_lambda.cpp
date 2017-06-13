#include "stdafx.h"

#include <string>
#include <stdarg.h>
#include <time.h>
#include <windows.h>

#include <thread>
#include <vector>

#include <iostream>
using namespace std;

//멤버 함수를 쓰레드로 생성하는 객체
class CObject{
private:
	vector<thread*> m_vpThread;

public:
	//쓰레드의 몸체가될 함수
	static void ThreadFunc(CObject* pResourceManager, int num){
		while(true){
			cout << num << endl;
			Sleep(rand()%100 + 100);
		}
	}

	//쓰레드 생성 객체
	void CreateThread(){
		for(int i=0 ; i<4 ; ++i){
			//람다 내부에 쓰레드 함수 본체가 있다.
			//[&](){} 와 [=](){} 의 차이점은 참조냐, 복사냐의 차이다
			m_vpThread.push_back(new thread([&](){ThreadFunc(this, i);}));
		}
	}
};


int main(){
	CObject test;
	test.CreateThread();

	while(true);
}