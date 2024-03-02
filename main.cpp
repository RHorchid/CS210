/*
* Ryan Howard
* Project 3
* This program uses a map to track items for a grocery store.
*/

#include "Inventory.h"

using namespace std;



void DisplayMenu(); //Function to display menu for user
int GetSelection(); //Function to retrieve user input menu selection

// Constant global int variable to store exit program selection
const int SENTINEL = 4;

int main() {
	string inputFile = "CS210_Project_Three_Input_File.txt"; //String variable to hold input file name
	int selection = 0; //Int variable to hold user selection value from menu
	Inventory itemInventory; //Inventory object to create map from the given input file and manipulate data as necessary

	itemInventory.ProcessInputFile(inputFile); //Call to function to process input file into a map

	//Do-while loop to run the program unitl user chooses to exit

	do {
		DisplayMenu();
		selection = GetSelection();
		itemInventory.ProcessSelection(selection);
	} while (selection != 4);

}//End main()

void DisplayMenu() {
	cout << "Enter 1 to look up item frequency." << endl;
	cout << "Enter 2 to print a frequency list." << endl;
	cout << "Enter 3 to print a frequency histogram." << endl;
	cout << "Enter " << SENTINEL << " to exit." << endl;
	cout << endl;
}// End DisplayMenu()

int GetSelection() {
	int selection = 0;
	bool inputValid = true;

	do {
		cout << "Enter your selection: ";
		cin >> selection;
		inputValid = ((selection < 1) || (selection > SENTINEL));
		if (inputValid) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input, please enter from 1 to " << SENTINEL << endl;
			cout << endl;
		}
	} while (inputValid);

	cout << endl;

	return selection;
}// End Getelection()



