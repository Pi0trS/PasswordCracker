#include<iostream>
#include<string>
#include<fstream>
#include<exception>

#include "UserData.h"
#include "md5.h"
#include "sha1.h"

UserData::UserData()
{
	hash = hashType = salt = dictionaryPath = numberOfThread = "";
}
UserData::UserData(UserData & a)
{
	hash = a.hash;
	hashType = a.hashType;
	salt = a.salt;
	dictionaryPath = a.dictionaryPath;
	numberOfThread = a.numberOfThread;
}
void UserData::setHash(std::string hash_){hash = hash_;}
std::string UserData::getHash() { return hash; }
void UserData::setHashType(std::string hashType_){hashType = hashType_;}
std::string UserData::getHashType(){return hashType;}
void UserData::setSalt(std::string salt_){salt = salt_;}
std::string UserData::getSalt(){return salt;}
void UserData::setDictionaryPath(std::string path){dictionaryPath = path;}
std::string UserData::getDictionaryPath(){return dictionaryPath;}
void UserData::setNumberOfThrede(std::string number){numberOfThread = number;}
std::string UserData::getNumberOfThrede(){return numberOfThread;}
void UserData::getDataFromConsol()
{
	std::string tmp;
	std::cout << "You have chosen the imput from the console."<<std::endl;
	std::cout << "Please enter the hash" << std::endl;
	std::cin >> tmp;
	setHash(tmp);

	std::cout << "Please enter the hash type : MD5, SHA1." << std::endl;
	std::cin >> tmp;
	setHashType(tmp);

	std::cout << "Please enter salt or, if there is no salt, enter: none." << std::endl;
	std::cin >> tmp;
	setSalt(tmp);

	std::cout << "Please enter the path to the dictionary." << std::endl;
	std::cin >> tmp;
	setDictionaryPath(tmp);

	std::cout << "Please enter the number of threads or, enter: auto." << std::endl;
	std::cin >> tmp;
	setNumberOfThrede(tmp);

	std::cout << "You have entered the data." << std::endl;
}

std::string UserData::getInfo(std::string tmp_, int position)
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
	setHash(getInfo(tmp, 5));

	getline(file, tmp);
	setHashType(getInfo(tmp, 9));

	getline(file, tmp);
	setSalt(getInfo(tmp, 5));

	getline(file, tmp);
	setDictionaryPath(getInfo(tmp, 16));

	getline(file, tmp);
	setNumberOfThrede(getInfo(tmp, 17));

	file.close();
}

std::string UserData::startCracking()
{
	std::fstream file;
	std::string tmp,help;
	file.open(dictionaryPath, std::ios::in);
	if (!file.good())throw std::exception("cannot be read");


}
