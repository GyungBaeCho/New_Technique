#include "stdafx.h"
#include "Function_Tool.h"

const UINT LOOP_NUM = 1000000;

#define FOREGROUND_BLUE				0x0001 // text color contains blue.
#define FOREGROUND_GREEN			0x0002 // text color contains green.
#define FOREGROUND_RED				0x0004 // text color contains red.
#define FOREGROUND_INTENSITY		0x0008 // text color is intensified.

#define BACKGROUND_BLUE				0x0010 // background color contains blue.
#define BACKGROUND_GREEN			0x0020 // background color contains green.
#define BACKGROUND_RED				0x0040 // background color contains red.
#define BACKGROUND_INTENSITY		0x0080 // background color is intensified.


#define COMMON_LVB_LEADING_BYTE		0x0100 // Leading Byte of DBCS
#define COMMON_LVB_TRAILING_BYTE	0x0200 // Trailing Byte of DBCS
#define COMMON_LVB_GRID_HORIZONTAL	0x0400 // DBCS: Grid attribute: top horizontal.
#define COMMON_LVB_GRID_LVERTICAL	0x0800 // DBCS: Grid attribute: left vertical.
#define COMMON_LVB_GRID_RVERTICAL	0x1000 // DBCS: Grid attribute: right vertical.
#define COMMON_LVB_REVERSE_VIDEO	0x4000 // DBCS: Reverse fore/back ground attribute.
#define COMMON_LVB_UNDERSCORE		0x8000 // DBCS: Underscore.

#define COMMON_LVB_SBCSDBCS			0x0300 // SBCS or DBCS flag.

int main(){
	CStopWatch watch;

	int n = 10;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY);

	HANDLE hConsolScreenBuff = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsolScreenBuff, 0x0001);		cout << "TEST" << endl;
	SetConsoleTextAttribute(hConsolScreenBuff, 0x0002);		cout << "TEST" << endl;
	SetConsoleTextAttribute(hConsolScreenBuff, 0x0003);		cout << "TEST" << endl;
	SetConsoleTextAttribute(hConsolScreenBuff, 0x0004);		cout << "TEST" << endl;
	SetConsoleTextAttribute(hConsolScreenBuff, 0x0005);		cout << "TEST" << endl;
	SetConsoleTextAttribute(hConsolScreenBuff, 0x0006);		cout << "TEST" << endl;
	SetConsoleTextAttribute(hConsolScreenBuff, 0x0007);		cout << "TEST" << endl;
	SetConsoleTextAttribute(hConsolScreenBuff, 0x0008);		cout << "TEST" << endl;


	cout << "----------if----------" << endl;

	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		if(n == 10)
			NULL;
		else
			NULL;
	}
	watch.EndTimer();

	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		if(n != 10)
			NULL;
		else
			NULL;
	}
	watch.EndTimer();

	cout << "----------ternary operator----------" << endl;
	
	watch.BeginTimer();
	for(int i=0 ; i<LOOP_NUM ; ++i){
		(n == 10) ? NULL : NULL;
	}
	watch.EndTimer();
} 