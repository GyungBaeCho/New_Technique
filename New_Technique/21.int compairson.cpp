#include "stdafx.h"
#include "Function_Tool.h"

const UINT LOOP_NUM = 1'000'000;
const UINT AVG_LOOP_NUM = 10;

template<class T>
void f(const T& data) {
	cout << data << endl;
}

int main() {

	f(10);

	std::shared_ptr<int> a = make_shared<int>(100);

	std::weak_ptr<int> b;
	
	cout << a.use_count() << endl;
	b = a;

	cout << *a << " " << a.use_count() << endl;

	cout << *b.lock() << " " << b.use_count() << endl;

	a = nullptr;

	if (b.expired()) {
		cout << "b 만료" << endl;
	}

/*
	int64와 int32 의 비교 퍼포먼스를 비교하는 Test

	Release 실행 결과
	
	순회 횟수 1백만번

	32 Bit
		AVG Time : 0.006061

	64 Bit
		AVG Time : 0.006433

	
	의미가 별로 없는 것으로 판단됨.
*/
	__int32 com32 = 100;
	__int32 n32 = 100;
	{
		CStopWatch watch;
		duration<double> emptyAvgTime = duration<double>(0);
		{
			duration<double> avgTime = duration<double>(0);
			for (volatile int avgLoop = 0; avgLoop < AVG_LOOP_NUM; ++avgLoop) {
				watch.BeginTimer();
				
				for(volatile int loop=0 ; loop < LOOP_NUM ; ++loop)
					n32 > com32;

				avgTime += watch.EndTimerNoPrint();
			}
			avgTime /= AVG_LOOP_NUM;
			avgTime -= emptyAvgTime;
			cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;
		}
	}

	__int64 com64 = 100;
	__int64 n64 = 100;
	{
		CStopWatch watch;
		duration<double> emptyAvgTime = duration<double>(0);
		{
			duration<double> avgTime = duration<double>(0);
			for (volatile int avgLoop = 0; avgLoop < AVG_LOOP_NUM; ++avgLoop) {
				watch.BeginTimer();

				for (volatile int loop = 0; loop < LOOP_NUM; ++loop)
					n64 > com64;

				avgTime += watch.EndTimerNoPrint();
			}
			avgTime /= AVG_LOOP_NUM;
			avgTime -= emptyAvgTime;
			cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;
		}
	}


}