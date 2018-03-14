#pragma once

class UserData
{
public:
	UserData();
	void setHash(std::string hash_);
	void setHashType(std::string hsahType_);
	void setSalt(std::string salt_);
	void setDictionaryPath(std::string path);
	void setNumberOfThrede(std::string number);
	void getDataFromConsol();
	void getDataFromFile(std:: string path);
	//std::string getInfo(std::string tmp_, int position);
private:
	std::string hash, hashType, salt, dictionaryPath, numberOfThread;
 
};