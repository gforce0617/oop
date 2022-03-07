#pragma once
#include "string"

class Services
{
public:
	Services(std::string);
	Services()
	{
		title = "";
	}
	~Services();
	
	std::string get_title();
	void set_title(std::string);

	virtual void view_services() = 0;
protected:
	std::string title;
};

class Tier_1 :virtual public Services
{
public:
	Tier_1(bool a, std::string str) : Services(str)
	{
		on = a;
	};
	Tier_1()
	{
		on = true;
	}
	~Tier_1();
	bool get_on();
	void set_on(bool);

	virtual void view_services();
protected:
	bool on;
};

class Tier_2 :virtual public Services
{
public:
	Tier_2(int a, std::string str) :Services(str) 
	{
		quantity = a;
	}
	Tier_2()
	{
		quantity = 0;
	}
	~Tier_2();
	int get_quantity();
	void set_quantity(int);

	virtual void view_services();
protected:
	int quantity;
};

class Tier_3 :virtual public Services
{
public:
	Tier_3(int a,std::string str):Services(str)
	{
		speed = a;
	}
	Tier_3()
	{
		speed = 1;
	}
	~Tier_3();
	int get_speed();
	void set_speed(int);

	virtual void view_services();
protected:
	int speed;
};

class Package_of_services
{
public:
	Package_of_services(std::string str, std::string str_1, bool b, std::string str_2, int i_2, std::string str_3, int i_3)
	{
		tier_1.set_on(b);
		tier_1.set_title(str_1);
		tier_2.set_quantity(i_2);
		tier_2.set_title(str_2);
		tier_3.set_speed(i_3);
		tier_3.set_title(str_3);
	}

private:
	Tier_1 tier_1;
	Tier_2 tier_2;
	Tier_3 tier_3;
	std::string pac_title;
};



