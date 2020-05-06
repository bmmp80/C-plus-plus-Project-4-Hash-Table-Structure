/*
CS3100
Data Structures and Algorithms
Brandon Prenger
prenger.30@wright.edu
Meilin Yiu
07/29/2019
Project 4 (Hash Table)
*/

#include "Lnode.h"
#include "Slist.h"
#include <iostream>
#include <string>
using namespace std;

//Header file for singly linked list

//Constructor
Slist::Slist()
{
	head = nullptr;
	num = 0;
}

//Destructor
Slist::~Slist()
{
	num = 0;
	Lnode* nextNode = head;
	Lnode* copy;

	//deleting each element of the linked list
	while (nextNode != nullptr)
	{
		copy = nextNode->next;
		delete nextNode;
		nextNode = copy;
	}
}

//Place a new item at the back of the list. 
bool Slist::insert(string lastName)
{
	Lnode* newNode = new Lnode(lastName);
	Lnode* prev = head;
	Lnode* next = head;
	bool newBucket;
	while (next != nullptr)
	{
		prev = next;
		next = next->next;
	}
	if (head == nullptr)
	{
		head = newNode;
		newBucket = true;
	}
	else
	{
		prev->next = newNode;
		newBucket = false;
	}
	num++;
	return newBucket;
}

//delete part of the list.
bool Slist::remove(string lastName)
{
	Lnode* prev = head;
	Lnode* next = head;
	while ((next != nullptr) && (next->lastName != lastName))
	{
		prev = next;
		next = next->next;
	}
	if (next == nullptr)
	{
		return false;
	}
	else
	{
		if (head == next)
		{
			head = next->next;
		}
		else
		{
			prev->next = next->next;
		}
		delete next;
		num--;
		return true;
	}
}

//search for a last name.
bool Slist::search(string lastName)
{
	Lnode* next = head;
	while ((next != nullptr) && (next->lastName != lastName))
	{
		next = next->next;
	}
	if (next == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//Returns true if the list is empty, otherwise returns false.
bool Slist::is_empty() const
{
	return (head == nullptr);
}

//Returns the number of elements in the list.
int Slist::size() const
{
	return num;
}

//Print all the elements in the list onto the screen. 
void Slist::print(ostream& outFile) const
{
	Lnode* next = head;
	while (next != nullptr)
	{
		outFile << next->lastName << " ";
		next = next->next;
	}
	cout << endl;
}