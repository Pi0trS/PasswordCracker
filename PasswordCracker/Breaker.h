#pragma once
#include<iostream>
#include<thread>

#include<string>
#include<fstream>
#include<exception>
#include<vector>

#include<mutex>
#include<queue>

#include "md5.h"
#include "sha1.h"
#include "UserData.h"
#include "Breaker.h"

class Breaker
{
public:
	Breaker(UserData data_);

	void startCracking();

	int counter;
private:
	UserData *data;
	std::string password,tmp;

	//std::vector <std::thread> breakingThread;
	std::vector <std::thread> breakingThread;

	std::queue <std::string> passQueue;
	std::mutex lock;
	bool flagStop = false;
	void fillQueue();
	void cracking();

};