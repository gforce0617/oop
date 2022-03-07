#pragma once
#include <string>


class Date
{
public:
	int get_day();
	int get_month();
	int get_year();

	void set_day(int);
	void set_month(int);
	void set_year(int);


	int get_hour();
	int get_minutes();

	void set_hour(int);
	void set_minutes(int);


private:
	int day;
	int month;
	int year;

	int hour;
	int minute;
};


class Records
{
public:
	std::string get_title();
	int get_parametr();

	int get_day();
	int get_month();
	int get_year();
	int get_hour();
	int get_minutes();

	void set_title(std::string);
	void set_parametr(int);
	void set_date(Date);

	void save_recods(int);

	void view();
private:
	Date date;
	std::string title;
	int parametr;
};
