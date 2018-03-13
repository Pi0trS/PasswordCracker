#include<iostream>
#include<string>
#include<fstream>

#include"UserData.h"
using namespace std;

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

	int i;
	cout << "Hello !";
	UserData a;
	//a.getDataFromConsol();
	a.getDataFromFile(s);
	cin >> i;
	return 0;
}