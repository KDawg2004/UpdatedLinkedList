/*
author: kaevin barta
file: linkedlists260.snl
version: .33

The purpose of this is to give me some practice with using a template to implement an unordered linked list.
*/
#pragma once
#include <iostream>

struct Node {
	int data;
	Node* next;
};

class LinkedList {
public:
	//constructor
	LinkedList();
	//deconstructor(uses removeAll function)
	~LinkedList();
	//mutators
	//used for inserting data at beginning @param x - a integer data type 
	bool prepend(const int x);
	//inserting data at the end
	bool append(const int x);
	//Made for removing speicific data off the list @param x - a integer data type 
	bool remove(const int x);
	//Made to delte the entire linked list
	void removeAll();
	//used for detecting duplicates @param x - a node structure type 
	bool removeDuplicates(Node* x);
	//accsessors
	//finds the name @param x - a integer data type 
	int find(const int x);
	//used to print all objects in linked list
	void print();
	//counts all strings in the linked list
	int count();
private:
	Node* head;//the start of the list
};

LinkedList::LinkedList() {
	head = nullptr;
}

bool LinkedList::prepend(const int x) {
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = nullptr;

	if (head == nullptr) {
		head = newNode;
		return true;
	}
	Node* current = head;
	newNode->next = head;
	head = newNode;
	removeDuplicates(newNode);
	return true;	
}

bool LinkedList::append(const int x) {
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = nullptr;

	if (head == nullptr) {//FIRST ENTRY CHECK
		head = newNode;
		return true;
	}
	//itterate through the list until last spot is found
	Node* curr = head->next;//If you do not keep these below the "FIRST ENTRY CHECK" then code will fail.
	Node* prev = head;
	while (curr != nullptr) {
		prev = curr;
		curr = curr->next;
	}
	newNode->next = prev->next;
	prev->next = newNode;
	removeDuplicates(newNode);//checks for duplicates everytime 
	return true;

}

bool LinkedList::removeDuplicates(Node* x){
	Node* p1 = head; // this hold the first postion in the list
	Node* p2; //to check for upcoming data
	Node* p3; //Only use is for deletion 

	while (p1 != nullptr && p1->next != nullptr) {
		p2 = p1;
		while (p2->next != nullptr) {
			if (p1->data == p2->next->data) {
				p3 = p2->next;
				p2->next = p2->next->next;
				delete p3;
			}
			else
				p2 = p2->next;
		}
		p1 = p1->next;
	}
	return false;
}

int LinkedList::count(){
	int i = 0;
	Node* current = head;//counts from the start 
	while (current != nullptr) {//checks for nullptr to find the end
		i += 1;
		current = current->next;
	}
	return i;//returns number of items
}

void LinkedList::print(){
	Node* current = head;//prints from the start
	int x = 0;
	x = count();//to hold the number of items 
	std::cout << "list contains " << x << " numbers: ";
	while (current != nullptr) {
		std::cout << current->data << ", ";
		current = current->next;
	}
	std::cout << "\n";
}

int LinkedList::find(const int x){
	int position = 1;//sense its humans, 1 is the start of the list
	Node* current = head;
	while (current) {//runs untill it comes to nullptr which make it false
		if (current->data == x) {
			return position;
		}
		position++;//counts trough the itterations 
		current = current->next;
	}
	return 0;
}

bool LinkedList::remove(const int x){
	Node* current = head;
	Node* prev = nullptr;

	while (current) {
		if (current->data == x) {
			// If the data is found, remove the node from the list
			if (!prev) {
				head = current->next;
			}
			else {
				prev->next = current->next;
			}
			delete current;//oldest input of that data will be deleted
			return true;
		}
		prev = current;
		current = current->next;
	}
	return false;
}

void LinkedList::removeAll() {
	Node* current = head;//sets it to first postition
	while (current) {//iterates through and deletes all entrys 
		Node* temp = current;
		current = current->next;
		delete temp;
	}
	head = nullptr;//marking the start with a null because thats standard
}

LinkedList::~LinkedList()
{
	removeAll();
}