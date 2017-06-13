#include "stdafx.h"
#include "Function_Tool.h"

const UINT LOOP_NUM = 1'000'000;
const UINT AVG_LOOP_NUM = 10;

int g_num = 0;
//atomic<int> g_num = 0;

void Func() {
	for (volatile int i = 0; i<10000000 ; ++i) {
		g_num++;
	}
}

int main(){
	CStopWatch watch;

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
			vThread.push_back(thread{Func});
			for (thread& th : vThread) th.join();

			avgTime += watch.EndTimerNoPrint();
		}
		avgTime /= AVG_LOOP_NUM;
		avgTime -= emptyAvgTime;
		cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;
	}

	

	cout << g_num << endl;
} 