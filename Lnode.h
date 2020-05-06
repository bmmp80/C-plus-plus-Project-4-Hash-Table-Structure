/*
CS3100
Data Structures and Algorithms
Brandon Prenger
prenger.30@wright.edu
Meilin Yiu
07/29/2019
Project 4 (Hash Table)
*/

#ifndef _Lnode
#define _Lnode
#include <cstdlib>
#include <string>
//using namespace std;

//header file for Lnode

class Lnode
{
public:
	std::string lastName;
	Lnode* next;
	Lnode()
	{
		next = nullptr;
	}
	Lnode(std::string newName)
	{
		lastName = newName;
		next = nullptr;
	}
};
#endif
#pragma once
