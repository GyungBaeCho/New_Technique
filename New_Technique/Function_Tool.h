#pragma once

class CStopWatch;

extern system_clock::time_point startTime;
extern duration<double> passedTime;

extern CStopWatch g_StopWatch;

__declspec(selectany) mutex printLock;

class CStopWatch{
private:
	system_clock::time_point	m_StartTime;
	duration<double>			m_PassedTime;

public:
	CStopWatch(){}
	virtual ~CStopWatch(){}

	void BeginTimer(){
		m_StartTime = system_clock::now();
	}

	duration<double> EndTimer(){
		m_PassedTime = system_clock::now() - m_StartTime;
		cout << "사용된 시간 : " << to_string(m_PassedTime.count()) << " [" <<  m_PassedTime.count() << "]" << endl << endl;
//		cout << "사용된 시간 : " << m_PassedTime.count()  << endl << endl;
		return m_PassedTime;
	}

	duration<double> EndTimerNoPrint(){
		m_PassedTime = system_clock::now() - m_StartTime;
		return m_PassedTime;
	}

	void LockEndTimer(){
		m_PassedTime = system_clock::now() - m_StartTime;
		printLock.lock();
			cout << "사용된 시간 : " << to_string(m_PassedTime.count()) << " [" <<  m_PassedTime.count() << "]" << endl << endl;
		printLock.unlock();
	}
};

void BeginTimer();
void EndTimer();
//
//inline void AvgTimer(void(*Func)(),int nAvgLoop,int nLoop){
//	CStopWatch watch;
//	duration<double> avgTime = duration<double>(0);
//
//	for(int avgLoop=0 ; avgLoop<nAvgLoop; ++avgLoop){
//		watch.BeginTimer();
//
//		for(int i=0 ; i<nLoop ; ++i){
//			Func();
//		}
//		avgTime += watch.EndTimerNoPrint();
//	}
//	avgTime /= nAvgLoop;
//	cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;
//}

template<class T>
inline void AvgTimer(T Func, int nAvgLoop, int nLoop){
	CStopWatch watch;
	duration<double> avgTime = duration<double>(0); 

	for(int avgLoop=0 ; avgLoop<nAvgLoop; ++avgLoop){
		watch.BeginTimer();

		for(int i=0 ; i<nLoop ; ++i){
			Func();
		}
		avgTime += watch.EndTimerNoPrint();
	}
	avgTime /= nAvgLoop;
	cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;
}