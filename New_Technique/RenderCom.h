#pragma once

//dummy class
class CUiObject;

class CUiRenderCom{
private:

public:
	CUiRenderCom(){}
	~CUiRenderCom(){}
	
	void Render(CUiObject * pUiObject);

friend class CUiObject;
};

