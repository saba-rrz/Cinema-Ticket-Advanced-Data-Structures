#include "Time.h"

Time::Time()
{
}

Time::Time(int hour, int minute, int day, int month)
{
	this->hour = hour;
	this->minute = minute; 
	this->day = day;
	this->month = month;
}

void Time::printTime() const
{
	cout << setfill('0') << setw(2) << hour << ":"
		<< setfill('0') << setw(2) << minute << " "
		<< setfill('0') << setw(2) << day << "/"
		<< setfill('0') << setw(2) << month << endl;
}
