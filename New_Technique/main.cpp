#include "stdafx.h"
#include "Unit.h"

using namespace std;

class CDataType{
private:

public:
	CDataType(){}
	virtual ~CDataType(){}

	virtual const type_info& GetType() const = 0;

//	virtual auto GetData(){}

	virtual void PrintData() = 0;
};

template<typename TYPE>
class CTempDataType : public CDataType{
private:
	TYPE m_Data;

public:
	CTempDataType(TYPE Data) : m_Data(Data){}
	virtual ~CTempDataType(){}

	virtual const type_info& GetType() const{
		return typeid(TYPE);
	}

//	virtual TYPE GetData(){ return m_Data; }

	virtual void PrintData(){
		cout << m_Data << endl;
	}
};

class CUniDataType{
private:
	CDataType* m_pData;

public:
	CUniDataType() : m_pData(nullptr){}
	
	CUniDataType(CDataType* data){
		cout << "持失切2 : " << m_pData << " : ";
		m_pData = data;
	}

	template<typename TYPE>
	CUniDataType(TYPE data){
		m_pData = new CTempDataType<TYPE>(data);
		cout << "持失切 : " << m_pData << " : ";
		m_pData->PrintData();
	}

//	CUniDataType(TYPE data) : m_pData(new CTempDataType<TYPE>(data)){}

	~CUniDataType(){
		cout << "社瑚切 : " << m_pData << endl;
	//	m_pData->PrintData();
	//	if(m_pData) delete m_pData;
	//	m_pData = nullptr;
	}
	 
	const type_info& GetType() const{
		return (m_pData != nullptr) ? m_pData->GetType() : typeid(nullptr);
	}

	CDataType* GetData(){
//		const type_info type = m_pData->GetType();
		return m_pData;
		
	}

	void PrintData(){
		cout << "PrintData : " << m_pData << " : ";
		m_pData->PrintData();
	}
};



int main(){
	//map<string, CUniDataType*> mpUniData;
	//mpUniData["HP"] = new CUniDataType(100.1);

	//exit(-1);

	map<string, CUniDataType> mUniData;
	mUniData["HP"] = 10.1;
	mUniData["NAME"] = "LOOKA";

	mUniData["NAME"].PrintData();
	mUniData["HP"].PrintData();

//	Sleep(10000);

	//cout << endl;
	//cout << mUniData["NAME"].GetType().name() << endl;
	//cout << mUniData["WORLD_MATRIX"].GetType().name() << endl;
	//cout << mUniData["WO_MATRIX"].GetType().name() << endl;


	//list<CUnit*> lpUnit;
	//CUnit* pUnit = nullptr;

	//pUnit = new CUnit(UNIT_TYPE::PLAYER);
	////pUnit->AddAttribute(new CFloatAttribute(DATA_TYPE::FLOAT, ATTRIBUTE_TYPE::HP)); 
	////pUnit->AddAttribute(new CFloatAttribute(DATA_TYPE::FLOAT, ATTRIBUTE_TYPE::MP));
	////pUnit->AddAttribute(new CFloatAttribute(DATA_TYPE::FLOAT, ATTRIBUTE_TYPE::DAMAGE));
	//pUnit->AddExecute(new CPlayerExcute);
	//lpUnit.push_back(pUnit);

	//pUnit = new CUnit(UNIT_TYPE::PLAYER);
	//pUnit->AddExecute(new CPlayerExcute); 
	//lpUnit.push_back(pUnit); 

	//UINT sceneNum = 0;

	////while(true){
	////	Sleep(1000);
	////
	////	cout << sceneNum << " #-------------------" << endl;
	////	for(CUnit* pUnit : lpUnit){
	////		pUnit->Update();
	////	}

	////	cout << endl;
	////	sceneNum++;
	////}
}
