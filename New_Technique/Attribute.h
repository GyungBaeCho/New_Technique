#pragma once

//-----------------------------------------------------
enum class ATTRIBUTE_TYPE{
	HP,
	MP,
	DAMAGE,
};

enum class DATA_TYPE{
	INT,
	UINT,
	FLOAT,
	DOUBLE,
	VECTOR3,
	VECTOR4,
	MATRIX,
};

string GetAttributeTypeString(ATTRIBUTE_TYPE attriType);

//-----------------------------------------------------
//#define interface
//
//struct interface DataType{
//	virtual DataType* copy() = 0;
//	virtual const type_info& type() const = 0;
//};

//-----------------------------------------------------
class CAttribute{
private:
	const ATTRIBUTE_TYPE m_AttributeType;
	const DATA_TYPE m_DataType;
//	TEMP_TYPE m_Data;

public:
	CAttribute(DATA_TYPE dataType, ATTRIBUTE_TYPE attriType) : m_DataType(dataType), m_AttributeType(attriType){}
	virtual ~CAttribute(){	}

	const ATTRIBUTE_TYPE& GetAttributeType(){ return m_AttributeType; }
	const string& GetAttributeTypeString(){ return ::GetAttributeTypeString(m_AttributeType); }
};


////-----------------------------------------------------
//class CFloatAttribute : public CAttribute{
//private:
//	float m_fData;
//
//public:
//	CFloatAttribute(DATA_TYPE dataType, ATTRIBUTE_TYPE attriType) : CAttribute(dataType, attriType){}
//	virtual ~CFloatAttribute(){}
//
//	const float& GetFloat(){ return m_fData; }
//
//	virtual auto GetData() -> float { return m_fData; }
//};
