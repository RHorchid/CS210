#include "Inventory.h"

Inventory::Inventory() {
	outputFilePath = "frequency.dat";
}//End Constructor

void Inventory::ProcessSelection(int selection) {
	string userItem;

	switch (selection) {
	case 1:
		cout << "Enter an item (First letter uppercase only): ";
		cin >> userItem;
		cout << "The frequency of " << userItem << " is " << inventoryMap[userItem] << endl << endl;
		break;
	case 2:
		PrintItemFrequency();
		break;
	case 3:
		PrintItemHistogram();
		break;
	case 4:
		BackupData();
		break;
	default:
		cout << "Invalid choice, please enter a valid number." << endl;
		break;

	}//End switch
}//End ProcessSelection()


void Inventory::ProcessInputFile(const string& filePath) {
	ifstream inputFile(filePath);
	string item;

	if (inputFile.is_open()) {
		while (getline(inputFile, item)) {
			inventoryMap[item]++;
		}//End while
		inputFile.close();
	}
	else {
		cout << "File unable to open." << endl;
	}
}//End ProcessInputFile()

void Inventory::BackupData() {
	ofstream outputFile("frequency.dat");

	for (const auto& pair : inventoryMap) {
		outputFile << pair.first << " " << pair.second << endl;
	}
	outputFile.close();

	cout << "The data has been saved into the 'frequency.dat' file." << endl;
}//End BackupData()

void Inventory::PrintItemFrequency() {
	for (const auto& pair : inventoryMap) {
		cout << pair.first << " " << pair.second << endl;
	}
	cout << endl;
}//End PrintItemFrequency()

void Inventory::PrintItemHistogram() {
	for (const auto& pair : inventoryMap) {
		cout << pair.first << " ";
		for (int i = 0; i < pair.second; i++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
}//End PrintItemHistogram()