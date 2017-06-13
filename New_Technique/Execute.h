#pragma once

//dummy class
class CUnit;

//-----------------------------------------------------
class CExecute{
private:

public:
	virtual void Update(CUnit* pUnit) = 0;
};

//-----------------------------------------------------
class CHpRecoverExecute{
private:

public:
	virtual void Update(CUnit* pUnit){
	//	cout << GetUnitTypeString(pUnit->GetUnitType()) << " : Player Updated" << endl;
	//	pUnit->
	}
};

//-----------------------------------------------------
class CPlayerExcute : public CExecute{
	virtual void Update(CUnit* pUnit);
};
