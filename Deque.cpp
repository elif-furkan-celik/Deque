#include "Deque.h"

///------------------------------------------------------
/// Default constructor
///
Deque::Deque() {
    // Fill this in
	this->head = NULL;
	this->tail = NULL;
	this->noOfItems = 0;
} //end-Deque

///------------------------------------------------------
/// Destructor
///
Deque::~Deque() {
    // Fill this in
	delete head;
	delete tail;
	this->noOfItems = 0;
} //end-~Deque

///------------------------------------------------------
/// Adds a new item to the front of the Deque
///
void Deque::AddFront(int item) {
    // Fill this in
	DequeNode * temp = new DequeNode(item);

	if(head == NULL){
        head = temp;
        tail = temp;
	}else{
        temp->next = head;
        head->prev = temp;
        head = temp;
	}
    noOfItems++;
} //end-AddFront

///------------------------------------------------------
/// Adds a new item to the end of the Deque
///
void Deque::AddRear(int item) {
	// Fill this in
	DequeNode * temp = new DequeNode(item);

	if(head == NULL){
        head = temp;
        tail = temp;
	}else{
	    tail->next = temp;
        temp->prev = tail;
        tail = temp;
	}
	noOfItems++;
} //end-AddRear

///------------------------------------------------------
/// Remove and return the item at the front of the Deque
/// If the Deque is empty, throw an exception
///
int Deque::RemoveFront() {
	// Fill this in
	DequeNode * temp;
	int tmp;
	if(head == NULL){
        throw "The Deque is empty!";
	}if(noOfItems == 1){
        temp = head;
        tmp = head->item;
        head = NULL;
        tail = NULL;
        delete temp;
        noOfItems--;
        return tmp;
	}else{
        temp = head;
        tmp = head->item;
        head = head->next;
        head->prev = NULL;
        delete temp;
        noOfItems--;
        return tmp;
	}
} //end-RemoveFront

///------------------------------------------------------
/// Remove and return the item at the rear of the Deque
/// If the Deque is empty, throw an exception
///
int Deque::RemoveRear() {
	// Fill this in
	DequeNode * temp;
	int tmp;
	if(head == NULL){
        throw "The Deque is empty!";
	}if(noOfItems == 1){
        temp = tail;
        tmp = tail->item;
        head = NULL;
        tail = NULL;
        delete temp;
        noOfItems--;
        return tmp;
	}else{
        temp = tail;
        tmp = tail->item;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        noOfItems--;
        return tmp;
	}
} //end-RemoveRear

///------------------------------------------------------
/// Return the item at the front of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
///
int Deque::Front() {
	// Fill this in
	if(head == NULL){
        throw "The Deque is empty!";
	}else{
        return head->item;
	}
} //end-Front

///------------------------------------------------------
/// Return the item at the rear of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
///
int Deque::Rear() {
	// Fill this in
	if(head == NULL){
        throw "The Deque is empty!";
	}else{
        return tail->item;
	}
} //end-Rear

