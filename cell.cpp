#include <iostream>
#include <string>
#include "cell.h"
#include <cstring>

Cell::Cell(const std::string& v, Color c) : m_value{v}, m_color{c} {}

void Cell::setValue(const std::string& s)
{
	m_value = s;
}

std::string Cell::getValue() const
{
	return m_value;
}

int Cell::toInt()
{
	return stoi(m_value);
}

double Cell::toDouble()
{
	return stod(m_value);
}

Date Cell::toDate(){
	int year, month, day;
    	sscanf(m_value.c_str(), "%d/%d/%d", &year, &month, &day);
    	return Date(year, month, day);
}

void Cell::reset(){
	m_value = "";
}

void Cell::setColor(Color color)
{
	m_color = color;
}

Color Cell::getColor() const
{
	return m_color;
}
