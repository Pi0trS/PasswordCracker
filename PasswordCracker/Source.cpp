#include<iostream>
#include<string>
#include<fstream>
#include <process.h> 
#include <windows.h>

#include"UserData.h"
#include"Breaker.h"
#include "md5.h"
#include"sha1.h"
using namespace std;

unsigned int g_Counter = 0;
void __cdecl ThreadProc(void * Args)
{
	while (g_Counter < 1000) 
	{
		Sleep(50);
		cout << g_Counter;
		g_Counter++;
	}

	_endthread();
}

int main()
{
	string s = "..\\ConfigData.txt";

	//std::fstream file;
	//file.open(s, std::ios::in);
	//if (!file.good())throw std::exception("cannot be read");
	//std::string tmp;
	//getline(file, tmp);
	//getline(file, tmp);
	//cout << tmp.substr(0);
	//
	//cout << "\n" << tmp << endl;
	//cout << md5("qweraaa")<<endl;
	UserData u;
	u.getDataFromFile(s);
	//s = u.startCracking();
	//cout << s;
	
	Breaker a(u);
	a.startCracking();

	getchar();
	return 0;
}