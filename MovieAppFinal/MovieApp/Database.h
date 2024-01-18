#pragma once
#include "Film.h"
#include "Showtime.h"
#include "LinkedList.h"
#include "BinarySearchTree.h"
#include <queue>
class Database
{
public: 
    static LinkedList films;
    static Showtime showtimes[15];
    static CinemaHalls cinemaHalls[3];
    static void PopulateCinemaHalls();
    static vector<int> reservedTickets; 
    static std::queue<int> queue; 
    static BinarySearchTree bst; 
    static void PopulateMovieList();
    static void PopulateShowtime();
    static void PopulateBST();
    static NodeBinaryTree* root;


};

