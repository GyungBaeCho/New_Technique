#include "stdafx.h"

//---------------------------------------------------음료
//Beverage와 Ingredient를 순수 가상클래스로 만들기 위하여 인위적으로 GetCost() 메소드를 순수 가상함수로 지정하였다.
//class CBeverage{
//private:
//
//protected:
//	float m_cost;
//	string m_sDescription;
//
//public:
//	CBeverage(){}
//	virtual ~CBeverage(){ cout << "Beverage 소멸 ->" << endl; }
//	virtual string GetDescription() const { return m_sDescription; }
//	virtual float GetCost() const = 0;
//	virtual void GetBill() const { cout << GetDescription() << " :  $ " << GetCost() << endl; }
//};
//
//class CEspresso : public CBeverage{
//public:
//	CEspresso(){
//		m_cost = 1.99;
//		m_sDescription = "에스프레소";
//	}
//	virtual ~CEspresso(){ cout << "Espresso 소멸 ->" << endl; }
//	virtual float GetCost() const { return m_cost; }
//};
//
//class CHouseBlend : public CBeverage{
//public:
//	CHouseBlend(){ 
//		m_cost = 0.89;
//		m_sDescription = "하우스 블렌드"; 
//	}
//	virtual ~CHouseBlend(){ cout << "HouseBlend 소멸 ->" << endl; }
//	virtual float GetCost() const { return m_cost; }
//};
//
////---------------------------------------------------추가
//class CIngredient : public CBeverage{
//private:
//
//protected:
//	CBeverage* m_pBeverage;
//
//public:
//	CIngredient(){}
//	virtual ~CIngredient(){ cout << "Ingredient 소멸 ->" << endl; delete m_pBeverage; }
//	virtual string GetDescription() const { return m_pBeverage->GetDescription() + ", " + m_sDescription; }
//	void GetBill() const { cout << m_pBeverage->GetDescription() + ", " + m_sDescription << " :  $ " << m_pBeverage->GetCost() + m_cost << endl; }
//};
//
//class CMocha : public CIngredient{
//private:
//	
//public:
//	CMocha(CBeverage* pBeverage){ 
//		m_sDescription = "모카";
//		m_cost = 0.2;
//		m_pBeverage = pBeverage; 
//	}
//	virtual ~CMocha(){ cout << "Mocha 소멸 ->" << endl; }
//	virtual float GetCost() const { return m_cost + m_pBeverage->GetCost(); }
//};
//
//class CSoy : public CIngredient{
//private:
//
//public:
//	CSoy(CBeverage* pBeverage){
//		m_sDescription = "두유";
//		m_cost = 0.3;
//		m_pBeverage = pBeverage; 
//	}
//	virtual ~CSoy(){ cout << "Soy 소멸 ->" << endl; }
//	virtual float GetCost() const { return m_cost + m_pBeverage->GetCost(); }
//};
//
//class CWhip : public CIngredient{
//private:
//
//public:
//	CWhip(CBeverage* pBeverage){
//		m_sDescription = "휘핑크림";
//		m_cost = 0.25;
//		m_pBeverage = pBeverage; 
//	}
//	virtual ~CWhip(){ cout << "Whip 소멸 ->" << endl; }
//	virtual float GetCost() const { return m_cost + m_pBeverage->GetCost(); }
//};
//
//int main(){
//	CBeverage* pBeverage = new CEspresso;
//	pBeverage = new CMocha(pBeverage);
//	pBeverage = new CWhip(pBeverage);
//	pBeverage->GetBill();
//	delete pBeverage;
//	cout << endl << endl;
//
//	pBeverage = new CHouseBlend;
//	pBeverage = new CMocha(pBeverage);
//	pBeverage = new CMocha(pBeverage);
//	pBeverage = new CWhip(pBeverage);
//	pBeverage->GetBill();
//	delete pBeverage;
//	cout << endl << endl;
//
//	pBeverage = new CHouseBlend;
//	pBeverage = new CWhip(pBeverage);
//	pBeverage->GetBill();
//	delete pBeverage;
//	cout << endl << endl;
//
//	getch();
//}
//
//


class CIngredient{
private:
	CIngredient*	m_pBeverage;
	string			m_nName;
	float			m_fCost;

private:
	CIngredient(){}

public:
	CIngredient(string sName, float fCost){
		m_pBeverage = nullptr;
		m_nName = sName;
		m_fCost = fCost;
	}
	CIngredient(CIngredient* pIngredient, string sName, float fCost){
		m_pBeverage = pIngredient;
		m_nName = sName;
		m_fCost = fCost;
	}
	~CIngredient(){}

	string GetName(){
		return (m_pBeverage) ? m_pBeverage->GetName() + ", " + m_nName : m_nName; 
	}
	float GetCost(){
		return (m_pBeverage) ? m_pBeverage->GetCost() + m_fCost : m_fCost; 
	}
};

int main(){
	CIngredient* pIngredient = new CIngredient("Americano", 10);
	pIngredient = new CIngredient(pIngredient, "Moca", 3);
	pIngredient = new CIngredient(pIngredient, "Cheese", 2);
	pIngredient = new CIngredient(pIngredient, "Shot", 7);
	pIngredient = new CIngredient(pIngredient, "Sugar", 1);

	cout <<  pIngredient->GetName() << " : " << pIngredient->GetCost() << endl;
}