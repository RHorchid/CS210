#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// Class to organize functions related to the inventory map

class Inventory {
private:
	map<string, int> inventoryMap; //Map to organize data from input file
	string outputFilePath; //String variable to hold output data file name

public:
	Inventory(); //Constructor to initialze variable
	void ProcessInputFile(const string& filePath); //Function to process the data from input file into map
	void BackupData(); //Function to write map into an output file
	void PrintItemFrequency(); //Function to print the frequency of all items
	void PrintItemHistogram(); //Function to print the frequency of all items as a histogram
	void ProcessSelection(int); //Function to process user selection from menu
};

#endif
