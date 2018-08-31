/*filename: grace's main.cpp*/

#include <iostream>
#include <string>
using namespace std;

#include "battle.cpp"


void battle(int fighterType);

int main()
{
    char play;
    int fighterType;
    for(int i=0;i<30;i++){cout<<"\n";}
  	cout << "\nGet ready to Fight!";
  	cout << "\nPlay(y) or	Exit(n): ";
    	cin >> play;
	while(play != 'y' && play != 'Y' && play != 'n' && play != 'N'){
		std::cout << "That's not a valid choice.\n\n" << std::endl;
		cin >> play;
	}
	switch(play) {
		case 'y':
		case 'Y':
			cout << "\nChoose a fighter!\n" <<endl;
            		cout << "Fighter 1: Higher attack power!\n" << endl;
            		cout << "Fighter 2: Higher defense power!\n" << endl;
            		cout << "Fighter 3: Higher healing power!\n" << endl;
            		cout << "Fighter 4: Equal stats!\n" << endl;
            		cin >> fighterType;
			while(fighterType!=1 && fighterType!=2 && fighterType!=3&& fighterType!=4) {
				std::cout << "Choose a valid Fighter.\n\n" << std::endl;
				cin >> fighterType;
			}
			battle(fighterType);
			break;
		case 'n':
		case 'N':
			cout << "\n Maybe next time !\n" << std::endl;
			break;
	}

	return 0;
}
