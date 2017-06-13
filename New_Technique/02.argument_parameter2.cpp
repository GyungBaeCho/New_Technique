#include "stdafx.h"

#include <iostream>
using namespace std;
#include <string>
#include <stdarg.h>
#include <time.h>


template<typename...Args>
void Function(int count, Args...args){
	va_list list;

	//C의 가변인자와 가변인자 템플릿은 다른 개념이다.

	//아래의 변수를 va_start의 파라미터로 넘기면 잘못된 값이 출력된다.
	int num_of_args = sizeof...(args);
	
	va_start(list, num_of_args);
//	va_start(list, count);
	for(int i=0 ; i<num_of_args ; ++i) 
		cout << va_arg(list, int) << endl;
	va_end(list);
}

int main(){

//	#define NUMARGS(...)  (sizeof((int[]){__VA_ARGS__})/sizeof(int))
//	#define CHECK1(...) { printf(__VA_ARGS__); }  
//	#define NUMARGS2(...)  	int a[]{__VA_ARGS__}; 

//	int a[]{10, 10};
//	sizeof(int[]{10, 10})/sizeof(int);

	Function(5, 1, 2, 3, 4, 5);
}
