// DayTypeClass2JoshuaTopp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
#include "DayType.h"
using namespace std;
//Assigning the values to each spot in the weekDays array. Default constructor.
DayType::DayType() 
{
	weekDay = "blank";
	weekDays[0] = "Sunday";
	weekDays[1] = "Monday";
	weekDays[2] = "Tuesday";
	weekDays[3] = "Wednesday";
	weekDays[4] = "Thursday";
	weekDays[5] = "Friday";
	weekDays[6] = "Saturday";
}
//Constructor with parameters, also sets the values for the array but can assign an input to d, setting a specific weekDay to the entire program. 
DayType::DayType(string d)
{
	weekDay = d;
	weekDays[0] = "Sunday";
	weekDays[1] = "Monday";
	weekDays[2] = "Tuesday";
	weekDays[3] = "Wednesday";
	weekDays[4] = "Thursday";
	weekDays[5] = "Friday";
	weekDays[6] = "Saturday";
}
//Sets the variable weekDay equal to the string input in the arguments spot in setDay(). 
void DayType::setDay(string d) 
{
	weekDay = d;
}

//A function to return the value of weekDay. Can be useful when checking what weekDay has been assigned to. 
string DayType::getDay() const
{
	return weekDay;
}
//similar to the getDay() function, calling this function will print the value of weekDay. 
void DayType::print() const 
{
	cout << weekDay;
}
//creates a variable called index to run through the array, see which day is equal to the one given, or weekDay,
//  then returns the value of the index + 1 to return the next day.
//  If only this if statement was here and weekDay = weekDays[6], adding one would give weekDays[7] which does not exist in this array. 
//I had to add a special case where if weekDay = weekDays[6], it would return weekDays[0] which is the next day in a calendar week. 
string DayType::nextDay() const
{
	int index = 0;
	for (int i = 0; i < 7; i++) 
	{
		if (weekDay == weekDays[i])
		{
			index = i;
		}
	}
	if (index == 6)
	{
		return weekDays[0];
	}
	else
	{
		return weekDays[index + 1];
	}
}
//This is a similar set up to the nextDay() function, but the other way around. 
// The variabe index is created to run through the array, find the value that equals the given weekDay,
//  and subtract one from its position in the array to get the new value.
//  Similarly,there is a special case where, if weekDay=weekDays[0], subtracting one would give weekDays[-1] which does not exist,
//  so I had to make sure it equalled weekDays[6] which is the previous day in the calendar week. 
string DayType::prevDay() const 
{
	int index = 0;
	for (int i = 0; i < 7; i++) 
	{
		if (weekDay == weekDays[i]) 
		{
			index = i;
		}
	}
	if (index == 0)
	{
		return weekDays[6];
	}
	else
	{
		return weekDays[index - 1];
	}

}

//This function takes the weekDay value, and adds to it the value of nDays which is given as an argument when the fucntion is called. 
// Since this arry of weekDays only has 7 values, I had to take the value of nDays and modulo it with 7, to get the remainder. 
// This would automatically elimante the number of exact weeks that would pass, as only the remainder would change the value of the day.
void DayType::addDay(int nDays)
{
	int num = nDays % 7; 
	int index = 0;
	for (int i = 0; i < 7; i++)
	{
		if (weekDay == weekDays[i])
		{
			index = i;
		}
	}
	index += num;
	if (index >= 7)
	{
		index = index - 7;
	}
	weekDay = weekDays[index];
	cout << "The day "<< nDays << " days after selected days is " << weekDay;
}


//The main function starts with assigning value to the weekDay, by creating object "today" of class "DayType"
//It then prints out the correct information because all the functions are running properly. 
//It starts with the default constructor and it prints out its value plainly.
//  Then it calls the nextDay and prevDay functions to do their part in finding the value of the next and previous day of the default constructor "Sunday".
//Then once that runs successfully, it moves on to the object I assigned, which is "Monday". 
// It then finds the next and previous day of Monday, then it adds 3 days to Monday and outputs it.
//Then it adds 30 and 365 days to Monday and outputs it. 
int main()
{

	
	DayType today("Monday");
	DayType defaultDay("Sunday");
	cout << "From default constructor : " << defaultDay.getDay() << endl;
	cout << "The previous day is " << defaultDay.prevDay() << endl;
	cout << "The day after is " << defaultDay.nextDay() << endl;

	cout << "The selected day is " << today.getDay();
	cout << endl;
	cout << "The day before " << today.getDay()<< " is " << today.prevDay() << endl;
	cout << "The day after " << today.getDay()<< " is " << today.nextDay() << endl; 
	today.addDay(3); cout << endl;
	today.addDay(30); cout << endl;
	today.addDay(365); cout << endl;
	
	

	


	return 0;
}
