#include "stdafx.h"
#include "Function_Tool.h"

vector<string> v;

struct T
{
	string A()
	{
		v.push_back("1");
		return "1"s;
	}

	string B()
	{
		v.push_back("2");
		return "2"s;
	}

	string C()
	{
		v.push_back("3");
		return "3"s;
	}
};

int main()
{
	T a;
	cout << a.A() << " " << a.B() << " " << a.C() << endl;

	cout << endl;

	for (auto&p : v)
		cout << p << " ";
}