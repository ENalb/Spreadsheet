#include <iostream>
#include "date.h"

Date::Date(int y, int m, int d) : year{y}, month{m}, day{d} {}

void Date::setYear(int y)
{
	year = y;
}

int Date::getYear() const
{
	return year;
}

void Date::setMonth(int m)
{
	month = m;
}

int Date::getMonth() const
{
	return month;
}

void Date::setDay(int d)
{
	day = d;
}

int Date::getDay() const
{
	return day;
}