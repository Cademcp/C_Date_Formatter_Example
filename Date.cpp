/*
	Author: Cade McPartlin
	File: Date.cpp 
	Description: Date.cpp holds the constructors and print statements for the Date class. Also handles formatting of the output

*/
#include <array>
#include <iostream>
#include <sstream>
#include "Date.h"

using namespace std;

//array of the number of days in each month
const array<unsigned int, 13> Date::days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//constructor to handle all number format of date
Date::Date (  int mn,  int dy,  int yr ) {

	//confirming date is between 1-12
	if (mn >= 1 && mn <= 12) {
		month = mn;
	} else {
		throw invalid_argument{"Month must be 1-12"};
	}
	//making sure the year is not negative 
	if (yr > 0) {
		year = yr;
	} else {
		throw invalid_argument{"Year must be greater than 0"};
	}
	//checking for a leap year
	if ((mn ==2 && leapYear(year) && dy >= 1 && dy <= 29) || (dy >= 1 && dy <= days[mn])) {
		day = dy;
	} else {
		throw invalid_argument {"Day is out of range for current month and year"};
	}
}

//constructor for the string version of the date
Date::Date ( string mstr,  int dd,  int yy ) 
{  
	monthString = mstr;
	day = dd;
	
	//making sure the year is not negative
	if (yy > 0) {
		year = yy;
	} else {
		throw invalid_argument{"Year must be greater than 0"};
	}
}

//method used to check for leap years
bool Date::leapYear(int year) {
	return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

//print method for numerical date format. Will print date in numerical format, then in string format
void Date::print() {

	ostringstream output;
	output << month << '/' << day << '/' << year;
	cout << "\nMM/DD/YYYY: " << output.str() << endl;
	ostringstream output2;
	output2 << Date::getMonthName(month) << " " << day << "," << year;
	cout << "Month DD, YYYY: " << output2.str() << endl;
	cout << "**********" << endl;
}

//print method for string format. Will print what month was enterd in a string, then the date in numerical format, then the date in string format 
void Date::printFullDate() {
	ostringstream output;
	output << Date::getMonthString() << " " << day << ','<< year;
	cout << "month:" << Date::getMonthString() << "\nMM/DD/YYYY: " << Date::getMonthNumber(monthString)  << '/' << day << '/' << year << "\nMonth DD, YYYY: " << output.str() << endl;
	cout << "**********" << endl;
}

//method used for getting the month string that goes along with the numerical value
string Date::getMonthName(int monthNum) {
	switch(monthNum) {
		case 1:
			return "January";
			break;
		case 2:
			return "February";
			break;
		case 3:
			return "March";
			break;
		case 4:
			return "April";
			break;
		case 5:
			return "May";
			break;
		case 6:
			return "June";
			break;
		case 7:
			return "July";
			break;
		case 8:
			return "August";
			break;
		case 9:
			return "September";
			break;
		case 10:
			return "October";
			break;
		case 11:
			return "November";
			break;
		case 12:
			return "December";
			break;
		default:
			return "Enter vaild month 1-12";
			break;	
	}
}

//method used to get the numerical value of the month when the string is provided 	
int Date::getMonthNumber(string monthName) {
	
	if (monthName == "January") {
		return 1;
	} else if (monthName == "February") {
		return 2;
	} else if (monthName == "March") {
		return 3; 
	} else if (monthName == "April") {
		return 4;
	} else if (monthName == "May") {
		return 5;
	} else if (monthName == "June") {
		return 6;
	} else if (monthName == "July") {
		return 7;
	} else if (monthName == "August") {
		return 8;
	} else if (monthName == "September") {
		return 9;
	} else if (monthName == "October") {
		return 10;
	} else if (monthName == "November") {
		return 11;
	} else if (monthName == "December") {
		return 12;
	}
}

