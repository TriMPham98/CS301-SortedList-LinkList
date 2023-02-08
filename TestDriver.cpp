// Test driver
#include <iostream>
#include <fstream>
#include <string>

#include "SortedList.h"

using namespace std;

void PrintList(ofstream& outFile, SortedList<int>& list);

int main()
{
	ifstream inFile;       // file containing operations
	ofstream outFile;      // file containing output
	string inFileName;     // input file external name
	string outFileName;    // output file external name
	string outputLabel;
	string command;        // operation to be executed

	int number;
	int item;
	SortedList<int> list;

	bool found;

	// Prompt for file names, read file names, and prepare files
	cout << "Enter name of input command file: ";
	cin >> inFileName;
	inFile.open(inFileName);

	cout << "Enter name of output file: ";
	cin >> outFileName;
	outFile.open(outFileName);

	cout << "Enter name of test run: ";
	cin >> outputLabel;

	outFile << outputLabel << endl;
	if (!inFile)
	{
		cout << "File not found." << endl;
		exit(2);
	}

	inFile >> command;
	//cin >> command;  // use cin instead of inFile if you want to do command line testing instead

	int numCommands = 0;
	while (command != "Quit")
	{
		//cout << "Command: " << command;
		if (command == "PutItem")
		{
			inFile >> item;
			//cin >> item;
			list.PutItem(item);
			outFile << item;
			outFile << " is in list." << endl;
		}
		else if (command == "DeleteItem")
		{
			//inFile >> item;
			cin >> item;
			list.DeleteItem(item);
			outFile << item;
			outFile << " is deleted." << endl;
		}
		else if (command == "Contains")
		{
			inFile >> item;
			//cin >> item;
			if (list.Contains(item)) {
				cout << item << " found in list." << endl;
				outFile << item << " found in list." << endl;
			}
			else {
				cout << item << " not in list." << endl;
				outFile << item << " not in list." << endl;
			}
		}
		else if (command == "GetLength") {
			outFile << "Length is " << list.GetLength() << endl;
		}
		else if (command == "IsFull") {
			if (list.IsFull())
				outFile << "List is full." << endl;
			else outFile << "List is not full." << endl;
		}
		else if (command == "MakeEmpty") {
			list.MakeEmpty();
		}
		else if (command == "PrintList") {
			PrintList(outFile, list);
		}
		else {
			cout << " Command not recognized." << endl;
		}
		numCommands++;
		
		inFile >> command;
		//cin >> command;
	};

	cout << "Quit" << endl << "Testing completed." << endl;
	inFile.close();
	outFile.close();
	return 0;
};


void PrintList(ofstream& dataFile, SortedList<int>& list)
// Pre:  list has been initialized.      
//       dataFile is open for writing.   
// Post: Each component in list has been written to dataFile.
//       dataFile is still open.         
{
	int length;
	int item;
	dataFile << "PrintList" << endl;
	cout << ": ";
	list.ResetIterator();	// Sets currentPos = -1.  Start at the beginning of list

	length = list.GetLength();
	if (length == 0)
		dataFile << "List is empty.";
	else
		for (int counter = 0; counter < list.GetLength(); counter++)
		{
			item = list.GetNextItem();
			dataFile << item << " ";
			cout << item << " ";
		}
	dataFile << endl;
	cout << endl;
}
