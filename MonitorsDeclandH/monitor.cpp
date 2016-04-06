#include "stdafx.h"
#include "monitor.h"


Monitor::Monitor()
{
	front = 0;
	rear = 0;
	count = 0;
	not_full = true;
	not_empty = false;
	stringAdded = false;

}
void Monitor::Deposit(std::string data)
{
	while (count == 100)
	{
		while (not_full == false){}		//check if buffer is full
	}
	buffer[rear] = data;
	rear = (rear + 1) % 10;
	count++;
	not_empty = false;
	stringAdded = true;
}

void Monitor::Fetch(std::string &result)
{
	while (count == 0)
	{
		while (not_empty == false) {}	//check if buffer is empty
	}
	result = buffer[front];
	front = (front + 1) % 10;
	count--;
	not_full = false;
	stringAdded = false;
}

bool Monitor::StringAdded()
{
	return stringAdded;
}