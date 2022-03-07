#include "logic_elem.h"
#include <iostream>


bool logic_elem::get_pin1()
{
	return logic_elem::pin1;
}

bool logic_elem::get_pin2()
{
	return logic_elem::pin2;
}

bool logic_elem::get_pin3()
{
	return logic_elem::pin3;
}

void logic_elem::set_pin(int pin,bool value)
{
	if (pin == 1)
		logic_elem::pin1 = value;
	else
		if (pin == 2)
			logic_elem::pin2 = value;
		else 
			std::cout<< "ERROR pin not available" << std::endl;

}

void logic_elem::set_pin3(bool value)
{
	logic_elem::pin3 = value;
}


void logic_elem::set(int pin, bool value)
{
	if (pin == 1)
	{
		logic_elem::pin1 = value;
	}
	else
		if (pin == 2)
		{
			logic_elem::pin2 = value;
		}
		else
			std::cout << "ERROR pin not available" << std::endl;
}


void AND::result()
{
	AND::set_pin3(AND::get_pin1() * AND::get_pin2());
}

void OR::result()
{
	OR::set_pin3(OR::get_pin1() + OR::get_pin2());
}

void NOT::result()
{
	NOT::set_pin3(!NOT::get_pin2());
}

void calculate(logic_elem* elem)
{
	elem->result();
	std::cout << elem->get_pin3() << std::endl;
}

void connect(logic_elem* elem_1, int pin_1, logic_elem* elem_2)
{
	elem_1->set_pin(pin_1, elem_2->get_pin3());
}