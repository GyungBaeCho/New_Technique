
#include "stdafx.h"

//#include <iostream>
//#include <queue>
//#include <stack>
//#include <list>


int main(){

	list<int*> lpInt;
	lpInt.push_back(new int(10));
	lpInt.push_back(new int(100));
	lpInt.push_back(new int(1000));
	lpInt.push_back(new int(10000));

	list<int*> lpInt2;
	lpInt2 = lpInt;

	for(int* pInt : lpInt)
		cout << pInt << " " << *pInt << endl;

	cout << endl;

	for(int* pInt : lpInt2)
		cout << pInt << " " << *pInt << endl;

	list<int> lInt;
	lInt.push_back(10); lInt.push_back(10); lInt.push_back(10); lInt.push_back(10); lInt.push_back(10); lInt.push_back(10); lInt.push_back(10); lInt.push_back(10);lInt.push_back(10);

	list<int> lInt2;
	lInt2.push_back(20); lInt2.push_back(20); lInt2.push_back(20); lInt2.push_back(20); lInt2.push_back(20); lInt2.push_back(20); lInt2.push_back(20); lInt2.push_back(20); lInt2.push_back(20);
	
	list<int> lInt3;
	lInt3.insert(lInt3.end(), lInt.begin(), lInt.end());
	lInt3.insert(lInt3.end(), lInt2.begin(), lInt2.end());

	cout << "--------------" << endl;
	for(int data : lInt)
		cout << data << endl;

	cout << "--------------" << endl;
	for(int data : lInt2)
		cout << data << endl;

	cout << "--------------" << endl;
	for(int data : lInt3)
		cout << data << endl;

	queue<int> qInt;
	qInt.push(5);
	qInt.push(2);
	qInt.push(1);
	qInt.push(4);

	qInt.pop();
	cout << qInt.front() << " " << qInt.back() << endl;
	cout << qInt.size() << endl<< endl;


	stack<int> sInt;
	sInt.push(5);
	sInt.push(2);
	sInt.push(1);
	sInt.push(4);

	sInt.pop();
	cout << sInt.top() << endl;

	cout << sInt.size() << endl;



	unsigned int num = 20;
	num -= 30;
	cout << num << endl;

//	if(num < 10)

}