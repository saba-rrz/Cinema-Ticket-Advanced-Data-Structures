#include "Utility.h"
#include "Database.h"

using namespace std;

int Utility::choice = 0;

void Utility::DisplayMenu()
{
	// Clear the console
	system("cls");

	// Display the menu
	cout << "*************************************" << endl;
	cout << "* Welcome to the Movie Application! *" << endl;
	cout << "*************************************" << endl;
	cout << "1. Display all current movies (LinkedList)" << endl;
	cout << "2. Display all showtimes (Array)" << endl;
	cout << "3. Reserve tickets (Queue)" << endl;
	cout << "4. Buy or cancel reserved tickets" << endl;
	cout << "5. Information about the cinema halls (Binary Search Tree)" << endl;
	cout << "6. Quit" << endl;
}

void Utility::CreateMenu()
{
	//populate the database
	
	Database::PopulateMovieList();
	Database::PopulateShowtime();
	Database::PopulateCinemaHalls();
	Database::PopulateBST(); 
	do
	{
		//Display the menu
		DisplayMenu();
		choice = VerifyChoiceInput("Enter a number from the menu: ", 6);
		switch (choice)
		{
		case 1:
			//Display movies
			DisplayMovies();
			_getch();
			break;
		case 2:
			//Display showtimes
			DisplayShowtimes(false);
			_getch();
			break;
		case 3:
			ReserveTicket();
			_getch();
			break;
		case 4:
			BuyOrCancelReservation();
			_getch();
			break;
		case 5:
			SearchByCinemaHall();
			_getch();
			break;
		}
	} while (choice != 6);
}

void Utility::SearchByCinemaHall() 
{
	system("cls");
	choice = VerifyChoiceInput("Enter the movie hall: ", sizeof(Database::cinemaHalls) / sizeof(Database::cinemaHalls[0])); 
	NodeBinaryTree* searchResult = Database::bst.searchNode(Database::root, Database::cinemaHalls[choice - 1]);
	CinemaHalls current = searchResult->data; 
	system("cls");
	for (Showtime showtime : current.showtimes) {
		DisplayShowtimes(false, showtime.getTicketNumber() - 1); 
	}
}
void Utility::ReserveTicket()
{
	bool repeat = true;

	cout << "Available Movies: " << endl;
	DisplayShowtimes(true);

	do {

		bool found = false;

		do {
			found = false;

			choice = VerifyChoiceInput("Enter a ticket number to reserve it: ", sizeof(Database::showtimes) / sizeof(Database::showtimes[0]));

			std::queue<int> copyQueue = Database::queue; // Create a copy of the queue
			while (!copyQueue.empty()) {
				if (copyQueue.front() == (choice - 1)) {
					found = true;
					break;
				}
				copyQueue.pop();
			}

			if (found) {
				cout << endl;
				std::cout << "You have already reserved this ticket. Please choose another one." << std::endl;
			}
			else {
				// Add the choice to the queue
				Database::queue.push(choice - 1);
				found = false;
			}
		} while (found);

		cout << endl;
		cout << "You have " << Database::queue.size() << " reservations." << endl;
		cout << "Your reservations are: " << endl;
		for (int i = 0; i < Database::queue.size(); i++) {
			cout << endl;
			DisplayShowtimes(false, i);
		}
		choice = VerifyChoiceInput("Enter 1 to reserve another movie or 2 to continue with your current selection: ", 2);
		if (choice == 2) {
			repeat = false;
		}
	} while (repeat);
}

void Utility::BuyOrCancelReservation()
{
	system("cls");
	if (Database::queue.size() != 0) {
		while (Database::queue.size() != 0) {
						DisplayShowtimes(false, Database::queue.front());
						choice = VerifyChoiceInput("Enter 1 to purchase or 2 to remove reservation: ", 2);
						if (choice == 1) {
							cout << "Movie ticket purchased!" << endl;
						}
						else {
							cout << "Reservation removed." << endl;
						}
						Database::queue.pop();
						cout << endl;
		}
	}
	else {
		cout << "You have no reservations. Please, reserve a ticket and come back again." << endl;
	}
	cout << "Press any key to go back to main menu: " ;
	std::cin.get();
}


void Utility::DisplayMovies()
{
	system("cls");
	Database::films.display();
}

void Utility::DisplayShowtimes(bool showTicketNumber)
{
	system("cls");
	for (int i = 0; i < 15; i++) {
		cout << "Film Title: " << Database::showtimes[i].getFilm().getTitle() << endl;
		cout << "Hall: " << Database::showtimes[i].hall << endl;
		cout << "Duration: " << Database::showtimes[i].getFilm().getDuration() << " minutes" << endl;
		cout << "Start Time: ";
		Database::showtimes[i].getStartTime().printTime();
		cout << "End Time: ";
		Database::showtimes[i].getEndTime().printTime();
		if (showTicketNumber) {
			cout << "Ticket Number: " << Database::showtimes[i].getTicketNumber() << endl;
		}
		cout << endl;
	}
}

void Utility::DisplayShowtimes(bool showTicketNumber, int i)
{
	cout << "Film Title: " << Database::showtimes[i].getFilm().getTitle() << endl;
	cout << "Hall: " << Database::showtimes[i].hall << endl;
	cout << "Duration: " << Database::showtimes[i].getFilm().getDuration() << " minutes" << endl;
	cout << "Start Time: ";
	Database::showtimes[i].getStartTime().printTime();
	cout << "End Time: ";
	Database::showtimes[i].getEndTime().printTime();
	if (showTicketNumber) {
		cout << "Ticket Number: " << Database::showtimes[i].getTicketNumber() << endl;
	}
	cout << endl;
}

int Utility::VerifyChoiceInput(string question, int max)
{
	//verify input
	int value;
	cout << question;
	cin >> value;
	while (cin.fail() || cin.peek() != '\n' || value <= 0 || value > max) {
		cin.clear();
		cin.ignore(512, '\n');
		cout << "ERROR! Enter a valid number: ";
		cin >> value;
	}
	return value;
};