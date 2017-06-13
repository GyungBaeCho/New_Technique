#include "stdafx.h"

//#include <iostream>
//#include <memory>
//#include <vector>


class CObject{
private:

public:
	int* pTexture;
	int* pMesh;
	vector<int> vData;
	int arr[100000];

public:
	CObject(){}
	CObject(int texture, int mesh){
		pTexture = new int(texture);
		pMesh = new int(mesh);

		for(int i=0 ; i<10000 ; ++i){		arr[i] = 100;		}
	}
};


class CSceneSaver{
public:
	vector<CObject*> vpObject;
	int nPivot;
	int max;

public:
	CSceneSaver(){
		nPivot = 0;
		max = 1000;
		vpObject.reserve(max*2);
		for(int i=0 ; i<max ; ++i) vpObject.push_back(new CObject);
	}

	void AddObject(CObject* pObject){
		*vpObject[nPivot++] = *pObject;
		if(nPivot >= max){
			max++;
			vpObject.push_back(new CObject);
		}
	}

	void Flush(){		nPivot = 0;		}
};

int main(){
	//int* pNum = new int(100);
	//int* pNum2 = new int;
	//memcpy(pNum2, pNum, sizeof(pNum));
	//cout << *pNum << " " << *pNum2 << endl;


	//int data = 100;
	//int data2;
	//memcpy(&data2, &data, sizeof(data));
	//cout << data << " " << data2 << endl;


	//CObject* pObject = new CObject;
	//pObject->pTexture = new int(10);
	//pObject->pMesh = new int(100);

	//CObject ObjectCopy = *pObject;

	//cout << *ObjectCopy.pTexture << " " << *ObjectCopy.pMesh << endl;


	int num = 0;
	CSceneSaver sceneSaver;
	CObject* pMonsterObject = new CObject(10, 20);

	while(true){
		for(int i=0 ; i<10000 ; ++i)
			sceneSaver.AddObject(pMonsterObject);
		sceneSaver.Flush();
		cout << num++ << endl;
	}
}