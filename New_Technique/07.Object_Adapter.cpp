#include "stdafx.h"

//Aggregation : 자신을 소유하고 있는 컨테이너가 소멸해도, 자신은 살아 있다.
//Composition : 자신을 소유하고 있는 컨테이너가 소멸하면, 자신도 소멸 된다.

//모든 객체를 다룰 객체의 Super Class 이다.
class CObject{
public:
	CObject(){}
	virtual ~CObject(){}
	
	virtual void Update() = 0;
	virtual void Render() = 0;
};

class CNpcObject : public CObject{
public:
	CNpcObject(){}
	~CNpcObject(){}

	virtual void Update(){ cout << "Object - NPC - Update" << endl; }
	virtual void Render(){ cout << "Object - NPC - Render" << endl; }
};


//CObject 객체와는 완전히 무관한 CUi 객체
//-------------------------------------------------
class CUi{
public:
	CUi(){}
	virtual ~CUi(){}

	virtual void UpdateUi() = 0;
	virtual void RenderUi() = 0;
};

class CButtonUi : public CUi{
public:
	CButtonUi(){}
	~CButtonUi(){}

	virtual void UpdateUi(){ cout << "Ui - Button - Update" << endl; }
	virtual void RenderUi(){ cout << "Ui - Button - Render" << endl; }
};

//CObject와 완전히 무관한 CUi 객체를 CObject의 수퍼클래스로 동작시킬 수 있는 Adapter
//-------------------------------------------------
class CObjectAdapter : public CObject{
	//Composition 객체.
	CUi* m_pUi;

public:
	CObjectAdapter() : m_pUi(nullptr){}
	CObjectAdapter(CUi* pUi) : m_pUi(pUi){}
	~CObjectAdapter(){ if(m_pUi) delete m_pUi; }

	virtual void Update(){ if(m_pUi) m_pUi->UpdateUi(); }
	virtual void Render(){ if(m_pUi) m_pUi->RenderUi(); }

};

int main(){
	vector<CObject*> vpObject;
	CObject* pNewObject = nullptr;

	vpObject.push_back(new CNpcObject);
	vpObject.push_back(new CObjectAdapter(new CButtonUi));
	
	for(CObject *pObject : vpObject){
		pObject->Update();
		pObject->Render();
		cout << endl;
	}
}