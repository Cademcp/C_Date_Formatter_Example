/*
	Author: Cade McPartlin
	File: Lab4.cpp 
	Description: Main file for Lab4 assignment. Handles two different situations in the program and runs the correct methods for each situation

*/
#include <iostream>
#include "Date.h"
#include "Date.cpp"
using namespace std;

int main() {
	
	//handling the while loop
	int input, month, day, year;
	cout << "Enter 1 for format: MM/DD/YYYY\nEnter 2 for format: Month DD, YYYY\nEnter 3 to exit\nChoice: " << endl;
	cin >> input;
	string monthStr;
	
	//keeps the program running until the user enters 3 in the menu
	while (input != 3) {
		switch(input) {
			
			//prompts the user for the month, day, and year in number form. Then will return the date using the print() method
			case 1:
			{	
				cout << "Enter Month (1-12): " << flush;
				cin >> month;
				cout << "Enter Day of Month: " << flush;
				cin >> day;
				cout << "Enter Year: " << flush;
				cin >> year;
				Date myDate = Date(month, day, year); 
				myDate.print();
				cout << "\nEnter 1 for format: MM/DD/YYYY\nEnter 2 for format: Month DD, YYYY\nEnter 3 to exit\nChoice: " << endl;
				cin >> input;
				break;
			}	
	
			//prompts the user for the month, day, and year in long date format. Then will return the date using the printFullDate() method
    		case 2:
    		{
	            cout <<  "Enter Month Name: " << flush;
	            cin >> monthStr;
	            cout <<  "Enter Day of Month: " << flush;
	            cin >> day;
	            cout <<  "Enter Year: " << flush;
	            cin >> year;
	            cout << endl;
	            Date myDate = Date(monthStr, day, year);
	            myDate.printFullDate();
	            cout << "\nEnter 1 for format: MM/DD/YYYY\nEnter 2 for format: Month DD, YYYY\nEnter 3 to exit\nChoice: " << endl;
				cin >> input;
	            break;
    		}
        	
        	//Handles errors of users entering a number other than 1, 2, or 3
       		default:
        		cout << "Please enter a vaild number 1-3" << endl;
        		cout << "\nEnter 1 for format: MM/DD/YYYY\nEnter 2 for format: Month DD, YYYY\nEnter 3 to exit\nChoice: " << endl;
				cin >> input;
        		break;
		}
	}
	
	
	return 0;
}

