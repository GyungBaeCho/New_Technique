#include "stdafx.h"
#include "Function_Tool.h"

class AAA {
public:
	int num = 0;
	
public:
	AAA() {
		cout << "일반 생성자" << endl;
	}
	AAA(int&& num) {
		this->num = num;
		num = 0;
		cout << "사용자 정의 생성자" << endl;
	}
	explicit AAA(const AAA& aaa) {
		num = aaa.num;
		cout << "상수 복사 생성자" << endl;
	}
	explicit AAA(AAA&& aaa) {
		num = aaa.num;
		cout << "이동 생성자" << endl;
	}
	~AAA() {}

	AAA& operator=(const AAA& data) {
		if (this != &data) {
			cout << "복사 연산자" << endl;
			num = data.num;
		}
		return *this;
	}

	AAA& operator=(AAA&& data) {
		if (this != &data) {
			cout << "이동 연산자" << endl;
			num = data.num;
			data.num = 0;
		}
		return *this;
	}
};

const UINT LOOP_NUM = 1'000'000;
const UINT AVG_LOOP_NUM = 10;

int main() {
	cout << endl << "------------------------" << endl;
	AAA a0;

	cout << endl << "------------------------" << endl;
	const AAA aaa;
	AAA aaaa(aaa);

	cout << endl << "------------------------" << endl;

	AAA aa(AAA::AAA());

	cout << endl << "------------------------" << endl;
	AAA a1 (std::move(AAA::AAA()));

	cout << endl << "------------------------" << endl;
	AAA a3 (std::move(AAA{}));

	cout << endl << "------------------------" << endl;
	AAA a4 (std::move(AAA()));

	cout << endl << "------------------------" << endl;
	AAA a5{ std::move(AAA()) };

	cout << endl << "------------------------" << endl;
	AAA a6{ std::move(AAA{}) };

	cout << endl << "------------------------" << endl;
	AAA a7{ (AAA{5}) };

	cout << endl << "------------------------" << endl;
	AAA a8(100);
	AAA a9(a8);

	//AAA input;
	////복사 생성자
	//cout << "--------------------------------------------------" << endl;
	//{duration<double> avgTime = duration<double>(0);
	//for (volatile int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
	//	watch.BeginTimer();
	//	for (volatile int i = 0; i<LOOP_NUM; ++i) {
	//		AAA data(input);
	//	}
	//	avgTime += watch.EndTimerNoPrint();
	//}
	//avgTime /= AVG_LOOP_NUM;
	//cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl; }

	////이동 생성자
	//cout << "--------------------------------------------------" << endl;
	//{duration<double> avgTime = duration<double>(0);
	//for (volatile int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
	//	watch.BeginTimer();
	//	for (volatile int i = 0; i<LOOP_NUM; ++i) {
	//		AAA data(std::move(input));
	//	}
	//	avgTime += watch.EndTimerNoPrint();
	//}
	//avgTime /= AVG_LOOP_NUM;
	//cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl; }
}
