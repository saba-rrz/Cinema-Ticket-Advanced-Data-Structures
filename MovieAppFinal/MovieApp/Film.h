#pragma once
#include <string>

using namespace std; 
class Film
{
protected:
	string title;
	int durationInMinutes;
	string synopsis; 
	string genre; 

public:
	Film();
	Film(string title, int duration, string synopsis, string genre); 
	string getTitle() const;
	void setTitle(string x);

	string getSynopsis() const;
	void setSynopsis(string x);

	string getGenre() const;
	void setGenre(string x);

	int getDuration() const;
	void setDuration(int x);
};

