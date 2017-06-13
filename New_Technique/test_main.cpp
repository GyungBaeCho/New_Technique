#include "stdafx.h"
#include "UiObject.h"

int main(){

	CUiObject UiObject;
	CUiRenderCom Com;

	UiObject.SetRenderCom(&Com);
	UiObject.Render();

} 