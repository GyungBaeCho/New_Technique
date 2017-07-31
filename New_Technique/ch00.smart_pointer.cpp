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
	smart_ptr() {}
	smart_ptr(T* pData) {
		m_pData = pData;
		m_pCount = new int(1);
	}
	~smart_ptr() {
		Release();
	}

	int GetRefCount() {
		return *m_pCount;
	}

	T& operator*() const {
		return *m_pData;
	}
	T* operator->() const {
		return m_pData;
	}
	void operator=(T* pData) {
		Release();
		m_pData = pData;
		m_pCount = new int(1);
	}
	smart_ptr<T>& operator=(smart_ptr<T>& pSmart_Pointer) {
		m_pData = pSmart_Pointer.m_pData;
		m_pCount = pSmart_Pointer.m_pCount;
		(*m_pCount)++;
		
		m_pNext = &pSmart_Pointer;
		m_pPrev = pSmart_Pointer.m_pPrev;

		pSmart_Pointer.m_pPrev->m_pNext = this;
		pSmart_Pointer.m_pPrev = this;

		return *this;
	}

private:
	void Release() {
		if (m_pPrev == this) {
			if (m_pData) {
				delete m_pData;
			}
			if (m_pCount) {
				delete m_pCount;
			}
		}
		else {
			m_pPrev->m_pNext = m_pNext;
			m_pNext->m_pPrev = m_pPrev;
			m_pPrev = m_pNext = this;
			(*m_pCount)--;
		}
		m_pData = nullptr;
	}

private:
	T* m_pData = nullptr;
	smart_ptr<T>* m_pPrev = this;
	smart_ptr<T>* m_pNext = this;
	int* m_pCount = nullptr;
};

class DATA {
public:
	~DATA(){
		cout << "Data ¼Ò¸ê" << endl;
	}

	int data = 100;
};


int main(){
	smart_ptr<DATA> p1(new DATA);
	smart_ptr<DATA> p2;
	smart_ptr<DATA> p3;
	smart_ptr<DATA> p4;
	smart_ptr<DATA> p5;
	smart_ptr<DATA> p6;

	cout << p1.GetRefCount() << endl;
	p2 = p1;
	cout << p1.GetRefCount() << endl;
	p3 = p2;
	cout << p1.GetRefCount() << endl;
	p4 = p3;
	cout << p1.GetRefCount() << endl;
	p5 = p4;
	cout << p1.GetRefCount() << endl;
	p6 = p5;
	cout << p1.GetRefCount() << endl;

	p1 = nullptr;
	p2 = nullptr;
	p3 = nullptr;
	p4 = nullptr;
	p5 = nullptr;
	p6 = nullptr;

	cout << "end" << endl;
} 