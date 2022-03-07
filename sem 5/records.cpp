#include "records.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>

std::string Records::get_title()
{
	return Records::title;
}
int Records::get_parametr()
{
	return Records::parametr;
}

int Records::get_day()
{
	return Records::date.get_day();
}

int Records::get_month()
{
	return Records::date.get_month();
}

int Records::get_year()
{
	return Records::date.get_year();
}

int Records::get_hour()
{
	return Records::date.get_hour();
}

int Records::get_minutes()
{
	return Records::date.get_minutes();
}

void Records::set_title(std::string str)
{
	Records::title = str;
}
void Records::set_parametr(int a)
{
	Records::parametr = a;
}

void Records::set_date(Date dte)
{
	Records::date = dte;
}


void Records::view()
{
	std::cout << Records::date.get_day() << " " << Records::date.get_month() << " " << Records::date.get_year() << "   "
		<< Records::date.get_hour() << " " << Records::date.get_minutes() << "   "
		<< Records::title << "   "
		<< Records::parametr << std::endl;
}

void Records::save_recods(int i)
{
	std::ofstream fout("records.txt", std::ios::app);

	if (i == 0) 
	{}
	else
		fout << std::endl;
	fout << Records::date.get_day() << " " << Records::date.get_month() << " " << Records::date.get_year() << " "
		<< Records::date.get_hour() << " " << Records::date.get_minutes() << " "
		<< Records::get_title() << " "
		<< Records::get_parametr();

	fout.close();
}


int Date::get_day()
{
	return Date::day;
}

int Date::get_month()
{
	return Date::month;
}

int Date::get_year()
{
	return Date::year;
}

int Date::get_hour()
{
	return Date::hour;
}

int Date::get_minutes()
{
	return Date::minute;
}

void Date::set_day(int a)
{
	Date::day = a;
}

void Date::set_month(int a)
{
	Date::month = a;
}
void Date::set_year(int a)
{
	Date::year = a;
}

void Date::set_hour(int a)
{
	Date::hour = a;
}

void Date::set_minutes(int a)
{
	Date::minute = a;
}