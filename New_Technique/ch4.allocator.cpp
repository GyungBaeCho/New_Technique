#include "stdafx.h"

#include <iostream>
using namespace std;

int* Function(){
	int num = 10;
	cout <<num << " " << &num << endl;
	return &num; 
}

int main(){
	int* pInt;
	pInt = Function();
	cout << *pInt << " " << pInt << endl;

//	*pInt = 100;
//	cout << *pInt << endl;
}