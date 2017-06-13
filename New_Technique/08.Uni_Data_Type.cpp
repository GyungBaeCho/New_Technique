#include "stdafx.h"

#define CONSOL_OUTPUT

class CDataType{
private:

public:
	CDataType(){}
	virtual ~CDataType(){}

	virtual const type_info& GetType() const = 0;
	virtual void PrintData() = 0;
};

template<typename TYPE>
class CTempDataType : public CDataType{
private:
	TYPE m_Data;

public:
	CTempDataType(TYPE Data) : m_Data(Data){}
	virtual ~CTempDataType(){}
	
	virtual const type_info& GetType() const{ return typeid(TYPE); }
	virtual void PrintData(){ cout << m_Data << endl; }
	TYPE& GetData(){ return m_Data; }
};

class CUniDataType{
private:
	CDataType* m_pData;

public:
	CUniDataType() : m_pData(nullptr){
#ifdef CONSOL_OUTPUT
		cout << "기본 생성자 : " << this << endl;
#endif
	}

	template<typename TYPE>
	CUniDataType(TYPE data){
		m_pData = new CTempDataType<TYPE>(data);

#ifdef CONSOL_OUTPUT
		cout << "템플 생성자 : " << this << endl;
#endif
	}

	CUniDataType(CUniDataType& data){
		cout << "복사 생성자 : " << this << endl;
	}

	CUniDataType(CUniDataType&& data){
		cout << "이동 생성자 : " << this << endl;
	}

	~CUniDataType(){
		if(m_pData) delete m_pData;
	//	m_pData = nullptr;
#ifdef CONSOL_OUTPUT
		cout << "소멸자      : " <<  this << endl;
#endif
	}
	 
//	CUniDataType &operator=(const CUniDataType &copy) = default;

	//CUniDataType &operator=(CUniDataType &copy){
	//	m_pData = move(copy.m_pData);
	//	copy.m_pData = nullptr;
	//	return *this;
	//}

	CUniDataType &operator=(CUniDataType &copy){
		
		m_pData = move(copy.m_pData);
		copy.m_pData = nullptr;
#ifdef CONSOL_OUTPUT
		cout << "데이터 이동 : " << &copy << " ----> " << this <<  endl;
#endif
		return *this;
	}
	 
	const type_info& GetType() const{ return (m_pData != nullptr) ? m_pData->GetType() : typeid(nullptr); }

	CDataType* GetData(){ return m_pData; }

	void PrintData(){
		cout << "PrintData : " << m_pData << " : ";
		m_pData->PrintData();
	}
};

int main(){

	map<string, CUniDataType> mUniData;
	mUniData["HP"] = CUniDataType(100.1);
	cout << endl;
	mUniData["POSITION"] = CUniDataType(D3DXVECTOR3(0, 0, 0));
	
	cout << endl;
	cout << endl;

	map<string, CUniDataType*> mpUniData;
	mpUniData["HP"] = new CUniDataType(100.1);
	mpUniData["POSITION"] = new CUniDataType(D3DXVECTOR3(1000, 0, 0));

	cout << endl;

#ifdef CONSOL_OUTPUT
	cout << "----------------------exit Program----------------------" << endl;
#endif
}
