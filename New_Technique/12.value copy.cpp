#include "stdafx.h"
#include "Function_Tool.h"


struct SData1{
	int arr[10];
};

struct SData2{
	int arr[100];
};

struct SData3{
	int arr[1000];
};

struct SData4{
	int arr[10000];
};

struct SData5{
	int arr[100000];
};

struct SData6{
	int arr[1000000];
};


const UINT LOOP_NUM = 1000000;

int main(){
	CStopWatch watch;

	cout << "------------정적 메모리-------------" << endl;
	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		SData1 data;
	}
	watch.EndTimer();

	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		SData2 data;
	}
	watch.EndTimer();

	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		SData3 data;
	}
	watch.EndTimer();

	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		SData4 data;
	}
	watch.EndTimer();

	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		SData5 data;
	}
	watch.EndTimer();

	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		SData6 data;
	}
	watch.EndTimer();

	cout << "------------동적 메모리-------------" << endl;
	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		SData1* data = new SData1;
		delete data;
	}
	watch.EndTimer();

	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		SData2* data = new SData2;
		delete data;
	}
	watch.EndTimer();

	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		SData3* data = new SData3;
		delete data;
	}
	watch.EndTimer();

	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		SData4* data = new SData4;
		delete data;
	}
	watch.EndTimer();

	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		SData5* data = new SData5;
		delete data;
	}
	watch.EndTimer();

	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		SData6* data = new SData6;
		delete data;
	}
	watch.EndTimer();
} 