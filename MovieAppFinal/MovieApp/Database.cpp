#include "Database.h"
#include "LinkedList.h"

Showtime Database::showtimes[15];
CinemaHalls Database::cinemaHalls[3];
LinkedList Database::films;
vector<int> Database::reservedTickets;
std::queue<int> Database::queue;
BinarySearchTree Database::bst;
NodeBinaryTree* Database::root;

void Database::PopulateBST() 
{
	root = nullptr; 
	for (CinemaHalls hall : cinemaHalls) 
	{
		root = bst.insertNode(root, hall); 
	}
}

void Database::PopulateCinemaHalls() 
{
	int y = 0; 
	for (int i = 0; i < sizeof cinemaHalls / sizeof cinemaHalls[0]; i++) {
		for (int j = 0; j < 5; j++) {
			cinemaHalls[i].showtimes.push_back(showtimes[y]);
			cinemaHalls[i].number = i; 
			showtimes[y].hall = i + 1; 
			y++; 
		}
	}
}


void Database::PopulateMovieList() {
	films.insert(Film("The Matrix", 136, "A hacker learns that reality is a computer simulation.", "Science Fiction"));
	films.insert(Film("The Shawshank Redemption", 142, "A man is falsely convicted of murder and sent to prison.", "Drama"));
	films.insert(Film("The Godfather", 175, "The patriarch of a powerful mafia family transfers control to his reluctant son.", "Crime"));
	films.insert(Film("The Dark Knight", 152, "Batman must confront the Joker, a criminal mastermind wreaking havoc on Gotham City.", "Action"));
	films.insert(Film("Forrest Gump", 142, "A simple man with a low IQ experiences key moments in American history.", "Drama"));
	films.insert(Film("Star Wars: Episode IV - A New Hope", 121, "A young farm boy joins a group of rebels to fight against an evil empire.", "Science Fiction"));
	films.insert(Film("Pulp Fiction", 154, "The lives of various criminals intertwine in a series of violent and unexpected events.", "Crime"));
	films.insert(Film("The Lord of the Rings: The Fellowship of the Ring", 178, "A hobbit and his companions set out to destroy a powerful ring before it falls into the wrong hands.", "Fantasy"));
	films.insert(Film("The Silence of the Lambs", 118, "An FBI agent seeks the help of a cannibalistic serial killer to catch another killer.", "Thriller"));
	films.insert(Film("The Lion King", 88, "A young lion prince must reclaim his throne from his uncle.", "Animation"));
	films.insert(Film("The Terminator", 107, "A cyborg assassin is sent back in time to kill a woman whose son will one day lead a resistance against machines.", "Science Fiction"));
	films.insert(Film("Jaws", 124, "A giant man-eating shark terrorizes a New England beach town.", "Horror"));
	films.insert(Film("Jurassic Park", 127, "A billionaire invites a group of scientists to tour his new dinosaur theme park, but things quickly go awry.", "Science Fiction"));
	films.insert(Film("Gone with the Wind", 238, "A manipulative Southern belle and a roguish blockade runner fall in love during the American Civil War.", "Romance"));
	films.insert(Film("Titanic", 194, "A poor artist and a rich woman fall in love aboard the doomed ship.", "Romance"));
}

void Database::PopulateShowtime() {
	Time startTime(9, 0, 23, 4); // starting time (9:00 AM on April 23st)
	Node* current = films.getNodeAtPosition(0);
	for (int i = 0; i < 15 && current != nullptr; i++) {
		Film film = current->data;
		Showtime showtime(film, i + 1, startTime);
		showtimes[i] = showtime;
		int totalMinutes = startTime.hour * 60 + startTime.minute + film.getDuration() + 15;
		int hours = totalMinutes / 60 % 24;
		int minutes = totalMinutes % 60;
		int days = totalMinutes / (24 * 60);
		startTime = Time::Time(hours, minutes, startTime.day + days, startTime.month);
		// Move to next node in linked list
		current = current->next;
	}
}

