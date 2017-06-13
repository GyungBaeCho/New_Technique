#include "stdafx.h"

//#include <iostream>
//#include <list>
//#include "Function_Tool.h"

class CObject{
	float matrix[16];

};

template<typename T>
class CObjectPool{
private:
	list<T*> m_lpObjectPool;

public:
	//만일 pool에 이미 데이터가 있다면 가져다 쓰고, 없다면 새로 할당해서 반환한다.
	T* NewObject(){
		if(m_lpObjectPool.size() != 0){
			CObject* pReturn = m_lpObjectPool.front();
			m_lpObjectPool.pop_front();
			return pReturn;
		}
		else{
			return new T;
		}
	}

	//객체를 삭제할 일이 있으면, 삭제하지 말고 여기에 넣어라.
	void RemoveObject(T* pObject){
		m_lpObjectPool.push_back(pObject);
		pObject = nullptr;
	}
};

int main(){
	CObject* pObject;


	cout << "Non-Pooling" << endl;
	BeginTimer();
		for(int i=0 ; i<100000 ; i++){
			pObject = new CObject;
			delete pObject;
		}
	EndTimer();
	cout << endl;

	CObjectPool<CObject> objectPool;;
	cout << "Pooling" << endl;
	BeginTimer();
		for(int i=0 ; i<100000 ; i++){
			pObject = objectPool.NewObject();
			objectPool.RemoveObject(pObject);
		}
	EndTimer();
	cout << endl;

}

/*
//데이터를 동적으로 생성하고 삭제하는 것이 아니라 Pooling을 사용하는것이 얼마나 성능 향상에 도움이 되는지를 테스트.
-------------Result

,400,000

Debug	: 0.0037081
result	: 0.0006744

*/