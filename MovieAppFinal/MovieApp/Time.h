#pragma once
#include <iomanip>
#include <iostream>

using namespace std; 
class Time
{
public:
	int day;
	int month;
	int hour; 
	int minute; 

	Time();
	Time(int hour, int minute, int day, int month);
	void printTime() const;
};

