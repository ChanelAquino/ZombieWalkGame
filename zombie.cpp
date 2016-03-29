//Name: Chanel Aquino
//Date Created: 25 March 2016
//Description: Zombie Implementation File

#include "tile.h"
#include "zombie.h"
#include <iostream>
#include <cstdlib>	//srand(), rand(), exit()
#include <ctime>	//time()
using namespace std; 


//*************************************
int displayMovementChoices();
//Summary: Displays menu of movement options.
//
//*************************************
//

//*************************************
void displayOutOfBounds();
//Summary: Displays out of bounds message to screen.
//
//*************************************
//


//*************************************
Zombie::Zombie()
{

	//Initialize player's starting position.
	row_coordinate = 0;
	column_coordinate = 0;

	//Ensure that total_scratches and total_zombies are 0 whenever creating a new Zombie object.
	board_game_grid[row_coordinate][column_coordinate].setTotalScratches(0);
	board_game_grid[row_coordinate][column_coordinate].setTotalZombies(0);


	//Declare variables needed to place zombies.
	int zombieRow, zombieColumn;

	//Generate seed for random number.
	srand(time(NULL));

	//Generate random number between 1 and 100, inclusive.
	int zombies = rand() % 100 + 1;

	//Fill in random spots of Tile array with zombies.
	for(int i = 0; i < zombies; i++)
	{
		//Generate random index for zombieRow and zombieColumn.
		zombieRow = rand() % 28 + 1;
		zombieColumn = rand() % 29;

		//If board_game_grid[zombieRow][zombieColumn] is not a zombie, set that position to be a zombie.
		if(!board_game_grid[zombieRow][zombieColumn].getIsZombie())
		{
			board_game_grid[zombieRow][zombieColumn].setIsZombie(true);
			board_game_grid[zombieRow][zombieColumn].setIsZombieVisible(false);
		}
		else
		{
			i--;
		}
	} //for
}
//
//*************************************
//


//*************************************
void Zombie::moveUp()
{
	if(row_coordinate != 0)
	{	
		board_game_grid[row_coordinate - 1][column_coordinate].exploreTile();
		row_coordinate--;
	}
	else
		displayOutOfBounds();
}
//
//*************************************
//


//*************************************
void Zombie::moveDown()
{
	if(row_coordinate != 29)
	{
		board_game_grid[row_coordinate + 1][column_coordinate].exploreTile();
		row_coordinate++;
	}
	else
		displayOutOfBounds();
}
//
//*************************************
//


//*************************************
void Zombie::moveLeft()
{
	if(column_coordinate != 0)
	{
		board_game_grid[row_coordinate][column_coordinate - 1].exploreTile();
		column_coordinate--;
	}
	else
		displayOutOfBounds();
}
//
//*************************************
//


//*************************************
void Zombie::moveRight()
{
	if(column_coordinate != 29)
	{
		board_game_grid[row_coordinate][column_coordinate + 1].exploreTile();
		column_coordinate++;
	}
	else
		displayOutOfBounds();
}
//
//*************************************
//


//*************************************
void Zombie::upDiag()
{
	if(row_coordinate != 0 && column_coordinate != 29)
	{
		board_game_grid[row_coordinate - 1][column_coordinate + 1].exploreTile();
		row_coordinate--;
		column_coordinate++;
	}
	else
		displayOutOfBounds();
}
//
//*************************************
//


//*************************************
void Zombie::downDiag()
{
	if(row_coordinate != 29 && column_coordinate != 29) 
	{
		board_game_grid[row_coordinate + 1][column_coordinate + 1].exploreTile();
		row_coordinate++;
		column_coordinate++;
	}
	else
		displayOutOfBounds();
}
//
//*************************************
//


//*************************************
void Zombie::newGame()
{
	//Create a new Zombie object and run game.
	Zombie newZombie;
	newZombie.runGame();
}
//
//*************************************
//


//*************************************
void Zombie::displayBoard()
{
	cout << endl << "START HERE" << endl;

	for(int i = 0; i < 30; i++)
	{
		cout << "\t";
		for(int j = 0; j < 30; j++)
		{
			cout << board_game_grid[i][j].getTileIcon();
		}
		cout << endl;
	}

	cout 
		<< "\t\t\t\tEND HERE" << endl
		<< endl << ".............................."
		<< endl << ".... Number of Zombies: " << board_game_grid[row_coordinate][column_coordinate].getTotalZombies()
		<< endl << ".... Total Scratches: " << board_game_grid[row_coordinate][column_coordinate].getTotalScratches()
		<< endl << ".............................." << endl;
}
//
//*************************************
//


//*************************************
void Zombie::displayGameOver()
{
	cout <<  "GAME OVER!" << endl;

	for(int i = 0; i < 30; i++)
	{
		for(int j = 0; j < 30; j++)
		{
			if(board_game_grid[i][j].getIsZombie())
				board_game_grid[i][j].setIsZombieVisible(true);
		}
	}

	displayBoard();
}
//
//*************************************
//


//*************************************
void Zombie::checkEndGame()
{
	char keepGoing;

	if(isGameOver())
		displayGameOver();
	if(didWin())
	{
		cout << "Congratulations! You escaped all the zombies!" << endl;
	}
	else
	{
		cout << endl << "Oh no!! The zombies have feasted on your flesh and bones. You are dead!" << endl;
	}

	do
	{
		cout << "Would you like to play again? Enter \'y\' to continue and any other key to quit: ";
		cin >> keepGoing;
		keepGoing = tolower(keepGoing);

	} while(keepGoing =='y');
	
	if(keepGoing == 'y')
		newGame();
	else
		cout << endl << "Thank you for playing! Exiting game now..." << endl;
}
//
//*************************************
//


//*************************************
void Zombie::runGame()
{
	while(!isGameOver() && !didWin())
	{	
		displayBoard();
		switch(displayMovementChoices())
		{
			case 1:
				moveUp();
				break;
			case 2: 
				moveDown();
				break;
			case 3: 
				moveRight();
				break;
			case 4:
				moveLeft();
				break;
			case 5:
				upDiag();
				break;
			case 6:
				downDiag();
				break;
			case 7:
				newGame();
				break;
			case 8:
				cout << endl << "Thank you for playing! Exiting game now..." << endl << endl << endl;
				exit(1);
			default:
				cout << endl << "ERROR: Invalid option. Try again." << endl;
				break;
		} //switch
	}
	checkEndGame();
}
//
//*************************************
//


//*************************************
int displayMovementChoices()
{
	int choice;

	cout 
		<< endl << "> In which direction do you wish to move?" << endl
		<< ">\t[1]: up \t[2]: down" << endl
		<< ">\t[3]: right \t[4]: left" << endl
		<< ">\t[5]: up diag \t[6]: down diag" << endl
		<< ">\t[7]: new \t[8]: quit" << endl
		<< "> Enter move now: ";
	cin >> choice;

	return choice;
}
//
//*************************************
//


//*************************************
void displayOutOfBounds()
{
	cout 
			<< endl 
			<< "\t-----------------------------" << endl
			<< "\t- Out of bounds. Try again! -" << endl
			<< "\t-----------------------------" << endl;
}
//
//*************************************
//