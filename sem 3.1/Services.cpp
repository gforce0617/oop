#include "Services.h"
#include<iostream>

Services::Services(std::string str)
{
	Services::title = str;
	Services::tier_1 = "";
	Services::tier_2 = -1;
	Services::tier_3 = -1;
}

void Services::add(std::string str)
{
	if (strcmp((Services::tier_1.c_str()), "") == 0)
		if (Services::tier_2 == -1)
			if (Services::tier_3 == -1)
				if (strcmp(str.c_str(), "on") == 0 || strcmp(str.c_str(),"off")==0)
				{
					Services::tier_1 = str;
				}
				else
					std::cout << "ERROR";
}

void Services::add(float speed)
{
	if (strcmp((Services::tier_1.c_str()), "") == 0)
		if (Services::tier_2 == -1)
			if (Services::tier_3 == -1)
				if (speed > 0)
				{
					Services::tier_2 = speed;
				}
				else
					std::cout << "ERROR";
}

void Services::add(int selection)
{
	if (strcmp((Services::tier_1.c_str()), "") == 0)
		if (Services::tier_2 == -1)
			if (Services::tier_3 == -1)
				if (selection > 0 && selection<=3)
				{
					Services::tier_3 = selection;
				}
				else
					std::cout << "ERROR";
}

std::string Services::get_tier_1()
{
	return Services::tier_1;
}

float Services::get_tier_2()
{
	return Services::tier_2;
}

int Services::get_tier_3()
{
	return Services::tier_3;
}

std::string Services::get_title()
{
	return Services::title;
}

void Services::set_tier_1(std::string str)
{
	Services::tier_1 = str;
}

void Services::set_tier_2(float a)
{
	Services::tier_2 = a;
}

void Services::set_tier_3(int a)
{
	Services::tier_3 = a;
}

void Services::set_title(std::string str)
{
	Services::title = str;
}

void Services::view()
{
	std::string str;
	if (strcmp(Services::tier_1.c_str(), "on") == 0 || strcmp(Services::tier_1.c_str(), "off") == 0)
		std::cout << "Tier 1  " << Services::title << "  " << Services::tier_1 << std::endl;
	if (Services::tier_2 > 0)
		std::cout << "Tier 2  " << Services::title << "  " << Services::tier_2 << std::endl;
	if (Services::tier_3 > 0 && Services::tier_3 <= 3)
	{
		switch (Services::tier_3)
		{
			default:
				break;
			case 1:
			{
				str = "constant ip";
				break;
			}
			case 2:
			{
				str = "subscribe to kinopoisk";
				break;
			}
			case 3:
			{
				str = "free wifi router";
				break;
			}
		}
		std::cout << "Tier 3  " << Services::title << "  " << str << std::endl;
	}
}


void Package_of_services::view()
{
	std::string str;

	std::cout << Package_of_services::title << ":" << std::endl;
	for (int i = 0; i < Package_of_services::pac_ser_count; i++)
	{
		
		if (strcmp(Package_of_services::pac_ser[i]->get_tier_1().c_str(), "on") == 0 || strcmp(Package_of_services::pac_ser[i]->get_tier_1().c_str(), "off") == 0)
			std::cout << "Tier 1 " << Package_of_services::pac_ser[i]->get_title() << "  " << Package_of_services::pac_ser[i]->get_tier_1() << std::endl;
		if (Package_of_services::pac_ser[i]->get_tier_2() > 0)
			std::cout << "Tier 2 " << Package_of_services::pac_ser[i]->get_title() << "  " << Package_of_services::pac_ser[i]->get_tier_2() << std::endl;
		if (Package_of_services::pac_ser[i]->get_tier_3() > 0 && Package_of_services::pac_ser[i]->get_tier_3() <= 3)
		{
			switch (Package_of_services::pac_ser[i]->get_tier_3())
			{
				default:
					break;
				case 1:
				{
					str = "constant ip";
					break;
				}
				case 2:
				{
					str = "subscribe to kinopoisk";
					break;
				}
				case 3:
				{
					str = "free wifi router";
					break;
				}
			}
			std::cout << "Tier 3 " << Package_of_services::pac_ser[i]->get_title() << "  " << str << std::endl;
		}
	}
	std::cout << std::endl;
}

void Package_of_services::add_services(Services* (&ser)[20])
{
	int selection;

	bool choose = true;

	std::cout << "Choose services,but <=10" << std::endl;
	do
	{
		pac_ser[pac_ser_count] = new Services("");
		std::cin >> selection;
		Package_of_services::pac_ser[pac_ser_count]->set_tier_1(ser[selection]->get_tier_1());
		Package_of_services::pac_ser[pac_ser_count]->set_tier_2(ser[selection]->get_tier_2());
		Package_of_services::pac_ser[pac_ser_count]->set_tier_3(ser[selection]->get_tier_3());
		Package_of_services::pac_ser[pac_ser_count]->set_title(ser[selection]->get_title());

		pac_ser_count++;

		std::cout << "Do you want to choose more services?(1/0)" << std::endl;
		std::cin >> choose;
	}while(choose == true);
}

Package_of_services::Package_of_services(std::string str)
{
	Package_of_services::title = str;
	pac_ser_count = 0;
}



std::string Package_of_services::get_title()
{
	return Package_of_services::title;
}




Subscriber::Subscriber(std::string str)
{
	Subscriber::name = str;
}

void Subscriber::add_subscriber(Package_of_services* (&pac)[15])
{
	int selection;


	std::cout << "Choose pack" << std::endl;
	std::cin >> selection;
	package = new Package_of_services(pac[selection]->get_title());
	package = pac[selection];


}

void Subscriber::view()
{
	std::cout << Subscriber::name << ":" << std::endl;
	Subscriber::package->view();
}