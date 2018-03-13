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

private:
	std::string hash, hashType, salt, dictionaryPath, numberOfThread;
 
};