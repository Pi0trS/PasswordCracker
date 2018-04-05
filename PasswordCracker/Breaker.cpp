#include<iostream>
#include<thread>

#include<string>
#include<fstream>
#include<exception>
#include<vector>

#include<mutex>
#include<queue>

#include<process.h> 
#include<windows.h>
#include<atlutil.h>

#include "md5.h"
#include "sha1.h"
#include "UserData.h"
#include "Breaker.h"

Breaker::Breaker(ConfigReader data_)
{
	data  = new ConfigReader(data_);
}


void Breaker::fillQueue()
{
	long long counter = 0;
	long long maxInQueue = 0;

	std::fstream file;
	std::string tmp;
	file.open(data->getDictionaryPath(), std::ios::in);
	


	file.seekg(0,file.end);
	int length = file.tellg();
	file.seekg(0, file.beg);
	std::cout<< length;

	if (!file.good())throw std::exception("cannot be read");
	while (!flagStop)
	{

		if (passQueue.size() < 1000)
		{
			
			getline(file, tmp);
			if (tmp == "")
			{
				flagEndFile = true;
				break;
			}

			lock.lock();
			passQueue.push(tmp);
			lock.unlock();
		}

	}

	file.close();
}

void Breaker::cracking()
{
	std::string tmp;
	std::string hash;

	while (true)
	{
		if (!flagPause)
		{
			lock.lock();
			if (!passQueue.empty())
			{
				//std::cout <<() << std::endl;
				tmp = passQueue.front();
				passQueue.pop();
			}
			lock.unlock();
			//std::cout << tmp << std::endl;
			hash = md5((data->getSalt() == "none" ? tmp : tmp + data->getSalt()));
			if (data->getHash() == hash)
			{
				password = tmp;
				flagStop = true;
			}

			if (passQueue.empty() && flagEndFile)
				break;
			if (flagStop)
				break;
		}
		if (flagStop)
			break;
	}
}
void Breaker::startCracking()
{
	//std::thread queueFiller(&Breaker::fillQueue,this);
	//std::thread thread1(&Breaker::cracking, this);
	//std::thread thread2(&Breaker::cracking);
	//std::thread thread3(&Breaker::cracking);

	std::thread test(&Breaker::fillQueue, this);
	std::thread keyT(&Breaker::keyControl, this);
	for (int i = 0; i < data->getNumberOfThrede(); i++)
	{
		breakingThread.push_back(std::thread(&Breaker::cracking,this));
	}
	//std::thread thread4(&Breaker::cracking,this);

	test.join();
	keyT.join();
	for (int i = 0; i < data->getNumberOfThrede(); i++)
	{
		breakingThread[i].join();
	}
	
	if(password != "")
	std::cout << "znalezione haslo: " << password << std::endl;
	else std::cout << "password not match" << std::endl;
}
void Breaker::keyControl()
{
	bool prevEscape = false, currEscape = false;
	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			currEscape = true;
		}
		else
			currEscape = false;
		if (currEscape != prevEscape)
		{
			if (currEscape)
			{
				flagPause ? flagPause = false : flagPause = true;
			}
			prevEscape = currEscape;
		}
		if (GetAsyncKeyState(0x51))
		{
			flagStop = true;
		}
		if (flagStop)
			break;
	}
}