/*filename:fighters.hpp*/
#ifndef FIGHTERS_HPP
#define FIGHTERS_HPP
#include "Base.hpp"
#include <iostream>
#include <string>
using namespace std;

class Fighter_A: public Base{
private:
public:
	Fighter_A(string n);
	~Fighter_A(){}

	virtual void print_character();
	virtual void print_status();
};
class Fighter_D: public Base{
private:
public:
	Fighter_D(string n);
	~Fighter_D() {}

	virtual void print_character();
	virtual void print_status();
};
class Fighter_H: public Base{
private:
public:
	Fighter_H(string n);
	~Fighter_H() {}

	virtual void print_character();
	virtual void print_status();
};
class Fighter_R: public Base{
private:
public:
	Fighter_R(string n);
	~Fighter_R() {}

	virtual void print_character();
	virtual void print_status();
};
#endif
