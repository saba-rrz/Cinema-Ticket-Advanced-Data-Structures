#include "Film.h"

//Constructor
Film::Film()
{
}

Film::Film(string title, int duration, string synopsis, string genre)
{
	this->title = title; 
	this->durationInMinutes = duration;
	this->synopsis = synopsis;
	this->genre = genre; 
}

//Get/Set

string Film::getTitle() const
{
	return this->title;
}

void Film::setTitle(string x)
{
	this->title = x;
}

string Film::getSynopsis() const
{
	return this->synopsis;
}

void Film::setSynopsis(string x)
{
	this->synopsis = x;
}

string Film::getGenre() const
{
	return this->genre;
}

void Film::setGenre(string x)
{
	this->genre = x;
}

int Film::getDuration() const
{
	return this->durationInMinutes;
}

void Film::setDuration(int x)
{
	this->durationInMinutes = x;
}
