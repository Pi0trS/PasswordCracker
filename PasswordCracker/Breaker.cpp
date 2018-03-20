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

Breaker::Breaker(UserData data_)
{
	data  = new UserData(data_);
	
}


void Breaker::fillQueue()
{
	std::fstream file;
	std::string tmp;
	file.open(data->getDictionaryPath(), std::ios::in);
	if (!file.good())throw std::exception("cannot be read");
	while (true)
	{

		if (passQueue.size() < 1000)
		{
			lock.lock();
			getline(file, tmp);
			if (tmp == "")
			{
				flagStop = true; 
				break;
			}
			passQueue.push(tmp);
			lock.unlock();
		}

	}
}

void Breaker::cracking()
{
	while (!passQueue.empty() || !flagStop)
	{
		lock.lock();

		std::cout << passQueue.front() << std::endl;
		lock.unlock();

		if (data->getHashType() == "MD5")
		{
			if (data->getHash() == md5((data->getSalt() == "none" ? tmp : tmp + data->getSalt())))
			{
				password = tmp;
				flagStop = true;
			}
		}
		else if (data->getHashType() == "SHA1")
		{
			if (data->getHash() == md5((data->getSalt() == "none" ? tmp : tmp + data->getSalt())))
			{
				password = tmp;
				flagStop = true;
			}
		}
		else
		{
			throw std::exception("wrong hash type");
		}
		passQueue.pop();
		if (tmp == "")
		{
			password = "pasword no found";
			flagStop = true;
		}
	}
}
void Breaker::startCracking()
{

	//std::thread queueFiller(&Breaker::fillQueue,this);
	//std::thread thread1(&Breaker::cracking, this);
	//std::thread thread2(&Breaker::cracking);
	//std::thread thread3(&Breaker::cracking);
	std::thread test(&Breaker::fillQueue, this);

	std::thread thread4(&Breaker::cracking,this);

}