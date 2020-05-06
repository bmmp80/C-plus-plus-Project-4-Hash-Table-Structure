/*
CS3100
Data Structures and Algorithms
Brandon Prenger
prenger.30@wright.edu
Meilin Yiu
07/29/2019
Project 4 (Hash Table)
*/
#include "Htable.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
{
	//file to open: C:\Users\Brandon\Desktop\CS3100\Projects\Project4\all.last.txt

	string lastName;
	int size;
	cout << "Enter size of table: " << endl;
	cin >> size;
	int bucketNumber;

	cout << "Enter number of records to read: " << endl;
	int numRecs;
	cin >> numRecs;

	Htable myTable1(1, size);
	Htable myTable2(2, size);

	//Prompts user to open a file to use as a database
	string filename;
	cout << "which file do you want to open? ";
	cin >> filename;

	ifstream my_stream;
	my_stream.open(filename);
	if (my_stream.is_open())
	{
		cout << "open file" << endl;
		for (int i = 0; i < numRecs; i++)
		{
			my_stream >> lastName;
			cout << lastName << endl;
			myTable1.insert(lastName);
			myTable2.insert(lastName);
			cout << "Table 1: " << endl;
			myTable1.print(cout);
			cout << "Table 2: " << endl;
			myTable2.print(cout);
		}
		cout << "Table 1 number of buckets: " << myTable1.getNumBuckets() << endl;
		cout << "Table 2 number of buckets: " << myTable2.getNumBuckets() << endl;

		cout << "Load factor: " << numRecs / size << endl;

		bool quit = false;
		char option = 'Q';


		
		//Creating user interface.
		while (!quit)
		{
			cout << "I to insert new record" << endl;
			cout << "D to delete record" << endl;
			cout << "S for last name search" << endl;
			cout << "L to save database to a log file" << endl;
			cout << "Q to quit the program" << endl;
			cin >> option;

			
			switch (option)
			{
			case 'I':
				/*Insert new Entry: prompt user for a last name, insert it into the Hash Table. Your implemen-
				tation should detect the insertion of a duplicated last name and reject the insertion. Display
				information telling whether or not the insertion is successful; if successful, display the bucket
				number that the last name is inserted.*/
				cout << "Enter a last name to insert: ";
				cin >> lastName;
				if (myTable1.search(lastName) != -1)
				{
					cout << "Error: last name already in table" << endl;
				}
				else
				{
					bucketNumber = myTable1.insert(lastName);
					cout << "Success, inserted at: " << bucketNumber << endl;
				}
				break;

			case 'D':
				/*Delete an Entry: Ask the user for a last name and delete it from the Hash Table. Display
				information telling whether or not the deletion is successful. If successful, display the last
				name and the corresponding bucket number. Display information telling the delete is not
				successful, i.e., last name: not found.*/
				cout << "Enter a last name to delete: " << endl;
				cin >> lastName;

				if (myTable1.search(lastName) == -1)
				{
					cout << "Error: last name not in table" << endl;
				}
				else
				{
					bucketNumber = myTable1.remove(lastName);
					cout << "Success, removed: " << lastName << "at bucket number: " << bucketNumber << endl;
				}
				break;
			case 'S':
				cout << "Enter a last name to search: " << endl;
				cin >> lastName;
				bucketNumber = myTable1.search(lastName);
				if (bucketNumber == -1)
				{
					cout << "Error: last name not in table" << endl;
				}
				else
				{
					cout << "Success, found " << lastName << "at bucket number: " << bucketNumber << endl;
				}
				break;
			case 'L':
				/*Logle: Write a formatted display of the hash table to the log le. The display should list
				each bucket of the Hash Table, indicating that the bucket is empty, or showing the key value.*/
				myTable1.logFile();
				break;
			case 'Q':
			{
				//quit
				quit = true;
				break;
			}
			default:
				cout << "Error: reached default case" << endl;
				break;
			}
		}
		my_stream.close();
	}
	else
	{
		cout << "Error: unable to open file";
	}
	return 0;
}
