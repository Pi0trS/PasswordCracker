#pragma once

class UserData
{
public:
	UserData();
	void hashSet(std::string hash_);
	void hashTypeSet(std::string hsahType_);
	void saltSet(std::string salt_);
	void dictionaryPathSet(std::string path);
	void numberOfThredeSet(std::string number);
	void getDataFromConsol();
	void getDataFromFile(std:: string path);
	//std::string getInfo(std::string tmp_, int position);
private:
	std::string hash, hashType, salt, dictionaryPath, numberOfThread;
 
};