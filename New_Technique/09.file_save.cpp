#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(){
//
//	int integer = 123456789;
//	char arr[4];
//	char *pChar;
//
///*
//	CHAR = 1byte
//	INT	 = 4byte
//
//	바이트 사이즈가 위와 같기 때문에.
//	byte단위로 int를 저장하려면, int를 4개의 byte단위로 쪼개서 4개를 모두 저장해야 한다.
//
//	만일 int를 char형으로 type casting 한 다음에 하나만 저장하게 되면, 4개중 1개의 byte만 저장이 되므로,
//	당연히 데이터는 깨지게 된다.
//*/
//
//	// inteager 자료형을 char* 형태로 형변환 하여 4byte를 각각 배열로 참조할 수 있도록 한다.
//	pChar = (char*)(&integer);
///*
//	형변환에는 여러가지 방법이 있는데, 재미있게도 static_cast<>는 되지 않는다.
//
//	reinterpret_cast<>같은 경우는 강제로 형태를 바꾸는 것으로 이것을 사용하기를 권장한다.
//	서버 수업들을때 사용하게 될것이다.
//
//	pChar = (char*)(&integer);							// O
//	pChar = static_cast<char*>(&integer);				// X
//	pChar = reinterpret_cast<char*>(&integer);			// O
//*/
//
//
//	cout << *(int*)(pChar) << endl;
///*
//	cout << *(int*)(pChar) << endl;						// O
//	cout << static_cast<int*>(pChar) << endl;			// X
//	cout << *reinterpret_cast<int*>(pChar) << endl;		// O
//*/
//
//
//	pChar[0];
//	pChar[1];
//	pChar[2];
//	pChar[3]=5;
//	cout << *reinterpret_cast<int*>(pChar) << endl;
///*
//	4개의 byte 모두를 사용해야한다는 증거로,
//	4번째 index 값을 수정하여 다시 integer로 출력해보면, 값이 달라졌음을 확인할 수 있다.
//*/
//
//	ofstream fOut;
//	fOut.open("data2.txt", std::ios::binary);
//
//	if(fOut.is_open()) cout << "Open Success" << endl;
//
//	vector<int> vnum;
//
//#define LOOP_NUM	5000
//
//	for(int i=0 ; i<LOOP_NUM ; ++i)
//		vnum.push_back(i);
//
//	for(int i=0 ; i<LOOP_NUM ; ++i){
//		fOut.write ((char*)&vnum[i], sizeof(vnum.front()));
//	//	char* pChar = reinterpret_cast<char*>(&vnum[i]);
//	//	fOut << pChar[0] << pChar[1] <<pChar[2] <<pChar[3];
//	}
//	fOut.close();
//	
//	ifstream fIn;
//	fIn.open("data2.txt", std::ios::binary);
//	if(fIn.is_open()) cout << "Open Success" << endl;
//
//	while(!fIn.eof()){
//		fIn.read(pChar, 4);
//		cout << *reinterpret_cast<int*>(pChar) << endl;
//	}
//	fIn.close();
//
//
//
	struct VECTOR{
		float x;
		float y;
		float z;
		float w;
		VECTOR(float x, float y, float z, float w){
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}
	};



	//ofstream fOut;
	//fOut.open("vector.txt", std::ios::binary);
	//if(fOut.is_open()) cout << "Open Success" << endl;

	////char* ppp = reinterpret_cast<char*>(&XMFLOAT4(1,1,1,1));
	////XMFLOAT4 pXMVec = *reinterpret_cast<XMFLOAT4*>(ppp);

	////fOut.write (reinterpret_cast<char*>(&pXMVec), sizeof(pXMVec));

	////fOut.close();
	////return 0;


	//vector<XMFLOAT4> vnum;

	//for(int i=0 ; i<10000 ; ++i)
	//	vnum.push_back(XMFLOAT4(1, 1, 1, 1));

	//for(int i=0 ; i<10000 ; ++i){
	//	fOut.write (reinterpret_cast<char*>(&vnum[i]), sizeof(vnum.front()));
	//}
	//fOut.close();
	//
	//char* pChar = nullptr;
	//ifstream fIn;
	//fIn.open("vector.txt", std::ios::binary);
	//if(fIn.is_open()) cout << "Open Success" << endl;

	//while(!fIn.eof()){
	//	fIn.read(pChar, sizeof(XMFLOAT4));
	//	XMFLOAT4 pXMVec = *reinterpret_cast<XMFLOAT4*>(pChar);
	//	cout << pXMVec.x << pXMVec.y << pXMVec.z << pXMVec.w << endl;
	//}
	//fIn.close();
}
