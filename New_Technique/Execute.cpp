#include "stdafx.h"

#include "Execute.h"
#include "Unit.h"

void CPlayerExcute::Update(CUnit * pUnit){
	cout << GetUnitTypeString(pUnit->GetUnitType()) << " : Player Updated" << endl;

//	cout << "Player Updated" << endl;
}
