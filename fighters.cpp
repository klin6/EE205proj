/*filename: fighters.cpp*/
#include "fighters.hpp"
#include <iostream>
#include <string>
using namespace std;

Fighter_A::Fighter_A(string n):
	Base(n, 500,40,20,20) {}

void Fighter_A::print_character(){
	int c;
	FILE *file=fopen(".//texts//fighta.txt","r");
	if(file){
		while((c=getc(file))!=EOF){putchar(c);}
		fclose(file);
	}
}
void Fighter_A::print_status(){
	Fighter_A::print_character();
	main_status();
	return;
}

Fighter_D::Fighter_D(string n):
	Base(n, 500,20,40,20) {}

void Fighter_D::print_character(){
	int c;
	FILE *file=fopen(".//texts//fightd.txt","r");
	if(file){
		while((c=getc(file))!=EOF){putchar(c);}
		fclose(file);
	}
}
void Fighter_D::print_status(){
		Fighter_D::print_character();
		main_status();
		return;
}

Fighter_H::Fighter_H(string n):
	Base(n, 500,20,20,40) {}


void Fighter_H::print_character(){
	int c;
	FILE *file=fopen(".//texts//fighth.txt","r");
	if(file){
		while((c=getc(file))!=EOF){putchar(c);}
		fclose(file);
	}
}
void Fighter_H::print_status(){
		Fighter_H::print_character();
		main_status();
		return;
}

Fighter_R::Fighter_R(string n):
	Base(n, 500,30,30,30) {}

void Fighter_R::print_character(){
	int c;
	FILE *file=fopen(".//texts//fightr.txt","r");
	if(file){
		while((c=getc(file))!=EOF){putchar(c);}
		fclose(file);
	}
}
void Fighter_R::print_status(){
	Fighter_R::print_character();
	main_status();
	return;
}
