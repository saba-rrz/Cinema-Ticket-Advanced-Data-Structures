#pragma once
#include <cstddef>
#include <iostream>
#include "Node.h"
class LinkedList
{
private:
    Node* head;
public:
    LinkedList();
    void insert(Film data);
    void remove(Film data);
    void display();
    //Insert at Beginning: This function is used to insert a new node
    //at the beginning of the list.
    void insertAtBeginning(Film data);
    //Insert at Position: This function is used to insert a new node 
    //at a specific position in the list.
    void insertAtPosition(Film data, int position);
    //Get Node at Position: This function is used to get the node at
    //a specific position in the list.
    Node* getNodeAtPosition(int position);
    //Get Length: This function is used to get the number of nodes in the list.
    int getLength();
    //Clear List: This function is used to delete all the nodes in the list.
    void clear();
};

