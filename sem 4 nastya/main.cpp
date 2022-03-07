#include <iostream>
#include "logic_elem.h"

int main()
{
	logic_elem* p[3];
	p[0] = new AND;
	p[1] = new NOT;
	p[2] = new OR;

	p[0]->set(1, true);
	p[0]->set(2, false);
	p[1]->set(2, true);

	p[0]->result();
	p[1]->result();


	connect(p[2], 1, p[0]);
	connect(p[2], 2, p[1]);
	

	

	calculate(p[2]);
	return 0;
}