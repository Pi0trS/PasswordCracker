//#include<iostream>
//#include<string>
//#include<fstream>
//#include<process.h> 
//#include<windows.h>
//#include<atlutil.h>
//#include<vector>
////#include <boost/thread.hpp>
//using namespace std;
//
//CRITICAL_SECTION g_Section;
//
//unsigned int g_Counter = 0;
//void __cdecl ThreadProc(void * Args)
//{
//	while (g_Counter < 1000)
//	{
//		Sleep(500);
//		EnterCriticalSection(&g_Section);
//		cout << g_Counter << endl;
//		g_Counter++;
//		LeaveCriticalSection(&g_Section);
//	}
//
//	_endthread();
//}
//
//int main()
//{
//	int s;
//	InitializeCriticalSection(&g_Section);
//	/*HANDLE hThread = (HANDLE)_beginthread(ThreadProc, 0, NULL);
//	HANDLE hThread1 = (HANDLE)_beginthread(ThreadProc, 0, NULL);
//	HANDLE hThread2 = (HANDLE)_beginthread(ThreadProc, 0, NULL);*/
//
//
//	vector < HANDLE > threads;
//	for (int i = 0; i < 1000; ++i)
//	{
//		threads.push_back((HANDLE)_beginthread(ThreadProc, 0, NULL));
//	}
//
//	if (threads.size() > 0)
//		WaitForMultipleObjects(threads.size(), &threads[0], TRUE, 10000);
//
//
//
//
//	cin >> s;
//	return 0;
//}