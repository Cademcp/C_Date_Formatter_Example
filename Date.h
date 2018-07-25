/*
	Author: Cade McPartlin
	File: Date.h 
	Description: Header file for the Date class. Defines the Date class, its methods, and its data members 

*/
#include <string>
#include <array>

#ifndef DATE_H_
#define DATE_H_

class Date {
public:
	static const unsigned int monthsPerYear{12};
	//constructor for numerical date
	explicit Date( int = 1,  int = 1,  int = 1900);
	//constructor for string date
	Date (std::string mstr, int dd, int yy);
	void print();
	void printFullDate();
	std::string getMonthName(int monthNum);
	int getMonthNumber(std::string monthName);
	static bool leapYear(int);
	
	unsigned int getMonth() {
		return month;
	}
		
	unsigned int getDay() {
		return day;
	}
	
	unsigned int getYear() {
		return year;
	} 
	
	void setMonth(int newMonth) {
		month = newMonth;
	}
	
	void setDay(int newDay) {
		day = newDay;
	}
	
	void setYear(int newYear) {
		year = newYear;
	}
	
	std::string getMonthString() {
		return monthString;
	}
	
private:
	int month;
	int day;
	int year;
	std::string monthString;
	
	static const std::array<unsigned int, 13> days;
	int checkDay(int) const;
	int checkLeapYear(int month, int day, int year) const;
};

#endif /* DATE_H_ */
