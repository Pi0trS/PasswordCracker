#pragma once

class Cracker
{
public:
	Cracker(UserData *data);
	std::string startCracking();
private:
	UserData data;
};