#include "stdafx.h"

#include <iostream>
using namespace std;

///<summary> 야호야호 </summary>
enum ANIMATION1 : int {
	WALK,	RUN,	JUMP,	DEAD,
};

///<summary> 야호야호 </summary>
enum class ANIMATION2 : int {
	WALK,	RUN,	JUMP,	DEAD,
};

int main(){
	cout << ANIMATION1::WALK << endl;

	//enum class는 형변환이 되질 않는다. 따라서 다음 코드는 수행이 불가능 하다.
	cout << ANIMATION2::WALK << endl;

	ANIMATION2 ani;


	switch(ani){
	//일반 enum인 ANIAMTION1은 호완이 되질 않는다.
	case ANIMATION1::WALK:
		break;
	case ANIMATION2::RUN:
		break;
	case ANIMATION2::JUMP:
		break;
	}

}