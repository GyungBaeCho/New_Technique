#include "stdafx.h"

#include <iostream>
using namespace std;
#include <string>
#include <stdarg.h>
#include <time.h>

void HandlData(int i){ cout << i << endl; }
void HandlData(string s){ cout << s << endl; }
//아무것도 남지 않았을 경우
void Print(){ }

//가변인자를 위한 함수
template<typename  Ty, typename...Args>
void Print(Ty ty, Args...args)
{
	HandlData(ty);

	Print(args...);
}

int main(){

	Print(10, 20, 30, 40, 50, 60, 70, "Hey Hey!", "안녕하세욧!");
}