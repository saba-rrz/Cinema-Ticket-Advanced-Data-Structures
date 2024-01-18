#pragma once
#include "Film.h"
#include "Time.h"
#include <iostream>
#include <iomanip>

using namespace std; 
class Showtime
{
protected:
	Film film;
	Time start_time;
	Time end_time; 
	int ticketNumber; 

public:
	Showtime();
	Showtime(Film film, int hall, Time startTime);
	int hall; 
	Film getFilm() const;
	void setFilm(Film x);

	Time getStartTime() const;
	void setStartTime(Time x);

	Time getEndTime() const;
	void setEndTime(Time x);

	int getTicketNumber() const;
	void setTicketNumber(int x); 
};

