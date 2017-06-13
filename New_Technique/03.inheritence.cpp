#include "stdafx.h"

//#include <iostream>

class CFather{
private:

protected:
	void SetA(){}

public:
	void ShowA(){}

};

class CSon : private CFather{
private:

protected:
	void SetB(){}

public:

	void ShowB(){}

	void Init(){
		SetA();
		ShowA();
	}
};

class CGrandSon : private CSon{
private:

protected:
public:
	void SetAB(){ 

	//	SetA();
	//	ShowA();
		SetB();
		ShowB();
	}
};

class CGrandGrandSon : private CGrandSon{
private:

protected:
public:
	void Init(){
		SetB();
	}
};



int main(){

}