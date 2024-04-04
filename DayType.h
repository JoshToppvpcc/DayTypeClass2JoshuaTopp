#pragma once
#include <iostream>
#include <string>

using namespace std;
class DayType
{
private: 
	string weekDay;
public:
	string weekDays[7];

	DayType();

	DayType(string d);

	void setDay(string d);

	string getDay() const;

	void print() const;

	string nextDay() const;

	string prevDay() const;

	void addDay(int nDays);




};
