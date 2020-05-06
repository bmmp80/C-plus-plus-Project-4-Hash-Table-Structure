/*
CS3100
Data Structures and Algorithms
Brandon Prenger
prenger.30@wright.edu
Meilin Yiu
07/29/2019
Project 4 (Hash Table)
*/
#ifndef _Htable
#define _Htable
#include "Slist.h"
#include <fstream>
#include <string>
//using namespace std;

class Htable
{
public: 
	Htable();

	Htable(int hashFunction, int hSize);

	~Htable();
	
	int insert(std::string lastName);

	int search(std::string lastName);

	int remove(std::string lastName);

	void logFile();

	void print(std::ostream& outFile);

	int getNumBuckets();

private:
	Slist* table;
	int tableSize;
	int hashFunction1(std::string lastName);
	int hashFunction2(std::string lastName);
	int numElements;
	int numBuckets;
	int ID;
};
#endif