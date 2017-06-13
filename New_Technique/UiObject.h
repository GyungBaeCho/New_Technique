#pragma once
#include "RenderCom.h"

//dummy class
class CUiRenderCom;

class CUiObject{
private:
	int x					= 100;
	int y					= 200;
	CUiRenderCom* m_pUiRender = nullptr;

public:
	CUiObject(){}
	~CUiObject(){}

	void SetRenderCom(CUiRenderCom* pUiRender){
		m_pUiRender = pUiRender;
	}

	void Render(){
		m_pUiRender->Render(this);
	}
friend class CUiRenderCom;
};