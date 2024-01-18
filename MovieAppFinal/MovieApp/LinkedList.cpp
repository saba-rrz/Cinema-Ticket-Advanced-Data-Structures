#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() {
    this->head = NULL;
}
void LinkedList::insert(Film data) {
    Node* new_node = new Node(data);
    if (this->head == NULL) {
        this->head = new_node;
    }
    else {
        Node* temp = this->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
void LinkedList::remove(Film data) {
    Node* temp = this->head;
    Node* prev = NULL;
    while (temp != NULL && temp->data.getTitle() != data.getTitle()) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    }
    else {
        prev->next = temp->next;
    }
    delete temp;
}
void LinkedList::display() {
    Node* temp = this->head;
    while (temp != NULL) {
        cout << "Title: " << temp->data.getTitle() << endl;
        cout << "Duration (in minutes): " << temp->data.getDuration() << endl;
        cout << "Synopsis: " << temp->data.getSynopsis() << endl;
        cout << "Genre: " << temp->data.getGenre() << endl;
        cout << endl; // add a newline for readability
        temp = temp->next;
    }
    cout << endl;
}
//Insert at Beginning: This function is used to insert a new node
//at the beginning of the list.
void LinkedList::insertAtBeginning(Film data) {
    Node* new_node = new Node(data);
    if (head == NULL) {
        head = new_node;
    }
    else {
        new_node->next = head;
        head = new_node;
    }
}
//Insert at Position: This function is used to insert a new node 
//at a specific position in the list.
void LinkedList::insertAtPosition(Film data, int position) {
    Node* new_node = new Node(data);
    if (head == NULL) {
        head = new_node;
    }
    else {
        Node* temp = head;
        Node* prev = NULL;
        int count = 0;
        while (temp != NULL && count < position) {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if (prev == NULL) {
            new_node->next = head;
            head = new_node;
        }
        else {
            prev->next = new_node;
            new_node->next = temp;
        }
    }
}
//Get Node at Position: This function is used to get the node at
//a specific position in the list.
Node* LinkedList::getNodeAtPosition(int position) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
    return temp;
}
//Get Length: This function is used to get the number of nodes in the list.
int LinkedList::getLength() {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}
//Clear List: This function is used to delete all the nodes in the list.
void LinkedList::clear() {
    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = NULL;
}