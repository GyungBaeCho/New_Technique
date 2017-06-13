#include "stdafx.h"

#include <string>
#include <stdarg.h>
#include <time.h>
#include <windows.h>

#include <thread>
#include <vector>

#include <iostream>
using namespace std;

class CObject{
private:
	vector<thread*> m_vpThread;

public:
	static void ThreadFunc(CObject* pResourceManager, int num){
		while(true){
			cout << num << endl;
			Sleep(rand()%100 + 100);
		}
	}

	void CreateThread(){

		for(int i=0 ; i<4 ; ++i){
			//함수명 앞에 주소가 있든 없든 잘 된다는 것은 뭔가 이상한 일이다...
			m_vpThread.push_back(new thread{CObject::ThreadFunc, this, i});
		//	m_vpThread.push_back(new thread{&CObject::ThreadFunc, this, i});

		}
	}
};

int main(){
	CObject test;
	test.CreateThread();

	while(true);
}