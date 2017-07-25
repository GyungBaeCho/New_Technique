#include "stdafx.h"
#include "Function_Tool.h"

class AAA {
public:
	AAA() {}
	~AAA() {
		cout << "¼Ò¸ê" << endl;
	}
};


template<class T>
class smart_ptr {
public:
	smart_ptr(T* pData) {
		m_pData = pData;
		m_nRef = 1;
	}

	smart_ptr<T*>& operator=(smart_ptr<T*>& pData) {
		m_pData = pData->m_pData;
		return this;
	}

	T* Get() {
		retrun m_pData;
	}

private:
	T* m_pData = nullptr;
	int m_nRef = 0;

};

int main(){
//	shared_ptr<AAA> ptr(new AAA);
	shared_ptr<AAA> ptr;
	ptr = make_shared<AAA>();
	shared_ptr<AAA> ptr2 = ptr;

	ptr.get();

	ptr2 = nullptr;
	ptr = nullptr;
	cout << "-----------------------" << endl << endl;


	cout << "Á¾·á" << endl;
} 