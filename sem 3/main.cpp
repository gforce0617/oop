#include "services.h"
#include <iostream>
#include <vector>

void menu();

int main()
{
	Services* ser[100];
	/*Package_of_services* pac_ser[100];*/
	std::vector <Package_of_services> pac_ser;
	int i;
	int ser_count=0, pac_ser_count=0;
	bool choise = true;
	int selection, ser_selection;
	std::string title;
	int i_buff;
	bool b_buff;
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
				std::cout << "Choose tier services" << std::endl <<
					"1) tier 1" << std::endl << "2) tier 2" << std::endl << "3) tier 3" << std::endl;
				std::cin >> ser_selection;
				switch (ser_selection)
				{
					default:
						break;
					case 1:
					{
						std::cout << "Write title" << std::endl;
						std::cin >> title;
						std::cout << "Write on/off (1/0)" << std::endl;
						std::cin >> b_buff;
						ser[ser_count] = new Tier_1(b_buff, title);
					}
					case 2:
					{
						std::cout << "Write title" << std::endl;
						std::cin >> title;
						std::cout << "Write quantity ethernet" << std::endl;
						std::cin >> i_buff;
						ser[ser_count] = new Tier_2(i_buff, title);
					}
					case 3:
					{
						std::cout << "Write title" << std::endl;
						std::cin >> title;
						std::cout << "Choose quantity ethernet" << std::endl <<
							"1) 10 kbyte/sec" << std::endl << "2) 30 kbyte/sec" << std::endl << "3) 100 kbyte/sec" << std::endl <<
							"4) 20 mbyte/sec" << std::endl << "5) 50 mbyte/sec" << std::endl << "6) 100 mbyte/sec" << std::endl <<
							"7) 200 mbyte/sec" << std::endl << "8) 500 mbyte/sec" << std::endl;
						std::cin >> i_buff;
						ser[ser_count] = new Tier_3(i_buff, title);
					}
				}
				ser_count++;
				
			}
			case 2:
			{
				for (i = 0; i <= ser_count; i++)
				{
					std::cout << i << ") ";
					ser[i]->view_services();
				}

				std::cout << "Choose one tier 1, one tier 2 and one tier 3" << std::endl;
				int choise_1, choise_2, choise_3;
				std::cout << "Number tier 1:" << std::endl;
				std::cin >> choise_1;
				std::cout << "Number tier 2:" << std::endl;
				std::cin >> choise_2;
				std::cout << "Number tier 3:" << std::endl;
				std::cin >> choise_3;
				
				std::cout << "Wtite title package" << std::endl;
				std::cin >> title;

				Tier_1 t_1_buff(ser[choise_1]->Tier_1::get_on(), ser[choise_1]->get_title()) ;
				Tier_2 t_2_buff;
				Tier_3 t_3_buff;



				pac_ser[pac_ser_count] = new  Package_of_services(title);

				pac_ser[pac_ser_count].set_t_1(ser[choise_1]);

				Package_of_services p_buff(title,ser[choise_1]->get_title(),ser[choise_1]->Tier_1::get_on(),;


			}
		}

	} while(choise==true);
}

void menu()
{
	std::cout<<"1) Add Servisec"<<std::endl
		<<"2) Add package of services"<<std::endl

}