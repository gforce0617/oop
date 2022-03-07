#pragma once
#include <string>
#include <iostream>

class Microchip
{
public:
	void set_title(std::string);
	void set_category(std::string);

	std::string get_title();
	std::string get_category();

	friend std::ostream& operator<< (std::ostream& s, Microchip& x)
	{
		return s << x.title << "  " << x.category;
	}


private:

	std::string title;
	std::string category;
};

