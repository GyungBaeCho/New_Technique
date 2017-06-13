#include <iostream>
using namespace std;

#include "stdafx.h"
#include "Function_Tool.h"

/*
	결론 : memcpy가 move보다 5배가량 빠르다.
*/

inline void init(int* arr, int length){
	for(int i=0 ; i< length ; ++i){
		arr[i] = i;
		if(i > length/2) arr[i] = 0;
	}
}
inline void print(int* arr, int length){
	for(int i=0 ; i< length ; ++i){
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

inline void my_move1(int* beg, int* end, int* dest){
	int pivot = 0;

	while(&beg[pivot] != end){
		dest[pivot]= beg[pivot];
		pivot += 1;
	}
}

inline void my_move2(int* beg, int* end, int* dest){
	int* itrtr = beg;
	
	while(itrtr != end){
		*dest = *itrtr;
		itrtr = itrtr + 1;
		dest = dest + 1;
	}
}

const int loop_num = 10000000;
int main(){
	CStopWatch stopWatch;

	int arr[100];

	init(arr, 100);
	//my move function
	stopWatch.BeginTimer();
	for(int i=0 ; i<loop_num ; ++i){
		my_move1(arr, arr+50, arr+50);
	}
	stopWatch.EndTimer();
	print(arr, 100);

	init(arr, 100);
	//my move function
	stopWatch.BeginTimer();
	for(int i=0 ; i<loop_num ; ++i){
		my_move2(arr, arr+50, arr+50);
	}
	stopWatch.EndTimer();
	print(arr, 100);

	init(arr, 100);
	//std move fnuction
	stopWatch.BeginTimer();
	for(int i=0 ; i<loop_num ; ++i){
		move(arr, arr+50, arr+50);
	}
	stopWatch.EndTimer();
	print(arr, 100);

	init(arr, 100);
	//memcpy
	stopWatch.BeginTimer();
	for(int i=0 ; i<loop_num ; ++i){
		memcpy(arr+50, arr, 4*50);
	}
	stopWatch.EndTimer();
	print(arr, 100);
}