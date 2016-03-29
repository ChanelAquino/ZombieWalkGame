//Name: Chanel Aquino
//Date Created: 25 March 2016
//Description: Zombiewalk Driver File


#include "tile.h"
#include "zombie.h"
#include <iostream>
using namespace std;

int main()
{
	cout 
		<< "|===============================================|" << endl
		<< "|  WELCOME TO THE ZOMBIE GAME! ESCAPE, ESCAPE!  |" << endl
		<< "|                                               |" << endl
		<< "|-----------------------------------------------|" << endl
		<< "|                                               |" << endl
		<< "| [#]: unexplored | [X]: explored | [*]: zombie |" << endl
		<< "|===============================================|" << endl << endl; 

	//Create Zombie object and run game.
	Zombie z1;
	z1.runGame();
	
	return 0;
}