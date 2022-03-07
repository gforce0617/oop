#pragma once
#include <iostream>

class Services
{
public:
	Services(std::string);


	void add(std::string);
	void add(float);
	void add(int);

	std::string get_tier_1();
	float get_tier_2();
	int get_tier_3();
	std::string get_title();

	void set_tier_1(std::string);
	void set_tier_2(float);
	void set_tier_3(int);
	void set_title(std::string);

	void view();
private:
	std::string title;
	std::string tier_1;
	float tier_2;
	int tier_3;
};

class Package_of_services
{
public:
	Package_of_services(std::string);

	Services get_pac_ser(int);
	std::string get_title();
	int get_pac_ser_count();

	void set_title(std::string);
	void set_pac_ser_count(int);
	void set_pac_ser(Services*);

	void view();
	void add_services(Services* (&ser)[20]);

private:
	Services* pac_ser[10];
	int pac_ser_count;
	std::string title;
};


class Subscriber
{
public:
	Subscriber(std::string);
	void add_subscriber(Package_of_services* (&pac)[15]);

	void view();
private:
	std::string name;
	Package_of_services* package;
};