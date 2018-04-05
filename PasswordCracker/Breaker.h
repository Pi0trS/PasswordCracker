#pragma once
#include<iostream>
#include<thread>

#include<string>
#include<fstream>
#include<exception>
#include<vector>

#include<mutex>
#include<queue>;

#include "md5.h"
#include "sha1.h"
#include "UserData.h"
#include "Breaker.h"
#include "ConfigReader.h"

class Breaker
{
public:
	Breaker(ConfigReader data_);
	void startCracking();
	int counter;
private:
	ConfigReader *data;
	std::string password;
	//std::vector <std::thread> breakingThread;
	std::vector <std::thread> breakingThread;
	std::queue <std::string> passQueue;
	std::mutex lock;


	bool flagStop = false;
	bool flagEndFile = false;
	bool flagPause = false;
	void fillQueue();
	void cracking();
	void keyControl();

};