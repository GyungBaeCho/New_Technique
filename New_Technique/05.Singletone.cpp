#include "stdafx.h"

/*
	Singletone 객체의 장점은,

	인스턴스가 하나만 생성되도록하여 오류를 미연에 방지하고,

	메모리 소비량이 많은 객체이지만, 사용량이 적을 경우, '게으른 생성'을 통하여 컴파일중에 바로 생성하여

	메모리를 낭비하지 않는다는 점이 있다.


	[전역변수]같은 경우는 컴파일시에 바로 메모리가 할당되므로, 좋지 못하다는 것인데..

	C++에서는 Java와 달리 포인터를 지원하니 이런 문제가 없는거 아닌가???
*/ 

class CSingletone{
private:
	static CSingletone* m_pInstance;

private:
	CSingletone(){
		cout << "싱글톤 생성!" << endl; 
	}
	~CSingletone(){}

public:
	static void CreateSingletone(){ if(!m_pInstance) m_pInstance = new CSingletone; }
	static CSingletone* GetInstance(){ return m_pInstance; }

	void Render(){ 
		cout << "나는 Singletone!!" << endl; 
	}
};

_declspec(selectany) CSingletone* CSingletone::m_pInstance = nullptr;

int main(){
	CSingletone::CreateSingletone();
	CSingletone::GetInstance()->Render();

	cout << CSingletone::GetInstance() << endl;
}

//#pragma pack(push, 1)
//struct pack {
//    char array[9];
//    int    len;
//};
//#pragma pack(pop)
//
//class CSingletone{
//private:
//	static CSingletone m_Instance;
//
//private:
//	CSingletone(){}
//	~CSingletone(){}
//
//public:
//	static CSingletone* GetInstance(){
//		return &m_Instance; 
//	}
//
//	void Render(){ 
//		cout << "나는 Singletone!!" << endl; 
//	}
//};
//_declspec(selectany) CSingletone CSingletone::m_Instance;
//
//int main(){
//	CSingletone::GetInstance()->Render();
//
//	cout << endl << CSingletone::GetInstance() << endl;
//}
//
//
//
#define SINGLETONE(type)								\
		public:											\
		static type* GetInstance(){						\
			static type instance;						\
			return &instance;							\
		}

class CObject{
private:

private:

public:
	SINGLETONE(CObject);

	void Render(){
		cout << "나도 싱글톤이다" << endl;
	}
};

int main(){
	CObject::GetInstance()->Render();
}
//	atexit();