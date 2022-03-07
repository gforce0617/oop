#pragma once
class logic_elem
{
private:
	bool pin1;
	bool pin2;
	bool pin3;
public:
	bool get_pin1();
	bool get_pin2();
	bool get_pin3();

	void set_pin(int, bool);
	void set_pin3(bool);

	void set(int,bool);
	virtual void result()=0;


};

class AND : public logic_elem
{
public:
	void result();
};

class OR : public logic_elem
{
public:
	void result();
};

class NOT : public logic_elem
{
public:
	void result();
};


void calculate(logic_elem*);
void connect(logic_elem*,int,logic_elem*);