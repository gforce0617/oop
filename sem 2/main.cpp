#include <vector>
#include "records.h"
#include <iostream>

void menu();
std::vector<Records> add_record(std::vector<Records>);
std::vector<Records> del_record(std::vector<Records>);
void sort(std::vector<Records>);

int main()
{
	std::vector<Records> list;
	int choise;
	bool selection = true;
	while (selection == true)
	{
		menu();
		std::cin >> choise;
		switch (choise)
		{
		default:
			break;
		case 1:
		{
			list = add_record(list);
			break;
		}
		case 2:
		{
			list = del_record(list);
			break;
		}
		case 3:
		{
			sort(list);
			break;
		}
		case 4:
		{
			for (int i = 0; i < list.size(); i++)
				list[i].view_records();
			break;
		}
		case 5:
		{
			selection = false;
			break;
		}
		}


	}
}

void menu()
{
	std::cout << "1 - add record" << std::endl << "2 - delete record" << std::endl << "3 - sort record" << std::endl << "4 - view records" << std::endl << "5 - exit" << std::endl;
}

std::vector<Records> add_record(std::vector<Records> list)
{
	bool choise;
	Records buff;
	int i_buff;
	float f_buff;
	std::string s_buff;
	bool right;

	do {
		right = true;
		std::cout << "Add record" << std::endl;

		std::cout << "enter num" << std::endl;
		std::cin >> f_buff;

		std::cout << "enter string" << std::endl;
		std::cin >> s_buff;

		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].get_num() == f_buff)
				if (strcmp(s_buff.c_str(), list[i].get_str().c_str()) == 0)
					right = false;
		}

		if (right == true)
		{
			i_buff = list.size() + 1;
			buff.set_ser_num(i_buff);
			buff.set_num(f_buff);
			buff.set_str(s_buff);

			list.push_back(buff);
		}
		else
		{
			std::cout << "This record already exists" << std::endl;
		}

		for (int i = 0; i < list.size(); i++)
			list[i].view_records();

		std::cout << "Want to add another record? (1/0)" << std::endl;
		std::cin >> choise;

	} while (choise == true);
	return list;
}

std::vector<Records> del_record(std::vector<Records> list)
{
	bool choise;
	int i_choise;
	float f_choise;
	std::string s_choise;
	int selection;

	do {
		std::cout << "What parameter do you want to delete the record?" << std::endl;
		std::cout << "1 - serial number" << std::endl << "2 - number" << std::endl << "3 - string" << std::endl;
		std::cin >> selection;

		switch (selection)
		{
		default:
			break;
		case 1:
		{
			std::cout << "enter serial number" << std::endl;
			std::cin >> i_choise;

			list.erase(list.begin() + i_choise - 1);

			std::cout << std::endl;
			for (int i = 0; i < list.size(); i++)
				list[i].view_records();
			break;
		}
		case 2:
		{
			std::cout << "enter number" << std::endl;
			std::cin >> f_choise;

			for (int i = 0; i < list.size(); i++)
			{
				if (list[i].get_num() == f_choise)
					list.erase(list.begin() + i);
			}

			std::cout << std::endl;
			for (int i = 0; i < list.size(); i++)
				list[i].view_records();
			break;
		}
		case 3:
		{
			std::cout << "enter string" << std::endl;
			std::cin >> s_choise;

			for (int i = 0; i < list.size(); i++)
			{
				if (strcmp(s_choise.c_str(), list[i].get_str().c_str()) == 0)
					list.erase(list.begin() + i);
			}

			std::cout << std::endl;
			for (int i = 0; i < list.size(); i++)
				list[i].view_records();
			break;
		}
		}

		std::cout << "Want to delete another record? (1/0)" << std::endl;
		std::cin >> choise;
	} while (choise == true);
	return list;
}

void sort(std::vector<Records> list)
{

	int i_choise;
	float f_choise;
	std::string s_choise;
	int selection;

	std::cout << "what parameter do you want to sort?" << std::endl;
	std::cout << "1 - serial number" << std::endl << "2 - number" << std::endl << "3 - string" << std::endl;
	std::cin >> selection;

	switch (selection)
	{
	default:
		break;
	case 1:
	{
		std::cout << "enter serial number" << std::endl;
		std::cin >> i_choise;

		list[i_choise].view_records();
		break;
	}
	case 2:
	{
		std::cout << "enter number" << std::endl;
		std::cin >> f_choise;

		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].get_num() == f_choise)
				list[i].view_records();
		}
		break;
	}
	case 3:
	{
		std::cout << "enter string" << std::endl;
		std::cin >> s_choise;

		for (int i = 0; i < list.size(); i++)
		{
			if (strcmp(s_choise.c_str(), list[i].get_str().c_str()) == 0)
				list[i].view_records();
		}
		break;
	}
	}
}