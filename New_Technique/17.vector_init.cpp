#include "stdafx.h"
#include "Function_Tool.h"

const UINT LOOP_NUM = 1'000'000;
const UINT AVG_LOOP_NUM = 10;

int main() {
	CStopWatch watch;

	duration<double> emptyAvgTime = duration<double>(0);
	{
		for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
			for (int i = 0; i<LOOP_NUM; ++i) {
				watch.BeginTimer();
				emptyAvgTime += watch.EndTimerNoPrint();
			}
		}
		emptyAvgTime /= AVG_LOOP_NUM;
		cout << "AVG Time : " << to_string(emptyAvgTime.count()) << endl << endl;
	}

	{
		duration<double> avgTime = duration<double>(0);
		for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
			for (int i = 0; i<LOOP_NUM; ++i) {
				watch.BeginTimer();
				vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
				avgTime += watch.EndTimerNoPrint();
			}
		}
		avgTime /= AVG_LOOP_NUM;
		avgTime -= emptyAvgTime;
		cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;
	}

	{
		duration<double> avgTime = duration<double>(0);
		for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
			for (int i = 0; i<LOOP_NUM; ++i) {
				watch.BeginTimer();
				int a[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
				avgTime += watch.EndTimerNoPrint();
			}
		}
		avgTime /= AVG_LOOP_NUM;
		avgTime -= emptyAvgTime;
		cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;
	}

	{
		duration<double> avgTime = duration<double>(0);
		for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
			for (int i = 0; i<LOOP_NUM; ++i) {
				watch.BeginTimer();
				int *a = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
				delete[] a;
				avgTime += watch.EndTimerNoPrint();
			}
		}
		avgTime /= AVG_LOOP_NUM;
		avgTime -= emptyAvgTime;
		cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;
	}
}