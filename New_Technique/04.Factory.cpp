#include "stdafx.h"

/*
원칙 1 : 바뀔 수 있는 부분을 찾아내서 바뀌지 않는 부분과 분리시켜야 함.

원칙 : 특정 구현을 바탕으로 프로그래밍 하지 마라

new는 구상 객체이다.
	구상 클랫스의 인스턴스를 만드는 것이다.
	new를 사용하는 것은 결국 특정 구현을 사용하는 것이므로, 원칙에 위배된다.
*/


/*
	간단한 팩토리 패턴			: 객체 생성을 처리하는 클래스

	팩토리 메소드 패턴	: 객체를 생성하기 위한 인터페이스 class로 어떤 객체를 만들지에 대한 것은
						  서브 클래스에서 결정하도록 만든 패턴

	정적 팩토리 패턴	: 팩토리 class의 인스턴스를 생성할 필요 없이 사용할 수 있도록 한 팩토리
						  다만 서브 클래스를 만들어서 행동을 변경시킬 수 없다?? 뭐지
*/

#define SIMPLE_FACTORY

#define METHOD_FACTORY


enum class UnitType{
	//Terran
	MARINE,
	SCV,
	MEDIC,

	//Protoss
	PROBE,
	CARRIER,
	DARK_TEMPLAR,
};

class CUnit{
public:
	virtual void Render() = 0;
};

class CMarine : public CUnit{
public:
	virtual void Render(){
		cout << "Marine" << endl;
	};
};

class CScv : public CUnit{
public:
	virtual void Render(){
		cout << "Scv" << endl;
	};
};

class CMedic : public CUnit{
public:
	virtual void Render(){
		cout << "Medic" << endl;
	};
};


class CProbe : public CUnit{
public:
	virtual void Render(){
		cout << "Probe" << endl;
	};
};

class CCarrier : public CUnit{
public:
	virtual void Render(){
		cout << "Carrier" << endl;
	};
};

class CDarkTemplar : public CUnit{
public:
	virtual void Render(){
		cout << "DarkTemplar" << endl;
	};
};


class CUnitFactory{
	vector<CUnit*> m_vpUnit;
public:
	virtual CUnit* CreateObject(UnitType objType) = 0;
	void AddObject(UnitType objType){
		CUnit* pUnit = nullptr;
		pUnit = CreateObject(objType);

		pUnit->Render();
		m_vpUnit.push_back(pUnit);
	}
};

class CTerranFactory : public CUnitFactory{
public:
	virtual CUnit* CreateObject(UnitType objType){
		switch(objType){
		case  UnitType::MARINE:
			return new CMarine;
		case  UnitType::SCV:
			return new CScv;
		case  UnitType::MEDIC:
			return new CMedic;
		default:
			cout << "잘못된 데이터 입력" << endl;
			exit(-1);
		}
	}
};

class CProtossFactory : public CUnitFactory{
public:
	virtual CUnit* CreateObject(UnitType objType){
		switch(objType){
		case  UnitType::PROBE:
			return new CProbe;
		case  UnitType::CARRIER:
			return new CCarrier;
		case  UnitType::DARK_TEMPLAR:
			return new CDarkTemplar;
			default:
			cout << "잘못된 데이터 입력" << endl;
			exit(-1);
		}
	}
};

int main(){
	CUnitFactory *pTerranFactory = new CTerranFactory;
	CUnitFactory *pProtossFactory = new CProtossFactory;

	pTerranFactory->AddObject(UnitType::MARINE);
	pTerranFactory->AddObject(UnitType::MARINE);
	pTerranFactory->AddObject(UnitType::MARINE);
	pTerranFactory->AddObject(UnitType::MEDIC);

	pProtossFactory->AddObject(UnitType::PROBE);
	pProtossFactory->AddObject(UnitType::DARK_TEMPLAR);
	pProtossFactory->AddObject(UnitType::DARK_TEMPLAR);
}