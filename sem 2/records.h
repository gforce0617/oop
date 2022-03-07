#pragma once
#include <string>
#include <vector>

class Records
{
public:
	Records();
	~Records();

	int get_ser_num();
	float get_num();
	std::string get_str();

	void set_ser_num(int);
	void set_num(float);
	void set_str(std::string);

	void view_records();
	
private:



	int serial_number;
	float number;
	std::string str;

};

