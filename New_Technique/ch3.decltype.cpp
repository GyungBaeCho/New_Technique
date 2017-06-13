#include "stdafx.h"

#include <iostream>
using namespace std;

#include <typeinfo>

/*
	decltype - 받은 변수의 자료형을 사용한다.
*/

//예전에는 다음과 같은 코드는 수행이 불가능했다.
//템플릿으로 받은 두개의 다른 자료형의 함수 결과물이 정수냐, 실수냐를
//보고 알아서 반환하는 형식이 불가능 했다.
template<typename T1, typename T2>
decltype(x+y) FunctionAdd1(T1 x, T2 y){}

//하지만 이제 다음과 같은 것이 가능하다.
template<typename T1, typename T2>
auto FunctionAdd2(T1 x, T2 y) -> decltype(x + y)
{
	return x + y;
}

int main(){
	int num;

	//전달된 변수의 자료형으로 새로운 변수를 선언한다.
	decltype(num) a;
	a = 100;
	cout << a << endl;
		
	//다음 함수는 실행이 불가능 하다.
	//decltype(x + y) 부분에서 x, y가 어느 것인지를 인지하지 못한다.
	//FunctionAdd2(10, 20);

	//각각의 반환하는 자료형이 다르다는 것을 알 수 있다.
	cout << typeid(FunctionAdd2(10, 10)).name() << endl;
	cout << typeid(FunctionAdd2(10, (float)10)).name() << endl;
	cout << typeid(FunctionAdd2(10, 10.0)).name() << endl;

}

