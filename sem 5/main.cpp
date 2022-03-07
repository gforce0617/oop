#include "records.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


std::vector<Records> set_list_records(std::vector<Records>);

void sort_by_date(std::vector<Records>);
void sort_by_title(std::vector<Records>);
void sort_by_parametr(std::vector<Records>);
std::vector<Records> add_records(std::vector<Records>);
std::vector<Records> delete_records(std::vector<Records>);
std::vector<Records> edit_records(std::vector<Records>);

void menu();

int main()
{
	std::vector<Records> records;

	records = set_list_records(records);

	std::string choice;
	int selection;

	
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
				records = add_records(records);
				break;
			}
			case 2:
			{
				records = delete_records(records);
				break;
			}
			case 3:
			{
				records = edit_records(records);
				break;
			}
			case 4:
			{
				sort_by_date(records);
				break;

			}
			case 5:
			{
				sort_by_title(records);
				break;
			}
			case 6:
			{
				sort_by_parametr(records);
				break;
			}
			case 7:
			{
				for (int i = 0; i < records.size(); i++)
					records[i].view();
				break;
			}
		}

		std::cout << "Do you want to continue working? (y/n)" << std::endl;
		std::cin >> choice;


	} while (choice=="y");

	for (int i = 0; i < records.size(); i++)
	{
		records[i].save_recods(i);
	}

	records.clear();
	system("pause");
	return 0;

}

void menu()
{
	std::cout << "1)Add new records" << std::endl
		<< "2)Delete records" << std::endl
		<< "3)Change records" << std::endl
		<< "4)Sort by date" << std::endl
		<< "5)Sort by title" << std::endl
		<< "6)Sort by parameter" << std::endl
		<< "7)View all records" << std::endl;
}

std::vector<Records> set_list_records(std::vector<Records> records)
{
	std::ifstream fin("records.txt", std::ios::in);
	if (!fin.is_open()) // если файл не открыт
		std::cout << "Fail open file\n"; // сообщить об этом
	else
	{
		while (!fin.eof())
		{
			Records buff;
			std::string buff_str;
			Date buff_d;
			int buff_i;

			fin >> buff_i;
			buff_d.set_day(buff_i);
			fin >> buff_i;
			buff_d.set_month(buff_i);
			fin >> buff_i;
			buff_d.set_year(buff_i);
			fin >> buff_i;
			buff_d.set_hour(buff_i);
			fin >> buff_i;
			buff_d.set_minutes(buff_i);

			fin >> buff_str;

			fin >> buff_i;

			buff.set_date(buff_d);
			buff.set_title(buff_str);
			buff.set_parametr(buff_i);

			records.push_back(buff);
		}
	}

	fin.close();

	std::ifstream fdel("records.txt", std::ios::trunc | std::ios::out);
	fdel.close();
	return records;
}

void sort_by_date(std::vector<Records> records)
{
	Date buff_d;
	int buff_i;
	std::cout << "Write date:";
	std::cout << std::endl << "Day: ";
	std::cin >> buff_i;
	buff_d.set_day(buff_i);

	std::cout << "Month: ";
	std::cin >> buff_i;
	buff_d.set_month(buff_i);

	std::cout << "Year: ";
	std::cin >> buff_i;
	buff_d.set_year(buff_i);

	std::cout << "Hour: ";
	std::cin >> buff_i;
	buff_d.set_hour(buff_i);

	std::cout << "Minutes: ";
	std::cin >> buff_i;
	buff_d.set_minutes(buff_i);

	for (int i = 0; i < records.size(); i++)
	{
		if (records[i].get_day() == buff_d.get_day())
			if (records[i].get_month() == buff_d.get_month())
				if (records[i].get_year() == buff_d.get_year())
					if (records[i].get_hour() == buff_d.get_hour())
						if (records[i].get_minutes() == buff_d.get_minutes())
							records[i].view();
	}

}

void sort_by_title(std::vector<Records> records)
{
	std::string str;
	std::cout << "Write title:";
	std::cin >> str;

	for (int i = 0; i < records.size(); i++)
	{
		if (records[i].get_title() == str)
			records[i].view();
	}
}

void sort_by_parametr(std::vector<Records> records)
{
	int buff;
	std::cout << "Write parametr:";
	std::cin >> buff;
	for (int i = 0; i < records.size(); i++)
	{
		if (records[i].get_parametr() == buff)
			records[i].view();
	}
}

std::vector<Records> add_records(std::vector<Records>records)
{
	Records buff;
	std::string buff_str;
	Date buff_d;
	int buff_i;

	std::cout << "Enter day:";
	std::cin >> buff_i;
	buff_d.set_day(buff_i);
	std::cout << "Enter month:";
	std::cin >> buff_i;
	buff_d.set_month(buff_i);
	std::cout << "Enter year:";
	std::cin >> buff_i;
	buff_d.set_year(buff_i);
	std::cout << "Enter hour:";
	std::cin >> buff_i;
	buff_d.set_hour(buff_i);
	std::cout << "Enter minutes:";
	std::cin >> buff_i;
	buff_d.set_minutes(buff_i);

	std::cout << "Enter title:";
	std::cin >> buff_str;

	std::cout << "Enter parameter:";
	std::cin >> buff_i;

	buff.set_date(buff_d);
	buff.set_title(buff_str);
	buff.set_parametr(buff_i);

	records.push_back(buff);

	return records;
}

std::vector<Records> delete_records(std::vector<Records> records)
{
	int choice;
	std::cout << "select the record you want to delete:" << std::endl;

	for (int i = 0; i < records.size(); i++)
	{
		std::cout << i + 1 << ") ";
		records[i].view();
	}

	std::cin >> choice;
	records.erase(records.begin()+choice - 1);
	
	return records;
}

std::vector<Records> edit_records(std::vector<Records> records)
{
	int choice;
	int buff_i;

	std::cout << "select the record you want to change:" << std::endl;

	for (int i = 0; i < records.size(); i++)
	{
		std::cout << i + 1 << ") ";
		records[i].view();
	}

	std::cin >> choice;

	std::cout << "Write new parameter:";
	std::cin >> buff_i;

	records[choice - 1].set_parametr(buff_i);

	return records;
}
