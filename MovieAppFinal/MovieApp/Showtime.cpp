#include "Showtime.h"
//Constructor


Showtime::Showtime()
{
}

Showtime::Showtime(Film film, int ticketNumber, Time startTime)
{
    this->film = film;
    this->start_time = startTime;
    this->ticketNumber = ticketNumber; 
    int hour = film.getDuration() / 60;
    int minute = film.getDuration() % 60;
    this->end_time = Time::Time(startTime.hour + hour, startTime.minute + minute, startTime.day, startTime.month);
}

//Get/set
Film Showtime::getFilm() const
{
    return this->film;
}

void Showtime::setFilm(Film x)
{
    this->film = x;
}

Time Showtime::getStartTime() const
{
    return this->start_time;
}

void Showtime::setStartTime(Time x)
{
    this->start_time = x;
}

Time Showtime::getEndTime() const
{
    return this->end_time;
}

void Showtime::setEndTime(Time x)
{
    this->end_time = x;
}

int Showtime::getTicketNumber() const
{
    return this->ticketNumber;
}

void Showtime::setTicketNumber(int x)
{
    this->ticketNumber = x;
}



