#include "stdafx.h"
#include "Function_Tool.h"

const UINT LOOP_NUM = 10000000;

class CData{
private:
	D3DXVECTOR4 m_v1;
	D3DXVECTOR4 m_v2;
	D3DXVECTOR4 m_v3;
	D3DXVECTOR4 m_v4;
	D3DXVECTOR4 m_v5;

public:
	CData(){
	//	cout << "디폴트 생성자" << endl;
	}
	CData(CData& data){
		m_v1 = data.m_v1;
		m_v2 = data.m_v2;
		m_v3 = data.m_v3;
		m_v4 = data.m_v4;
		m_v5 = data.m_v5;
	//	cout << "복사 생성자" << endl;
	}
};

int main(){
	CStopWatch watch;

	CData data;
	cout << "----------------디폴트 생성자----------------" << endl;
	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		CData temp = data;
	}
	watch.EndTimer();

	cout << "----------------복사 생성자----------------" << endl;
	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		CData temp(data);
	}
	watch.EndTimer();
} 