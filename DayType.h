#pragma once
#include <iostream>
#include <string>

using namespace std;
//Class Daytype, used to set a day of the week and find any related days, wether it be the next day, previous day, or what day it is 50 days later. 
class DayType
{
private: 
	string weekDay;
public:
	string weekDays[7];
	//Default constructor, sets the value of weekDay to Sunday. 
	DayType();

	//Postcondition- Takes the input of the day, string d, and sets it as the weekday for the entire prgram. 
	DayType(string d);

	//Postcondition- Sets the string d equal to weekDay. 
	void setDay(string d);

	//Returns the value of weekDay which should be the string d given, which is the given day of the week. Makes it easy to cout the selected day of the week. 
	string getDay() const;

	//similar to getDay(), calling this function simply prints the value of weekDay so long as it has been set in DayType and setDay. 
	void print() const;

	//Postcondition- Takes the given weekDay and returns the value of the next day in the calendar week.
	string nextDay() const;

	//Postcondition- takes the given weekDay and returns the value of the previous day. 
	string prevDay() const;

	//Postcondition- The function can take an input of nDays (number of days to be added) and correctly add them to the current weekDay set in the previous functions.
	// This function can add any amount of days. 
	void addDay(int nDays);




};
