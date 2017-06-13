#include "stdafx.h"
#include "Function_Tool.h"

const UINT LOOP_NUM = 1'000'000;
const UINT AVG_LOOP_NUM = 1;

class csLock {
private:
	CRITICAL_SECTION m_critical_section;

public:
	csLock() {
		InitializeCriticalSection(&m_critical_section);
	}
	~csLock() {
		DeleteCriticalSection(&m_critical_section);
	}
	void lock() {
		EnterCriticalSection(&m_critical_section);
	}
	void unlock() {
		LeaveCriticalSection(&m_critical_section);
	}
};

//int g_num = 0;
atomic<int> g_num = 0;

void Func() {
	for (volatile int i = 0; i<LOOP_NUM ; ++i) {
		g_num++;
	}
}

csLock mylock;
volatile int g_num2 = 0;
void Func2() {
	for (volatile int i = 0; i<LOOP_NUM ; ++i) {
		mylock.lock();
		g_num2++;
		mylock.unlock();
	}
}

mutex mutexlock;
volatile int g_num3 = 0;
void Func3() {
	for (volatile int i = 0; i<LOOP_NUM ; ++i) {
		mutexlock.lock();
		g_num3++;
		mutexlock.unlock();
	}
}

int main(){
	CStopWatch watch;

	cout << "atomic<int>" << endl;
	duration<double> emptyAvgTime = duration<double>(0);
	{
		duration<double> avgTime = duration<double>(0); 
		for(volatile int avgLoop=0 ; avgLoop<AVG_LOOP_NUM; ++avgLoop){
			watch.BeginTimer();

			vector<thread> vThread;
			vThread.push_back(thread{Func});
			vThread.push_back(thread{Func});
			vThread.push_back(thread{Func});
			vThread.push_back(thread{Func});
			for (thread& th : vThread) th.join();

			avgTime += watch.EndTimerNoPrint();
		}
		avgTime /= AVG_LOOP_NUM;
		avgTime -= emptyAvgTime;
		cout << "AVG Time : " << to_string(avgTime.count()) << endl;
	}
	cout << g_num << endl << endl;

	cout << "critical_section" << endl;
	{
		duration<double> avgTime = duration<double>(0); 
		for(volatile int avgLoop=0 ; avgLoop<AVG_LOOP_NUM; ++avgLoop){
			watch.BeginTimer();

			vector<thread> vThread;
			vThread.push_back(thread{Func2});
			vThread.push_back(thread{Func2});
			vThread.push_back(thread{Func2});
			vThread.push_back(thread{Func2});
			for (thread& th : vThread) th.join();

			avgTime += watch.EndTimerNoPrint();
		}
		avgTime /= AVG_LOOP_NUM;
		avgTime -= emptyAvgTime;
		cout << "AVG Time : " << to_string(avgTime.count()) << endl;
	}
	cout << g_num2 << endl << endl;

	cout << "mutex" << endl;
	{
		duration<double> avgTime = duration<double>(0); 
		for(volatile int avgLoop=0 ; avgLoop<AVG_LOOP_NUM; ++avgLoop){
			watch.BeginTimer();

			vector<thread> vThread;
			vThread.push_back(thread{Func3});
			vThread.push_back(thread{Func3});
			vThread.push_back(thread{Func3});
			vThread.push_back(thread{Func3});
			for (thread& th : vThread) th.join();

			avgTime += watch.EndTimerNoPrint();
		}
		avgTime /= AVG_LOOP_NUM;
		avgTime -= emptyAvgTime;
		cout << "AVG Time : " << to_string(avgTime.count()) << endl;
	}
	cout << g_num3 << endl << endl;

	{
		duration<double> avgTime = duration<double>(0); 
		for(volatile int avgLoop=0 ; avgLoop<AVG_LOOP_NUM; ++avgLoop){
			watch.BeginTimer();

			Sleep(1000);

			avgTime += watch.EndTimerNoPrint();
		}
		avgTime /= AVG_LOOP_NUM;
		avgTime -= emptyAvgTime;
		cout << "AVG Time : " << to_string(avgTime.count()) << endl;
	}
} 