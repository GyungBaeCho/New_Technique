#pragma once
#include "Execute.h"
#include "Attribute.h"

enum class UNIT_TYPE{
	PLAYER,
};

//UNIT_TYPE Enum에 대한 정보를 출력합니다.
string GetUnitTypeString(const UNIT_TYPE& unitType);

//-----------------------------------------------------
//객체 Attribute Map
typedef map<ATTRIBUTE_TYPE, CAttribute*> Attribute;

//객체 Execute List
typedef list<CExecute*> ExecuteList;

class CUnit{
private:
	const UNIT_TYPE m_UnitType;		//한번 정해진 객체 Type은 변할 수 없다.
	Attribute* m_pAttribute;		//Compisition
	ExecuteList* m_pExecuteList;	//Aggregation

protected:

public:
	CUnit(UNIT_TYPE unitType) : m_UnitType(unitType),
								m_pAttribute(nullptr), 
								m_pExecuteList(nullptr)
	{		
	//	m_UnitType = unitType;		
	}
	virtual ~CUnit(){
		if(m_pAttribute){
			Attribute::iterator pvt = m_pAttribute->begin();
			Attribute::iterator end = m_pAttribute->end();

			for(pvt ; pvt!=end ; ++pvt) delete pvt->second;

			delete m_pAttribute;
			m_pAttribute = nullptr;
		}
	}

	void AddExecute(CExecute* pExecute){		
		if(m_pExecuteList){
			m_pExecuteList->push_back(pExecute);		
		}
		else{
			m_pExecuteList = new ExecuteList;
			m_pExecuteList->push_back(pExecute);
		}
	}

	void AddAttribute(CAttribute* pAttribute){
		if(m_pAttribute){
			(*m_pAttribute)[pAttribute->GetAttributeType()] = pAttribute;
		}
		else{
			m_pAttribute = new Attribute;
			(*m_pAttribute)[pAttribute->GetAttributeType()] = pAttribute;
		//	m_pAttribute->operator[](attriType) = pAttribute;
		}
	}

	void Update();

	const UNIT_TYPE& GetUnitType(){		return m_UnitType;		}
	const string& GetUnitTypeString(){ return ::GetUnitTypeString(m_UnitType); }
};
