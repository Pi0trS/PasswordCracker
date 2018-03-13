#include<iostream>
#include<string>

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