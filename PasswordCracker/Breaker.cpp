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
	long long counter = 0;
	long long maxInQueue = 0;

	std::fstream file;
	std::string tmp;
	file.open(data->getDictionaryPath(), std::ios::in);
	if (!file.good())throw std::exception("cannot be read");
	while (!flagStop)
	{

		//if (passQueue.size() < 1000)
		{
			maxInQueue = __max(passQueue.size(), maxInQueue);

			if (counter++ % 100000 == 0)
				std::cout << "line: " << counter << std::endl;
			
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

	std::cout << "miq: " << maxInQueue << std::endl;
}

void Breaker::cracking()
{
	std::string tmp;
	std::string hash;

	while (true)
	{
		lock.lock();
		if (!passQueue.empty())
		{
			//std::cout <<() << std::endl;
			tmp = passQueue.front();
			passQueue.pop();

		}
		lock.unlock();

		if (tmp == "URYUNG")
		{
			int a = (int)tmp[0];
			int b = a + (int)tmp[2];
		}

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

}
void Breaker::startCracking()
{
	//std::thread queueFiller(&Breaker::fillQueue,this);
	//std::thread thread1(&Breaker::cracking, this);
	//std::thread thread2(&Breaker::cracking);
	//std::thread thread3(&Breaker::cracking);



	std::thread test(&Breaker::fillQueue, this);
	for (int i = 0; i < std::stoi(data->getNumberOfThrede()); i++)
	{
		breakingThread.push_back(std::thread(&Breaker::cracking,this));
	}
	//std::thread thread4(&Breaker::cracking,this);

	test.join();
	for (int i = 0; i < std::stoi(data->getNumberOfThrede()); i++)
	{
		breakingThread[i].join();
	}
	
	std::cout << "znalezione haslo: " << password << std::endl;

}