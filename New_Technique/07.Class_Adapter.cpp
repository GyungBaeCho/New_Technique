#include "stdafx.h"

//모든 객체를 다룰 객체의 Super Class 이다.
class CObject{
public:
	CObject(){}
	~CObject(){}
	
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
	~CUi(){}

	void UpdateUi(){ cout << "Ui - Button - Update" << endl; }
	void RenderUi(){ cout << "Ui - Button - Render" << endl; }
};

//CObject와 완전히 무관한 CButtonUi 객체를 CObject의 수퍼클래스로 동작시켜주는 Adapter
//-------------------------------------------------
class CObjectAdapter : public CObject, CUi{
public:
	CObjectAdapter(){}
	~CObjectAdapter(){}

	virtual void Update(){ CUi::UpdateUi(); }
	virtual void Render(){ CUi::RenderUi(); }
};

//-------------------------------------------------
int main(){
	vector<CObject*> vpObject;
	CObject* pNewObject = nullptr;

	vpObject.push_back(new CNpcObject);
	vpObject.push_back(new CObjectAdapter);
	
	for(CObject *pOBject : vpObject){
		pOBject->Update();
		pOBject->Render();
		cout << endl;
	}

	/*
	CObjectAdapter class의 Base class는 CObject 클래스이므로, 
	그 이외의 다중 상속자 클래스로는 다형성을 이룰 수 없다.
	CUi* pUi = new CObjectAdapter;
*/
}