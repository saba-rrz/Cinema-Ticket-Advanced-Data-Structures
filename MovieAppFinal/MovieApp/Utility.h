#pragma once
#include <iostream>
#include "Database.h"
#include "Showtime.h"
#include "Node.h"
#include <string>
#include <conio.h>
#include <cstdlib>
class Utility
{
public:
	static int choice; 
	static void DisplayMenu(); 
	static void CreateMenu(); 
	static void DisplayMovies(); 
	static void DisplayShowtimes(bool showTicketNumber); 
	static void DisplayShowtimes(bool showTicketNumber, int i); 
	static void ReserveTicket(); 
	static void BuyOrCancelReservation();
	static int VerifyChoiceInput(string question, int max);
	static void SearchByCinemaHall(); 
};

