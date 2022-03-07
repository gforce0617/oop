#include <string>
#include <iostream>
#include "records.h"
#include <vector>

Records::Records()
{

}

Records::~Records()
{

}

int Records::get_ser_num()
{
	return Records::serial_number;
}

float Records::get_num()
{
	return Records::number;
}

std::string Records::get_str()
{
	return Records::str;
}

void Records::set_ser_num(int ser_num)
{
	Records::serial_number = ser_num;
}

void Records::set_num(float num)
{
	Records::number = num;
}

void Records::set_str(std::string string)
{
	Records::str = string;
}

void Records::view_records()
{
	std::cout << Records::serial_number << "  " << Records::number << "  " << Records::str << std::endl;
}

