#include<iostream>
#include<string>
#include<fstream>
#include<exception>

#include "UserData.h"

UserData::UserData()
{
	hash = hashType = salt = dictionaryPath = numberOfThread = "error";
}
void UserData::hashSet(std::string hash_){hash = hash_;}
void UserData::hashTypeSet(std::string hashType_){hashType = hashType_;}
void UserData::saltSet(std::string salt_){salt = salt_;}
void UserData::dictionaryPathSet(std::string path){dictionaryPath = path;}
void UserData::numberOfThredeSet(std::string number){numberOfThread = number;}
void UserData::getDataFromConsol()
{
	std::string tmp;
	std::cout << "You have chosen the imput from the console."<<std::endl;
	std::cout << "Please enter the hash" << std::endl;
	std::cin >> tmp;
	hashSet(tmp);

	std::cout << "Please enter the hash type : MD5, SHA1." << std::endl;
	std::cin >> tmp;
	hashSet(tmp);

	std::cout << "Please enter salt or, if there is no salt, enter: none." << std::endl;
	std::cin >> tmp;
	saltSet(tmp);

	std::cout << "Please enter the path to the dictionary." << std::endl;
	std::cin >> tmp;
	dictionaryPathSet(tmp);

	std::cout << "Please enter the number of threads or, enter: auto." << std::endl;
	std::cin >> tmp;
	numberOfThredeSet(tmp);

	std::cout << "You have entered the data." << std::endl;
}

std::string getInfo(std::string tmp_, int position)
{
	std::string tmp = tmp_;
	tmp = tmp.substr(position);
	if (tmp[0] == ' ')tmp = tmp.substr(1);
	return tmp;
}

void UserData::getDataFromFile(std::string path)
{
	std::fstream file;
	file.open(path, std::ios::in);
	if (!file.good())throw std::exception("cannot be read");
	std::string tmp;
	
	getline(file,tmp);
	hashSet(getInfo(tmp, 5));

	getline(file, tmp);
	hashTypeSet(getInfo(tmp, 9));

	getline(file, tmp);
	saltSet(getInfo(tmp, 5));

	getline(file, tmp);
	dictionaryPathSet(getInfo(tmp, 16));

	getline(file, tmp);
	numberOfThredeSet(getInfo(tmp, 17));
}


