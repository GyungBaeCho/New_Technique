#include "stdafx.h"

class AAA{
private:
	int* m_pData;

public:
	AAA(){
		cout << this << " : 생성자" << endl;
		m_pData = new int(0);
	}
	AAA(int num){
		cout << this << " : 생성자" << endl;
		m_pData = new int(num);
	}
	AAA(AAA& a) : m_pData(a.m_pData){
		cout << this << " : 복사생성자" << endl;
		a.m_pData = nullptr;
	}
	AAA(AAA&& a){
		cout << this << " : 이동생성자" << endl;
		*this = move(a);

		a.m_pData = nullptr;
	//	m_pData = a.m_pData;
	//	a.m_pData = nullptr;
	}
	~AAA(){
		cout << this << " : 소멸자" << endl;
		if(m_pData) delete m_pData;
	}

	AAA &operator=(const AAA &copy) = default;

	int* GetData(){ return m_pData; }
};

int main(){
	vector<AAA> v1;
//	v1.emplace_back(AAA(100));
	v1.push_back(AAA(100));
	cout << *v1[0].GetData() << endl;

//위의 코드에서 문제가 발생하는 원인
/*
	vector Container의 자료형인 AAA는 포인터가 아닌 객체 그 자체다.
*/

	cout << endl;

	vector<AAA*> v2;
	v2.push_back(new AAA(100));
	cout << *(v2[0]->GetData()) << endl;
}