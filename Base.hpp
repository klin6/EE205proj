/*FileName:Base.hpp*/
#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
using namespace std;

class Base {

private:
	string name;
	int health;
	int attack;
	int defense;
	int heal;

public:
	//default constructor
	Base();
	Base(string n_,int hlt_, int a_, int d_, int hl_);
	Base(const Base& other);

	int game();
	void main_status();
	virtual void print_character();
	virtual void print_status();
	void print_win();
	void print_lose();
	void print_pet();

	//getters & setters
	string get_name();
	int get_health();
	int get_attack();
	int get_defense();
	int get_heal();

	void set_name(string n);
	void set_health(int hlt);
	void set_attack(int a);
	void set_defense(int d);
	void set_heal(int hl);


};

#endif
