#include "stdafx.h"
#include "Function_Tool.h"

const UINT LOOP_NUM = 1'000'000;
const UINT AVG_LOOP_NUM = 1000;

void Fu(){}

#define AvgTimer(X)													\
		{															\
			duration<double> avgTime = duration<double>(0); 		\
			for(int avgLoop=0 ; avgLoop<AVG_LOOP_NUM; ++avgLoop){	\
				watch.BeginTimer();									\
				for(int i=0 ; i<LOOP_NUM ; ++i){					\
																	\
				}													\
			avgTime += watch.EndTimerNoPrint();						\
			}														\
		}															\
		avgTime /= AVG_LOOP_NUM;									\
		cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;


int main(){
	CStopWatch watch;

	CStopWatch *pWatch = &watch;

	cout << "Address Compare == Address" << endl;
	{
		duration<double> avgTime = duration<double>(0); 
		for(int avgLoop=0 ; avgLoop<AVG_LOOP_NUM; ++avgLoop){
			watch.BeginTimer();
			for(int i=0 ; i<LOOP_NUM ; ++i){
				if(pWatch == &watch);
			}
			avgTime += watch.EndTimerNoPrint();
		}
		avgTime /= AVG_LOOP_NUM;
		cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;
	}

	cout << "Address Compare != Address" << endl;
	{
		duration<double> avgTime = duration<double>(0); 
		for(int avgLoop=0 ; avgLoop<AVG_LOOP_NUM; ++avgLoop){
			watch.BeginTimer();
			for(int i=0 ; i<LOOP_NUM ; ++i){
				if(pWatch != &watch);
			}
			avgTime += watch.EndTimerNoPrint();
		}
		avgTime /= AVG_LOOP_NUM;
		cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;
	}

	cout << "Address Compare == nullptr" << endl;
	{
		duration<double> avgTime = duration<double>(0); 
		for(int avgLoop=0 ; avgLoop<AVG_LOOP_NUM; ++avgLoop){
			watch.BeginTimer();
			for(int i=0 ; i<LOOP_NUM ; ++i){
				if(pWatch == nullptr);
			}
			avgTime += watch.EndTimerNoPrint();
		}
		avgTime /= AVG_LOOP_NUM;
		cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;
	}

	cout << "Address Compare != nullptr" << endl;
	{
		duration<double> avgTime = duration<double>(0); 
		for(int avgLoop=0 ; avgLoop<AVG_LOOP_NUM; ++avgLoop){
			watch.BeginTimer();
			for(int i=0 ; i<LOOP_NUM ; ++i){
				if(pWatch != nullptr);
			}
			avgTime += watch.EndTimerNoPrint();
		}
		avgTime /= AVG_LOOP_NUM;
		cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;
	}

	bool bFlag = false;

	cout << "bool Compare ==" << endl;
	{
		duration<double> avgTime = duration<double>(0); 
		for(int avgLoop=0 ; avgLoop<AVG_LOOP_NUM; ++avgLoop){
			watch.BeginTimer();
			for(int i=0 ; i<LOOP_NUM ; ++i){
				if(bFlag == true);
			}
			avgTime += watch.EndTimerNoPrint();
		}
		avgTime /= AVG_LOOP_NUM;
		cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;
	}

	cout << "bool Compare !=" << endl;
	{
		duration<double> avgTime = duration<double>(0); 
		for(int avgLoop=0 ; avgLoop<AVG_LOOP_NUM; ++avgLoop){
			watch.BeginTimer();
			for(int i=0 ; i<LOOP_NUM ; ++i){
				if(bFlag != true);
			}
			avgTime += watch.EndTimerNoPrint();
		}
		avgTime /= AVG_LOOP_NUM;
		cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;
	}
} 