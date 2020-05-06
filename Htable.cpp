/*
CS3100
Data Structures and Algorithms
Brandon Prenger
prenger.30@wright.edu
Meilin Yiu
07/29/2019
Project 4 (Hash Table)
*/
#include "Slist.h"
#include "Htable.h"
#include <iostream>
using namespace std;


Htable::Htable()
{
	tableSize = 20;
	table = new Slist[tableSize];
	numElements = 0;
	numBuckets = 0;
	ID = 1;
}

Htable::Htable(int hashFunction, int hSize)
{
	tableSize = hSize;
	table = new Slist[tableSize];
	numElements = 0;
	numBuckets = 0;
	ID = hashFunction;
}

Htable::~Htable()
{
	delete[] table;
}

int Htable::insert(string lastName)
{
	int bucket;
	bool newBucket;
	if (ID == 1)
	{
		bucket = hashFunction1(lastName);
	}
	else
	{
		bucket = hashFunction2(lastName);
	}
	newBucket = table[bucket].insert(lastName);
	if (newBucket)
	{
		numBuckets++;
	}
	numElements++;
	return bucket;
}

int Htable::getNumBuckets()
{
	return numBuckets;
}


int Htable::search(string lastName)
{
	int bucket;
	//bool newBucket;
	if (ID == 1)
	{
		bucket = hashFunction1(lastName);
	}
	else
	{
		bucket = hashFunction2(lastName);
	}
	if (table[bucket].search(lastName))
	{
		return bucket;
	}
	else
	{
		return -1;
	}
}

int Htable::remove(string lastName)
{
	int bucket;
	//bool newBucket;
	if (ID == 1)
	{
		bucket = hashFunction1(lastName);
	}
	else
	{
		bucket = hashFunction2(lastName);
	}
	if (table[bucket].remove(lastName))
	{
		return bucket;
	}
	else
	{
		return -1;
	}
}

void Htable::logFile()
{
	cout << "Enter output file name: ";
	string fileName;
	cin >> fileName;
	ofstream outfile(fileName);
	print(outfile);
	outfile.close();
}

void Htable::print(ostream& outFile)
{
	for (int i = 0; i < tableSize; i++)
	{
		outFile << i << ": ";
		table[i].print(outFile);
	}
}

int Htable::hashFunction1(string lastName)
{
	int hash = 5381;
	for (int i = 0; i < (int)lastName.size(); i++)
	{
		hash = (hash * 33) + (lastName[i] - '0');
	}
	return ((int)hash % (int)tableSize);
}

int Htable::hashFunction2(string lastName)
{
	int hash = 0;
	for (int i = 0; i < (int)lastName.size(); i++)
	{
		hash = hash + (lastName[i] - '0');
	}
	return hash % tableSize;
}
