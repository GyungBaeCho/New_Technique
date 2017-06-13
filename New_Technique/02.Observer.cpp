#include "stdafx.h"
#include "Function_Tool.h"

struct SPlayerState{
	unsigned int	m_nMaxHp;		
	unsigned int	m_nHp;	
	unsigned int	m_nMaxMp;
	unsigned int	m_nMp;
	unsigned int	m_nMoney;

	SPlayerState(){
		m_nMaxHp	= 0;
		m_nHp		= 0;
		m_nMaxMp	= 0;
		m_nMp		= 0;
		m_nMoney	= 0;
	}
};

//------------------------------------------------------------------------------
class CObserver{
public:
	CObserver(){}
	~CObserver(){}

	virtual void Description() = 0;
	virtual void Update(SPlayerState& houseState) = 0;
};

class CStateAlarm : public CObserver{
public:
	CStateAlarm(){}
	~CStateAlarm(){}

	void Description() override{ cout << "CStateAlarm"; }
	void Update(SPlayerState& houseState) override{
		cout << "-----------CStateAlarm-----------" << endl;
		if(houseState.m_nHp < static_cast<int>(houseState.m_nMaxHp/10)) cout << "Ã¼·Â ¼öÀ§ ³·À½" << endl;
		if(houseState.m_nMp < static_cast<int>(houseState.m_nMaxMp/10)) cout << "¸¶³ª ¼öÀ§ ³·À½" << endl;
		if(houseState.m_nMoney == 0) cout << "ÆÄ»ê!" << endl;
		cout << endl;
	}
};

class CHealer : public CObserver{
public:
	CHealer(){}
	~CHealer(){}

	void Description() override{ cout << "CHealer"; }
	void Update(SPlayerState& houseState) override{
		cout << "-----------CHealer-----------" << endl;
		if(houseState.m_nHp < static_cast<int>(houseState.m_nMaxHp/2)) cout << "Èú!" << endl;
		cout << endl;
	}
};

//------------------------------------------------------------------------------
class CSubject{
private:

public:
	CSubject(){}
	~CSubject(){}

	virtual void AddObserver(CObserver* pObserver)		= 0;
	virtual void RemoveObserver(CObserver* pObserver)	= 0;
	virtual void NotifyObserver()						= 0;
};

class CPlayer: public CSubject{
public:
	list<CObserver*> m_lpObserver;
	SPlayerState m_State;

public:
	CPlayer(){}

	void AddObserver(CObserver* pObserver) override{
		pObserver->Description();
		cout << "-Added" << endl;
		m_lpObserver.push_back(pObserver);
	}
	void RemoveObserver(CObserver* pObserver) override{
		m_lpObserver.remove_if([&](CObserver* pPivot){
			if(pPivot == pObserver){
				pObserver->Description();
				cout << "-Removed" << endl;
				return true;
			}
			else return false;
		});
	}
	void NotifyObserver() override{
		for(CObserver* pObserver : m_lpObserver){
			pObserver->Update(m_State);
		}
	}
	void SetState(SPlayerState& state){
		m_State = state;
		NotifyObserver();
	}
};

//------------------------------------------------------------------------------
int main(){
	cout << "-----Observer Pattern-----" << endl << endl;

	SPlayerState state;
	state.m_nMaxHp = 100;
	state.m_nHp = 1;
	state.m_nMaxMp = 100;
	state.m_nMp = 1;
	state.m_nMoney;

	CPlayer* pPlayer = new CPlayer;
	pPlayer->SetState(state);

	CObserver* pCookCenter = new CStateAlarm;
	CObserver* pHealer = new CHealer;
	pPlayer->AddObserver(pCookCenter);
	pPlayer->AddObserver(pHealer);
	cout << endl;

	pPlayer->NotifyObserver();

	pPlayer->RemoveObserver(pCookCenter);
	pPlayer->RemoveObserver(pHealer);
	cout << endl;

	pPlayer->NotifyObserver();
} 