/*FileName:Robot.cpp*/
#include "Robot.hpp"
#include <iostream>
#include <string>
using namespace std;

Robot::Robot(string n):
	Base(n, 1000,50,10,10) {}

void Robot::print_character(){
	cout << "\n";
	int c;
	FILE* file=fopen(".//texts//robot.txt","r");
	if(file){
		while((c=getc(file))!=EOF){putchar(c);}
		fclose(file);
	}
}
void Robot::print_status(){
	Robot::print_character();
	main_status();
	return;
}
