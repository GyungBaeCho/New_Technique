#include "stdafx.h"
#include "Function_Tool.h"

/*
	Critical Section
	Mutex
	Semaphore
*/

class CMesh{
private:

public:
	CMesh(){}
	~CMesh(){
		cout << "CMesh ¼Ò¸êÀÚ" << endl;
	}
};

class CObject{
private:
	CMesh* m_pMesh;

	CMesh m_Mesh;
	static int m_nLastId;
	int m_nId;

public:
	CObject(){
		m_pMesh = nullptr;

		m_nId = m_nLastId;
		m_nLastId++;
	}
	~CObject(){
		cout << m_nId << " : CObject ¼Ò¸êÀÚ" << endl;

		if(m_pMesh) delete m_pMesh;
	}

	void SetMesh(CMesh* pMesh){
		m_pMesh = pMesh;
	}

};

CRITICAL_SECTION critical_section;
mutex mut;
volatile int num = 0;

const int LoopNum = 1000000;

void ThreadCriticalFunc(){
	for(int i=0 ; i<LoopNum ; ++i){
		EnterCriticalSection(&critical_section);
		num++;
		LeaveCriticalSection(&critical_section);
	}
}

void ThreadMutexFunc(){
	for(int i=0 ; i<LoopNum ; ++i){
		mut.lock();
		num++;
		mut.unlock();
	}
}

int main(){
	CStopWatch watch;

	//CMesh* pMesh = new CMesh;
	//CObject* pObject = new CObject;
	//pObject->SetMesh(pMesh);
	//delete pObject;

	InitializeCriticalSection(&critical_section);

	watch.BeginTimer();
	thread th1 = thread{ThreadCriticalFunc};
	thread th2 = thread{ThreadCriticalFunc};
	th1.join();
	th2.join();
	watch.EndTimer();
	cout << num << endl;
	num = 0;

	watch.BeginTimer();
	thread th8 = thread{ThreadMutexFunc};
	thread th9 = thread{ThreadMutexFunc};
	th8.join();
	th9.join();
	watch.EndTimer();
	cout << num << endl;
} 

int CObject::m_nLastId = 0;