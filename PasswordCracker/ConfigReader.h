#pragma once
#include<map>

class ConfigReader
{
public:
	ConfigReader();
	ConfigReader(std::string path);
	ConfigReader(std::istream &stream);
	void checkData();

	std::string getHash();
	std::string getHashType();
	std::string getSalt();
	std::string getDictionaryPath();
	int getNumberOfThrede();

private:
	std::map<std::string, std::string>config;
	const char separator = ':';
	std::string hash, hashType, salt, dictionaryPath;

	int numberOfThreads;
	void setHash(std::string hash_);
	void setHashType(std::string hsahType_);
	void setSalt(std::string salt_);
	void setDictionaryPath(std::string path);
	void setNumberOfThrede(int number);
	std::string trim(std::string s);
};