/*
CS3100
Data Structures and Algorithms
Brandon Prenger
prenger.30@wright.edu
Meilin Yiu
07/29/2019
Project 4 (Hash Table)
*/

#ifndef _Slist
#define _Slist
#include "Lnode.h"
#include <string>
#include <fstream>
#include <iostream>
//using namespace std;

//Header file for singly linked list
class Slist
{
public:
	//Constructor
	Slist();

	//Destructor
	~Slist();

	//Place a new item at the back of the list. 
	bool insert(std::string lastName);

	//delete part of the list.
	bool remove(std::string lastName);

	//search for a last name.
	bool search(std::string lastName);

	//Returns true if the list is empty, otherwise returns false.
	bool is_empty() const;

	//Returns the number of elements in the list.
	int size() const;

	//Print all the elements in the list onto the screen. 
	void print(std::ostream& outFile) const;


private:
	Lnode* head;
	// The top of the Linked List based list.
	int num;
	//the number of elements in the list.
};
#endif