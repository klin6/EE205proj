/*FileName:Base.cpp*/
 
#include "Base.hpp"
#include <iostream>
#include <string>
using namespace std;

//Constructors
Base::Base() :
	name(""),
	health(0),
	attack(0),
	defense(0),
	heal(0) {}

Base::Base(string n_,int hlt_, int a_,  int d_, int hl_):
	name(n_), health(hlt_), attack(a_), defense(d_), heal(hl_) {}

Base::Base(const Base& other) :
	name(other.name),
	health(other.health),
	attack(other.attack),
	defense(other.defense),
	heal(other.heal){}

int Base::game(){
	for(int i=0;i<15;i++){cout<<"\n";}
	int c;
	FILE *file=fopen(".//texts//pet_sidekick_story.txt","r");
	if(file){
		while((c=getc(file))!=EOF){putchar(c);}
		fclose(file);
	}
	for(int i=0;i<5;i++){cout<<"\n";}
	int rounds=0;
	int check_win=0;
	while(rounds!=2 && check_win!=1){
		int hide=(rand()%3);
		int user_choice;
		cout<<"\nGuess where your pet sidekick is."
			<<"\nIs he behind the rock(1),tree(2),car(3): ";
		cin>>user_choice;
		if(hide==0&&user_choice==1){
			cout<<"\nYou found him.";
			check_win++;
		}
		if(hide==1&&user_choice==2){
			cout<<"\nYou found him.";
			check_win++;
		}
		if(hide==2&&user_choice==3){
			cout<<"\nYou found him.";
			check_win++;
		}
		rounds++;
	}
	if(check_win==1){
		cout << "\n";
		Base::print_pet();
		int win=1;
		return win;
	}else{cout<<"\nYou couldn't find your pet sidekick.";}
}
void Base::main_status(){
	cout << "	Status"
		<< "\n Name: " << name
		<< "\n Health: " << health
		<< "\n Attack: " << attack
		<< "\n Defense: " << defense
		<< "\n Heal: " << heal;
}
void Base::print_character(){cout<<"\n";}
void Base::print_status(){cout<<"\n";}
void Base::print_win(){
	for(int i=0;i<40;i++){cout<<"\n";}
	int c;
	FILE *file=fopen(".//texts//youwin.txt","r");
	if(file){
		while((c=getc(file))!=EOF){putchar(c);}
		fclose(file);
	}
}
void Base::print_lose(){
	for(int i=0;i<40;i++){cout<<"\n";}
	int c;
	FILE *file=fopen(".//texts//youlose.txt","r");
	if(file){
	while((c=getc(file))!=EOF){putchar(c);}
	fclose(file);
	}
}
void Base::print_pet(){
	int c;
	FILE *file=fopen(".//texts//pet.txt","r");
	if(file){
	while((c=getc(file))!=EOF){putchar(c);}
	fclose(file);
	}
}
//getters & setters
string Base::get_name() { return name; }
int Base::get_health() { return health; }
int Base::get_attack() { return attack; }
int Base::get_defense() { return defense; }
int Base::get_heal() { return heal; }

void Base::set_name(string n) {  name = n; }
void Base::set_health(int hlt) { health = hlt; }
void Base::set_attack(int a) { attack = a; }
void Base::set_defense(int d) { defense = d; }
void Base::set_heal(int hl) { heal = hl; }
