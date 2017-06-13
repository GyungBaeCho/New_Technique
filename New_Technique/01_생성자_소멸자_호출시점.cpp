#include "stdafx.h"

class CClass {
public:
	CClass() {
		cout << "CClass" << endl;
	}
	~CClass() {
		cout << "~CClass" << endl;
	}
	void Update() {
		cout << "나는 CClass다!" << endl;
	}
};


class CClassChild : public CClass{
public:
	float a;

public:
	CClassChild() {
		cout << "CClassChild" << endl;
	}
	~CClassChild() {
		cout << "~CClassChild" << endl;
	}
	void Update() {
		cout << "나는 CClassChild다!" << endl;
	}
};

class CClassChildChild : public CClassChild {
public:
	float b;

public:
	CClassChildChild() {
		cout << "CClassChildChild" << endl;
	}
	~CClassChildChild() {
		cout << "~CClassChildChild" << endl;
	}
	void Update() {
		cout << "나는 CClassChildChild다!" << endl;
	}
};

int main() {
	{
		CClass data;
		cout << "종료" << endl;
	}

	cout << "------------------" << endl;
	{
		CClassChild data;
		cout << "종료" << endl;
	}

	cout << "------------------" << endl;
	{
		CClassChildChild data;
		cout << "종료" << endl;
	}

	cout << "------------------" << endl;
	{
		CClass *Data = new CClassChildChild();

		cout << "종료" << endl;
		delete Data;
	}

	cout << "------------------" << endl;
	{
		CClassChildChild * pData = new CClassChildChild;
		delete pData;
	}


	//cout << "------------------" << endl;
	//{
	//	CClassChild data;
	//	CClassChildChild data2;

	//	data.a = 10;
	//	data2.a = 20;
	//	data2.b = 30;
	//	data = data2;

	//	cout << data.a << endl;
	//}

}