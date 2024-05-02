/*
author: kaevin barta
file: linkedlists260.snl
version: .33

The purpose of this is to give me some practice with using a template to implement an unordered linked list.
*/

#include <iostream>
#include "linkedLists.h"//its a good to leave this last for debugging

int main() {
	//adds the linked list & initialize the head
	LinkedList* p1 = nullptr;
	p1 = new LinkedList;
	//commmands
	p1->prepend(8);
	p1->prepend(9);
	p1->append(1);
	p1->prepend(3);
	std::cout << "3 is in the " << p1->find(3) << " postion\n";
	p1->remove(9);
	p1->prepend(8);
	std::cout << "there is " << p1->count() << " number of items.\n";
	p1->print();
	p1->~LinkedList();
	p1->append(9);
	p1->print();
	return 1;
}