#include "Services.h"
#include <iostream>

void menu();

int main()
{
	Services* ser[20];
	Package_of_services* pac[15];
	Subscriber* sub[15];
	
	int ser_count = 0, pac_count=0,sub_count=0;
	bool choose=true;
	int selection;
	std::string str_buff;
	float f_buff;
	int i_buff;
	int tier;

	do 
	{
		menu();
		std::cin >> selection;
		switch (selection)
		{
			default:
				break;
			case 1:
			{
				std::cout << "what type do you want to create a service?" << std::endl << "1) Tier 1" << std::endl << "2) Tier 2" << std::endl << "3) Tier 3" << std::endl;
				std::cin >> tier;
				std::cout << "Write title:" << std::endl;
				std::cin >> str_buff;
			
			
				ser[ser_count] = new Services(str_buff);
				switch (tier)
				{
					default:
						break;
					case 1:
					{
						std::cout << "Write on/off" << std::endl;
						std::cin >> str_buff;
						ser[ser_count]->add(str_buff);
						break;
					}
					case 2:
					{
						std::cout << "Write speed" << std::endl;
						std::cin >> f_buff;
						ser[ser_count]->add(f_buff);
						break;
					}
					case 3:
					{
						std::cout << "choose one of the options" << std::endl
							<< "1) constant ip" << std::endl << "2) subscribe to kinopoisk" << std::endl
							<< "3) free wifi router" << std::endl;
						std::cin >> i_buff;
						ser[ser_count]->add(i_buff);
						break;
					}
				}
				ser_count++;
				break;
			
			
			}
			case 2:
			{
				for (int i = 0; i < ser_count; i++)
				{
					ser[i]->view();
				}
				break;
			}
			case 3:
			{
				std::cout << "Write title:" << std::endl;
				std::cin >> str_buff;
				pac[pac_count] = new Package_of_services(str_buff);

				for (int i = 0; i < ser_count; i++)
				{
					std::cout << i << ") ";
					ser[i]->view();
				}
				pac[pac_count]->add_services(ser);
				pac_count++;
				break;
			}
			case 4:
			{
				for (int i = 0; i < pac_count; i++)
				{
					pac[i]->view();
				}
				break;			
			}
			case 5:
			{
				std::cout << "Write name" << std::endl;
				std::cin >> str_buff;

				sub[sub_count] = new Subscriber(str_buff);

				for (int i = 0; i < pac_count; i++)
				{
					std::cout << i << ") ";
					pac[i]->view();
				}

				sub[sub_count]->add_subscriber(pac);
				sub_count++;
				break;
			}
			case 6:
			{
				for (int i=0; i < sub_count; i++)
				{
					sub[i]->view();
				}
				break;
			}
		}
		std::cout << "Do you want to continue working? (1/0)" << std::endl;
		std::cin >> choose;

	} while (choose == true);
}

void menu()
{
	std::cout << "1)add services" << std::endl
		<< "2)view all services" << std::endl
		<< "3)add package of services" << std::endl
		<< "4)view all package" << std::endl
		<< "5)add subscriber" << std::endl
		<< "6)view all subscriber" << std::endl;
}