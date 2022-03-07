#include "services.h"
#include <string>
#include <iostream>

Services::Services(std::string str)
{
	Services::title = str;
}

std::string Services::get_title()
{
	return Services::title;
}

void Services::set_title(std::string str)
{
	Services::title = str;
}

bool Tier_1::get_on()
{
	return Tier_1::on;
}

void Tier_1::set_on(bool a)
{
	Tier_1::on = a;
}

void Tier_1::view_services()
{
	std::cout << "Tier 1" << "   " << Tier_1::title << "   " << Tier_1::on << std::endl;
}

int Tier_2::get_quantity()
{
	return Tier_2::quantity;
}

void Tier_2::set_quantity(int a)
{
	Tier_2::quantity = a;
}
void Tier_2::view_services()
{
	std::cout << "Tier 2" << "   " << Tier_2::title << "   " << Tier_2::quantity << std::endl;
}

int Tier_3::get_speed()
{
	return Tier_3::speed;
}

void Tier_3::set_speed(int a)
{
	Tier_3::speed = a;
}

void Tier_3::view_services()
{
	std::string str;
	switch (Tier_3::speed)
	{
		default:
			break;
		case 1:
		{
			str = "10 kbyte/sec";
			break;
		}
		case 2:
		{
			str = "30 kbyte/sec";
			break;
		}
		case 3:
		{
			str = "100 kbyte/sec";
			break;
		}
		case 4:
		{
			str = "20 mbyte/sec";
			break;
		}
		case 5:
		{
			str = "50 mbyte/sec";
			break;
		}
		case 6:
		{
			str = "100 mbyte/sec";
			break;
		}
		case 7:
		{
			str = "200 mbyte/sec";
			break;
		}
		case 8:
		{
			str = "500 mbyte/sec";
			break;
		}
	}
	std::cout << "Tier 3" << "   " << Tier_3::title << "   " << str << std::endl;
}

