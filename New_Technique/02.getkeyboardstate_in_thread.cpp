#include "stdafx.h"

//#include <iostream>
//#include <memory>
//#include <thread>
//#include <conio.h>
//#include <vector>
//#include <Windows.h>
//#include <vector>

#define VK_W									0x57

void ThreadFunc(){
	UCHAR pKeyBuffer[256];
	static int num = 0;

	while(true){
		//if(GetAsyncKeyState(VK_SPACE)){
		//	cout << "zzz" << endl;
		//}
		//if(GetAsyncKeyState(VK_W)){
		//	cout << "www" << endl;
		//}

		if(_kbhit()){
			if(GetAsyncKeyState(VK_W))
				cout << "W" << endl;
			if(GetAsyncKeyState(VK_SHIFT))
				cout << "SHIFT" << endl;
			if(GetAsyncKeyState(VK_SPACE))
				cout << "SPACE" << endl;

			//if (GetKeyboardState(pKeyBuffer)){
			//	if (pKeyBuffer[VK_SHIFT] & 0xF0)
			//		cout << num++ << endl;
			//	if (pKeyBuffer[VK_W] & 0xF0)
			//		cout << num++ << endl;
			//}
		}
	}
}

void PrintToBinary(DWORD dwData){
	vector<int> vInt;

	cout << dwData << " : ";
	while(true){
		if(dwData == 0) break;
		else if(dwData == 1){
			vInt.push_back(dwData);
			break;
		}

		int remain = dwData%2;
		vInt.push_back(remain);
		dwData/=2;
	}

	for(int i=vInt.size()-1 ; i>=0 ; --i){
		cout << vInt[i];
	}
	cout << endl;

}

int main(){
	printf("%x\n", 256);

	PrintToBinary(0x01);
	PrintToBinary(0x02);
	PrintToBinary(0x04);
	PrintToBinary(0x08);
	PrintToBinary(0x10);
	PrintToBinary(0x20);
	PrintToBinary(0x40);
	PrintToBinary(0x80);
	PrintToBinary(0x100);


	UCHAR pKeyBuffer[256];
	static int num = 0;
//	thread thread{ThreadFunc};

//	while(true);
	
}