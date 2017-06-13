#include "stdafx.h"
#include "Function_Tool.h"

const UINT LOOP_NUM = 1'000'000;
const UINT AVG_LOOP_NUM = 10;

#pragma comment(linker, "/STACK:8000000")
//#pragma comment(linker, "/HEAP:3999990")

int main() {
	int arr[LOOP_NUM];
	for (int i = 0; i<LOOP_NUM; ++i) arr[i] = 0;

	array<int, LOOP_NUM> sarr;
	for (int i = 0; i<LOOP_NUM; ++i) sarr[i] = 0;
	
	vector<int> vec;
	for (int i = 0; i<LOOP_NUM; ++i) vec.push_back(0);

	list<int> lst;
	for (int i = 0; i<LOOP_NUM ; ++i) lst.push_back(0);


	CStopWatch watch;
	cout << "-------------------------Array-------------------------" << endl;
	cout << "index" << endl;
	{duration<double> avgTime = duration<double>(0);
	for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
		watch.BeginTimer();
		for (int i = 0; i<LOOP_NUM; ++i) {
			arr[i];
		}
		avgTime += watch.EndTimerNoPrint();
	}
	avgTime /= AVG_LOOP_NUM;
	cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl; }

	cout << "range" << endl;
	{duration<double> avgTime = duration<double>(0);
	for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
		watch.BeginTimer();
		for (int num : arr) {
			
		}
		avgTime += watch.EndTimerNoPrint();
	}
	avgTime /= AVG_LOOP_NUM;
	cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;}

	cout << "reference range" << endl;
	{duration<double> avgTime = duration<double>(0);
	for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
		watch.BeginTimer();
		for (const auto& num : arr) {

		}
		avgTime += watch.EndTimerNoPrint();
	}
	avgTime /= AVG_LOOP_NUM;
	cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl; }

	cout << "itrtr" << endl;
	{duration<double> avgTime = duration<double>(0);
	auto endPvt = end(arr);
	for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
		watch.BeginTimer();
		for (auto pvt = begin(arr); pvt != endPvt; pvt++) {

		}
		avgTime += watch.EndTimerNoPrint();
	}
	avgTime /= AVG_LOOP_NUM;
	cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl; }






	cout << "-------------------------SArray-------------------------" << endl;
	cout << "index" << endl;
	{duration<double> avgTime = duration<double>(0);
	for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
		watch.BeginTimer();
		for (int i = 0; i<LOOP_NUM; ++i) {
			sarr[i];
		}
		avgTime += watch.EndTimerNoPrint();
	}
	avgTime /= AVG_LOOP_NUM;
	cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl; }

	cout << "range" << endl;
	{duration<double> avgTime = duration<double>(0);
	for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
		watch.BeginTimer();
		for (int num : sarr) {

		}
		avgTime += watch.EndTimerNoPrint();
	}
	avgTime /= AVG_LOOP_NUM;
	cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl; }

	cout << "reference range" << endl;
	{duration<double> avgTime = duration<double>(0);
	for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
		watch.BeginTimer();
		for (const auto& num : sarr) {

		}
		avgTime += watch.EndTimerNoPrint();
	}
	avgTime /= AVG_LOOP_NUM;
	cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl; }

	cout << "itrtr" << endl;
	{duration<double> avgTime = duration<double>(0);
	auto end = sarr.end();
	for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
		watch.BeginTimer();
		for (auto pvt = sarr.begin(); pvt != end; pvt++) {

		}
		avgTime += watch.EndTimerNoPrint();
	}
	avgTime /= AVG_LOOP_NUM;
	cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl; }





	cout << "-------------------------Vector-------------------------" << endl;
	cout << "index" << endl;
	{duration<double> avgTime = duration<double>(0);
	for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
		watch.BeginTimer();
		for (int i = 0; i<LOOP_NUM; ++i) {
			vec[i];
		}
		avgTime += watch.EndTimerNoPrint();
	}
	avgTime /= AVG_LOOP_NUM;
	cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl; }

	cout << "range" << endl;
	{duration<double> avgTime = duration<double>(0);
	for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
		watch.BeginTimer();
		for (int num : vec) {

		}
		avgTime += watch.EndTimerNoPrint();
	}
	avgTime /= AVG_LOOP_NUM;
	cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;}

	cout << "reference range" << endl;
	{duration<double> avgTime = duration<double>(0);
	for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
		watch.BeginTimer();
		for (const auto& num : vec) {

		}
		avgTime += watch.EndTimerNoPrint();
	}
	avgTime /= AVG_LOOP_NUM;
	cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl; }

	cout << "itrtr" << endl;
	{duration<double> avgTime = duration<double>(0);
	auto end = vec.end();
	for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
		watch.BeginTimer();
		for (auto pvt = vec.begin(); pvt != end; pvt++) {

		}
		avgTime += watch.EndTimerNoPrint();
	}
	avgTime /= AVG_LOOP_NUM;
	cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl; }







	cout << "-------------------------List-------------------------" << endl;
	cout << "range" << endl;
	{duration<double> avgTime = duration<double>(0);
	for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
		watch.BeginTimer();
		for (int num : lst) {

		}
		avgTime += watch.EndTimerNoPrint();
	}
	avgTime /= AVG_LOOP_NUM;
	cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;}

	cout << "reference range" << endl;
	{duration<double> avgTime = duration<double>(0);
	for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
		watch.BeginTimer();
		for (const auto& num : lst) {

		}
		avgTime += watch.EndTimerNoPrint();
	}
	avgTime /= AVG_LOOP_NUM;
	cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl; }

	cout << "itrtr" << endl;
	{duration<double> avgTime = duration<double>(0);
	auto end = lst.end();
	for (int avgLoop = 0; avgLoop<AVG_LOOP_NUM; ++avgLoop) {
		watch.BeginTimer();

		for (auto pvt = lst.begin(); pvt != end; pvt++) {

		}
		avgTime += watch.EndTimerNoPrint();
	}
	avgTime /= AVG_LOOP_NUM;
	cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl; }
}