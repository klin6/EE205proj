/*FileName:Robot.hpp*/
#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Base.hpp"
#include <iostream>
#include <string>
using namespace std;

class Robot : public Base{

private:

public:
	Robot(string n);
	~Robot(){}

	virtual void print_character();
	virtual void print_status();

};
#endif
