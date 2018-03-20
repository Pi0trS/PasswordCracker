#pragma once

class UserData
{
public:
	UserData();
	UserData(UserData & a);
	void setHash(std::string hash_);
	std::string getHash();
	void setHashType(std::string hsahType_);
	std::string getHashType();
	void setSalt(std::string salt_);
	std::string getSalt();
	void setDictionaryPath(std::string path);
	std::string getDictionaryPath();
	void setNumberOfThrede(std::string number);
	std::string getNumberOfThrede();
	void getDataFromConsol();
	void getDataFromFile(std:: string path);
	std::string startCracking();
private:
	std::string hash, hashType, salt, dictionaryPath, numberOfThread, password;
	std::string getInfo(std::string tmp_, int position);
	bool passMath();
};