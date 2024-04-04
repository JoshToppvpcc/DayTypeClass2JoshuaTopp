// DayTypeClass2JoshuaTopp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DayType.h"
using namespace std;

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
void DayType::setDay(string d) 
{
	weekDay = d;
}

string DayType::getDay() const
{
	return weekDay;
}
void DayType::print() const 
{
	cout << weekDay;
}

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
}



int main()
{
	
	DayType today("Thursday");
	cout << "The selected day is " << today.getDay();
	cout << endl;
	cout << "The day before " << today.getDay()<< " is " << today.prevDay() << endl;
	cout << "The day after " << today.getDay()<< " is " << today.nextDay() << endl;
	


	return 0;
}
