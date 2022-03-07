#include "microchip.h"
#include <iostream>

void Microchip::set_title(std::string str)
{
	title = str;
}
void Microchip::set_category(std::string str)
{
	category = str;
}

std::string Microchip::get_title()
{
	return title;
}
std::string Microchip::get_category()
{
	return category;
}
