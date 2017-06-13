#include "stdafx.h"
#include "Function_Tool.h"

const UINT LOOP_NUM = 1'000'000;
const UINT AVG_LOOP_NUM = 100;

class CCommand{
public:
	virtual void Execute() = 0;
};


inline void Func(){}
inline void Func2(){}

int main(){
	CStopWatch watch;

	{
		duration<double> avgTime = duration<double>(0); 
		for(int avgLoop=0 ; avgLoop<AVG_LOOP_NUM; ++avgLoop){
			watch.BeginTimer();
			for(int i=0 ; i<LOOP_NUM ; ++i){
				Func();
			}
			avgTime += watch.EndTimerNoPrint();
		}
		avgTime /= AVG_LOOP_NUM;
		cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;
	}
	
	{
		duration<double> avgTime = duration<double>(0); 
		for(int avgLoop=0 ; avgLoop<AVG_LOOP_NUM; ++avgLoop){
			watch.BeginTimer();
			for(int i=0 ; i<LOOP_NUM ; ++i){
				Func2();
			}
			avgTime += watch.EndTimerNoPrint();
		}
		avgTime /= AVG_LOOP_NUM;
		cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;
	}

	{
		duration<double> avgTime = duration<double>(0); 
		for(int avgLoop=0 ; avgLoop<AVG_LOOP_NUM; ++avgLoop){
			watch.BeginTimer();
			for(int i=0 ; i<LOOP_NUM ; ++i){
				Func();
			}
			avgTime += watch.EndTimerNoPrint();
		}
		avgTime /= AVG_LOOP_NUM;
		cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;
	}
}