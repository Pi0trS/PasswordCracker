#include<iostream>
#include<string>
#include<fstream>
#include <process.h> 
#include <windows.h>

#include"UserData.h"
#include "md5.h"
#include"sha1.h"
using namespace std;

unsigned int g_Counter = 0;
void __cdecl ThreadProc(void * Args)
{
	while (g_Counter < 1000) 
	{
		Sleep(500);
		cout << g_Counter;
		g_Counter++;
	}

	_endthread();
}

int main()
{
	string s = "C:\\Users\\Piotr\\Documents\\Visual Studio 2015\\Projects\\PasswordCracker\\ConfigData.txt";

	//std::fstream file;
	//file.open(s, std::ios::in);
	//if (!file.good())throw std::exception("cannot be read");
	//std::string tmp;
	//getline(file, tmp);
	//getline(file, tmp);
	//cout << tmp.substr(0);
	//
	//cout << "\n" << tmp << endl;

	//HANDLE hThread = (HANDLE)_beginthread(ThreadProc, 0, NULL);
	//WaitForSingleObject(hThread, INFINITE);

	//char buffer[1024];
	//sprintf(buffer, "g_Counter: %d\n", g_Counter);
	//cout << g_Counter;
	//OutputDebugString(buffer);
	cout << md5("qweraaa")<<endl;
	UserData u;
	u.getDataFromFile(s);
	s = u.startCracking();
	cout << s;




	cin >> s;
	return 0;
}