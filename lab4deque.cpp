#include "Deque.h"
#include <iostream>

using namespace std;

struct mamba_byte : exception {
	const char* what() const noexcept
	{
		return "Deque Is Empty";
	}
};
///------------------------------------------------------
/// Default constructor
/// 
Deque::Deque() {
	this->head = NULL;
	this->tail = NULL;
	noOfItems = 0;

} //end-Deque

///------------------------------------------------------
/// Destructor
/// 
Deque::~Deque() {
	DequeNode* CurrentNode = this->head;
	while (CurrentNode != NULL)
	{
		DequeNode* temp = CurrentNode;
		CurrentNode = CurrentNode->next;
		delete CurrentNode;
	}

} //end-~Deque

///------------------------------------------------------
/// Adds a new item to the front of the Deque
/// 
void Deque::AddFront(int item) {
	DequeNode* node = new DequeNode(item);
	if (this->head == NULL)
	{
		this->head = node; //if head is null the new node we add front will be the only element that present. new node will be equal to both tail and head.
		this->tail = node;
	}
	else
	{
		this->head->prev = node;//the current head's previous will be queal to new node. new node's next will be equal to head 
		node->next = this->head;
		this->head = node;// new node is equal to head
	}
	// Increment size
	noOfItems++;

} //end-AddFront

///------------------------------------------------------
/// Adds a new item to the end of the Deque
/// 
void Deque::AddRear(int item) {
	DequeNode* node = new DequeNode(item);
	if (this->head == NULL)
	{
		this->head = node;//if head is null the new node we add front will be the only element that present. new node will be equal to both tail and head.
		this->tail = node;
	}
	else
	{
		this->tail->next = node;//tail will point to new node
		node->prev = this->tail;// new node's previous will be equal to tail
		this->tail = node;
	}
	// Increment size
	noOfItems++;
} //end-AddRear

///------------------------------------------------------
/// Remove and return the item at the front of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveFront() {
	try
	{
		int item = -11111; //because we will return the this item we need to declare it as a integer
		if (this->head != NULL)
		{
			if (this->head == this->tail)
			{
				item = this->head->item; //only one element present and we delete it, tail and head must be null
				delete this->head;
				this->head = NULL;
				this->tail = NULL;
			}
			else
			{
				item = this->head->item;// head will point to item that we can delete it without losing the data of head
				this->head = this->head->next;// new head will be equal to current heads next
				delete this->head->prev;
				this->head->prev = NULL;// we are freeing the memory by adding this line
			}
		}
		noOfItems--;// Decrement size
		return item;
	}
	catch (const std::exception& enesk)
	{
		cerr << "Exception: " << enesk.what() << endl;
	}

} //end-RemoveFront

///------------------------------------------------------
/// Remove and return the item at the rear of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveRear() {
	int item = -11111;
	try
	{
		if (this->head != NULL)
		{
			if (this->head == this->tail)
			{
				item = this->head->item;//only one element present and we delete it, tail and head must be null
				delete this->head;
				this->head = NULL;
				this->tail = NULL;
			}
			else
			{
				item = this->tail->item;//item will be queal to tail so we can return it later
				this->tail = this->tail->prev;// tail's prev will be equal to new tail
				delete this->tail->next;
				this->tail->next = NULL;// freeing memory by pointing new tails memory to null
			}
		}
		noOfItems--;// Decrement size
		return item;
	}
	catch (const std::exception& enesk)
	{
		cerr << "Exception: " << enesk.what() << endl;
	}


} //end-RemoveRear

///------------------------------------------------------
/// Return the item at the front of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Front() {
	try
	{
		int item = -11111;
		if (this->head != NULL) {
			item = this->head->item;//returnning head if it is not null
		}
		return item;
	}
	catch (const std::exception& enesk)
	{
		cerr << "Exception: " << enesk.what() << endl;
	}
	// Fill this in
} //end-Front

///------------------------------------------------------
/// Return the item at the rear of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Rear() {
	try
	{
		int item = -11111;
		if (this->tail != NULL) {
			item = this->tail->item;//returnnint tail if its not null
		}
		return item;
	}
	catch (const std::exception& enesk)
	{
		cerr << "Exception: " << enesk.what() << endl;
	}
} //end-Rear