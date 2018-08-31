/*filename: grace's battle.cpp (edited)*/

#include "Base.hpp"
#include "Battle.hpp"
#include "fighters.hpp"
#include "Robot.hpp"

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

void battle(int fighterType){
    //creating objects for each class
    Robot robot("Enemy");

    string playername;
    cout << "\nName of your fighter: ";
    cin >> playername;

    Base* you;

    //choosing a fighter type
    if (fighterType == 1)
    	you = new Fighter_A(playername);
    else if(fighterType == 2)
        you = new Fighter_D(playername);
    else if(fighterType == 3)
        you = new Fighter_H(playername);
    else
        you = new Fighter_R(playername);
    for(int i=0;i<5;i++){cout<<"\n";}
    char m;
    int less;
    int quit=1;
    int d_count = 0;
    int x = 0;
    int a_count = 0;
    int mini_game=1;
    //check to make sure the fighter and the robot both have get_health
    //if so, begin the game
    while (robot.get_health() > 0 && you->get_health() > 0 && quit!=0){
      cout<<"\n";
      //continuously update the status of each character
      you->print_status();
      robot.print_status();
        //the amount of health the fighter will have after the robot attacks
        less = you->get_health() - (robot.get_attack() - you->get_defense());
        //ask for player input to play the game
        cout << "\nMake your move" << endl;
        cout << "A = Attack, H = Heal, D = Lower Robot Defenses, Q = Quit Game" << endl;
        cout << "G = Mini game for pet sidekick" << endl;
        cin >> m;
        //in case of an invalid move
	       while(m != 'A' && m != 'a' && m != 'D' && m != 'd' && m != 'H' && m != 'h' && m != 'Q' && m != 'q' && m != 'G' && m != 'g') {
		         cout << "Invalid Move: A = attack, H = heal, D = Lower Robot defense, Q = Quit Game" << endl;
		         cin >> m;
	       }
         //if they choose to attack
        if (m == 'A' || m =='a'){
            //set the robot's health equal to its' current health minus
            //the difference of the fighter's attack and the robot's defense
            robot.set_health(robot.get_health() - (you->get_attack() - robot.get_defense()));
	           a_count++;
             d_count++;
        }
        // heal move
        else if (m == 'H' || m == 'h'){
            //increase the health of the fighter by the amount of healing power
            you->set_health(you->get_health() + you->get_heal() );
            //make sure the health of the fighter does not go above its max
            //if it does, set it to the max health
            if(you->get_health() >= 500){
                you->set_health(500);
            }
            d_count++;
        }
        //decrease the robot's defenses
	      else if (m == 'D'|| m == 'd'){
            //this can only be done after the fighter has attacked 5 times
          if(a_count>=5){
                //setting the robot's defenses down by 5
                if(robot.get_defense() >= 0){
                        robot.set_defense(robot.get_defense()-5);
                }
                else{
                        robot.set_defense(0);
                }
               a_count = 0;
               //save the current "count" of the moves, to set the defenses back
               x = d_count;
             }
          else{cout<<"\n\nYou can't use this yet"<<endl;}
        }

        //mini guessing game
        else if(m=='G'||m=='g'){
          int play;
          if(mini_game==1){
            play=you->game();
            if(play==1){
              robot.set_health(robot.get_health()-500);
  	           a_count++;
            }
            mini_game=0;
          }
          //make sure the user can only play the game once
          else{cout<<"You already played the game"<<endl;}
        }
        else if (m == 'Q' || m == 'q'){
          quit=0;
          cout << "\n Maybe next time !\n" << std::endl;
        }
        //if it has been five turns since the defenses have been lowered
        if (d_count == (x+5)){
          //then set the defense of the robot back to its original value
          robot.set_defense(robot.get_defense() +5);
          if (robot.get_defense() >= 10){
            robot.set_defense(10);
          }
          d_count = 0;
          x = 0;
        }
        //robot random attack
        int rand_robot=(rand()%3);
        switch(rand_robot){
          //if 0, make it do nothing (gives the fighter a chance)
          case 0:
            break;
          //if 1, make the robot attack the fighter
          case 1:
            you->set_health(less);  //attack
            break;
          //if 2, heal self
          case 2:
            robot.set_health(robot.get_health()+robot.get_heal());
            if(robot.get_health()>=1000)
              robot.set_health(1000);
            break;
        }
        for(int i=0;i<5;i++){cout<<"\n";}
//        cout<<"\nrandnum: "<<rand_robot<<endl;  //debug robot rand attack
        if (robot.get_health() <= 0){
          you->print_win();
          cout<< "\n";
          quit=0;
        }
        if (you->get_health() <= 0){
          you->print_lose();
          cout<< "\n";
          quit=0;
        }
    }//end while in battle
}//end battle
