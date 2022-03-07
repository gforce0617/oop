#include"microchip.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

void menu();


bool SortByKey(const std::pair<int, Microchip>& a, const std::pair<int, Microchip>& b);
bool sortByVal(const std::pair<int, Microchip>& a, const std::pair<int, Microchip>& b);

void sort_by_alphabet(std::map<int, Microchip>);
void sort_by_numbers(std::map<int, Microchip>);

std::string convert_category_to_string(int);



int main()
{
	std::map<int, Microchip> microchip;
	std::string choose;
	int selection;
	std::map<int, Microchip>::iterator p;
	int i_buff,i_buff1;
	Microchip mic_buff;
	std::string str_buff;
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
				std::cout << "Write number to new microchip output:";
				std::cin >> i_buff;
				std::cout << "Write title to new microchip output:";
				std::cin >> str_buff;
				mic_buff.set_title(str_buff);
				std::cout << std::endl << "1) power supply" << std::endl
					<< "2) analog input" << std::endl
					<< "3) analog output" << std::endl
					<< "4) digital input" << std::endl
					<< "5) digital output" << std::endl
					<< "6) analog input-output" << std::endl
					<< "7) digital input-output" << std::endl
					<< "8) not connected" << std::endl;
				std::cout << "Enter category to microchip output:";
				std::cin >> i_buff1;
				str_buff = convert_category_to_string(i_buff1);
				mic_buff.set_category(str_buff);

				microchip.insert(std::pair<int, Microchip>(i_buff, mic_buff));
				break;
			}
			case 2:
			{
				sort_by_numbers(microchip);
				break;
			}
			case 3:
			{
				sort_by_alphabet(microchip);
				break;
			}
			case 4:
			{
				for (p = microchip.begin(); p != microchip.end(); p++)
					std::cout << p->first << " " << p->second << std::endl;
				break;
			}
		}

		std::cout << "Do you want to continue working? (y/n)"<<std::endl;
		std::cin >> choose;
	} while (choose == "y");

	return 0;
}

void menu()
{
	std::cout << "1) Add new microchip output" << std::endl
		<< "2) View sort by numbers" << std::endl
		<< "3) View sort by title" << std::endl
		<< "4) View all microchip" << std::endl;
}



void sort_by_numbers(std::map<int, Microchip>microchip)
{
	std::map <int, Microchip> ::iterator p;
	std::vector <std::pair<int, Microchip>> buff;
	int* categ;
	categ = new int[microchip.size()];
	p = microchip.begin();
	for (int i = 0; i < microchip.size(); i++)
	{
		
		if (p->second.get_category() == "power supply")
		{
			categ[i] = 1;
			p++;
			continue;
		}
		if (p->second.get_category() == "analog input")
		{
			categ[i] = 2;
			p++;
			continue;
		}
		if (p->second.get_category() == "analog output")
		{
			categ[i] = 3;
			p++;
			continue;
		}
		if (p->second.get_category() == "digital input")
		{
			categ[i] = 4;
			p++;
			continue;
		}
		if (p->second.get_category() == "digital output")
		{
			categ[i] = 5;
			p++;
			continue;
		}
		if (p->second.get_category() == "analog input-output")
		{
			categ[i] = 6;
			p++;
			continue;
		}
		if (p->second.get_category() == "digital input-output")
		{
			categ[i] = 7;
			p++;
			continue;
		}
		if (p->second.get_category() == "not connected")
		{
			categ[i] = 8;
			p++;
			continue;
		}
	}

	for (int i = 0; i < 8; i++)
	{

		p = microchip.begin();
		for (int j = 0; j < microchip.size(); j++)
		{
			if (categ[j] == i+1)
			{
				buff.push_back(std::make_pair(p->first, p->second));
			}
			p++;
		}
		sort(buff.begin(), buff.end(), SortByKey);
		std::cout << convert_category_to_string(i + 1) << ":" << std::endl;
		for (int k = 0; k < buff.size(); k++)
			std::cout << buff[k].first << "  " << buff[k].second.get_title() << std::endl;
		buff.clear();
	}
}

void sort_by_alphabet(std::map<int, Microchip> microchip)
{
	std::map <int, Microchip> ::iterator p;
	std::vector <std::pair<int, Microchip>> buff;
	int* categ;
	categ = new int[microchip.size()];
	p = microchip.begin();
	for (int i = 0; i < microchip.size(); i++)
	{
		if (p->second.get_category() == "power supply")
		{
			categ[i] = 1;
			p++;
			continue;
		}
		if (p->second.get_category() == "analog input")
		{
			categ[i] = 2;
			p++;
			continue;
		}
		if (p->second.get_category() == "analog output")
		{
			categ[i] = 3;
			p++;
			continue;
		}
		if (p->second.get_category() == "digital input")
		{
			categ[i] = 4;
			p++;
			continue;
		}
		if (p->second.get_category() == "digital output")
		{
			categ[i] = 5;
			p++;
			continue;
		}
		if (p->second.get_category() == "analog input-output")
		{
			categ[i] = 6;
			p++;
			continue;
		}
		if (p->second.get_category() == "digital input-output")
		{
			categ[i] = 7;
			p++;
			continue;
		}
		if (p->second.get_category() == "not connected")
		{
			categ[i] = 8;
			p++;
			continue;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		p = microchip.begin();
		for (int j = 0; j < microchip.size(); j++)
		{
			if (categ[j] == i+1)
			{
				buff.push_back(std::make_pair(p->first,p->second));
			}
			p++;
		}
		sort(buff.begin(), buff.end(), sortByVal);
		std::cout << convert_category_to_string(i + 1) << ":" << std::endl;
		for (int k = 0; k < buff.size(); k++)
			std::cout << buff[k].first << "  " << buff[k].second.get_title() << std::endl;
		buff.clear();
	}
}


std::string convert_category_to_string(int a)
{
	std::string str;
	switch (a)
	{
		default:
			break;
		case 1:
		{
			str = "power supply";
			break;
		}
		case 2:
		{
			str = "analog input";
			break;
		}
		case 3:
		{
			str = "analog output";
			break;
		}
		case 4:
		{
			str = "digital input";
			break;
		}
		case 5:
		{
			str = "digital output";
			break;
		}
		case 6:
		{
			str = "analog input-output";
			break;
		}
		case 7:
		{
			str = "digital input-output";
			break;
		}
		case 8:
		{
			str = "not connected";
			break;
		}
	}
	return str;
}

bool sortByVal(const std::pair<int, Microchip>& a,const std::pair<int, Microchip>& b)
{
	std::string str1, str2;
	Microchip buff1, buff2;

	buff1 = a.second;
	buff2 = b.second;

	if (strcmp(buff1.get_title().c_str(), buff2.get_title().c_str()) < 0)
		return true;
	else
		return false;
}

bool SortByKey(const std::pair<int, Microchip>& a, const std::pair<int, Microchip>& b)
{
	return (a.first < b.first);
}