#include "stdafx.h"
#include "Function_Tool.h"

class CBehavior{
public:
	CBehavior(){}
	~CBehavior(){}

	virtual void Behave() = 0;
};

class CStand : public CBehavior{
public:
	CStand(){}
	~CStand(){}

	void Behave() override {	cout << "가만히 서있기" << endl << endl;	}
};

class CPunch : public CBehavior{
public:
	CPunch(){}
	~CPunch(){}

	void Behave() override {	cout << "주먹 공격!" << endl << endl;	}
};

class CKick : public CBehavior{
public:
	CKick(){}
	~CKick(){}

	void Behave() override {	cout << "발차기 공격!" << endl << endl;	}
};

class CObject{
private:
	CBehavior* m_pBehavior;

public:
	CObject(){
		m_pBehavior = nullptr;
	}
	~CObject(){}

	void SetBehavior(CBehavior* pBehavior){
		m_pBehavior = pBehavior;
	}

	void Behave(){
		if(m_pBehavior) m_pBehavior->Behave();
		else cout << "동작 없음" << endl << endl;
	}
};

int main(){
	std::cout << "-----Strategy Pattern-----" << std::endl;
	
	CBehavior* pStandBehavior = new CStand;
	CBehavior* pPunchBehavior = new CPunch;
	CBehavior* pKickBehavior = new CKick;

	CObject* pPlayer = new CObject;

	pPlayer->SetBehavior(pStandBehavior);
	pPlayer->Behave();

	pPlayer->SetBehavior(pPunchBehavior);
	pPlayer->Behave();

	pPlayer->SetBehavior(pKickBehavior);
	pPlayer->Behave();
} 