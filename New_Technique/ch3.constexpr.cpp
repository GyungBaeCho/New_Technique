#include "stdafx.h"

#include <iostream>
using namespace std;

/*
	C+ 11 부터 컴파일 시간에 평가될 수 있는 표현식을 나타내는 키워드
	Const Expression : 상수 표현식 -> constexpr
*/

//아래의 두개는 동일한 표현식인듯 하다.
const int cnst_int = 100;
constexpr int num_of_index = 100;

//Const Expression : 상수 표현식
constexpr int DynamicIndex(int num){
	return num;
}

//int 형식을 반환하는 반환하는 것이 아니라 const int를 반환 함에도
//다음 함수의 return 값을 받는 배열은 불가능하다.
const int ReturnIndex(int num){
	return num;
}


int main(){
	int arr1[cnst_int];

	int arr2[num_of_index];

	//다음과 같은 형태는 불가
	int num = 10;
	int arr3[DynamicIndex(num)];

	//다음과 같이 상수 표현 반환 함수의 인자에는 반드시 상수가 들어가야 한다.
	int arr3[DynamicIndex(100)];
	//그러면 별 의미 없는거 아닌가...??

	//뭐.. 어찌 되었든.. 아래와 같은 문법이 아예 안되던 것에서 달라졌으니..
	int arr3[ReturnIndex(100)];

	const int num = 100;
	//int arr4[DynamicIndex(num)];
}