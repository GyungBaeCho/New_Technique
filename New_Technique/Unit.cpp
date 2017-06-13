#include "stdafx.h"
#include "Unit.h"

string GetUnitTypeString(const UNIT_TYPE& unitType){
	switch(unitType){
	case UNIT_TYPE::PLAYER:
		return "PLAYER";
	default:
		return "UNIT_TYPE Unknown";
	}
}

void CUnit::Update(){ 
	if(m_pExecuteList == nullptr) return;

	for(CExecute* pExecute : *m_pExecuteList) 
		pExecute->Update(this);
}

