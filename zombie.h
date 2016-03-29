//Name: Chanel Aquino
//Date Created: 25 March 2016
//Description: Zombie Header File

#include "tile.h"
#ifndef ZOMBIE_H
#define ZOMBIE_H

class Zombie
{
	private: 
		Tile board_game_grid[30][30];
		unsigned int row_coordinate,
					 column_coordinate;

	public:
	//CONSTRUCTORS
		//*************************************
		Zombie();
		//Summary: Default constructor that creates a random number
		// of zombies from 1 - 100 and places the zombies in random locations 
		// except for at array location [0][0] and [29][29].
		//
		//*************************************
		//

	//ACCESSOR METHODS
		//*************************************
		unsigned int getRowCoord()const {return row_coordinate;}
		//Summary: Returns current row position.
		//
		//*************************************
		//

		//*************************************
		unsigned int getColumnCoord()const {return column_coordinate;}
		//Summary: Returns current column position.
		//
		//*************************************
		//

	//MEMBER METHODS: MOVEMENT
		//*************************************
		void moveUp();
		//Summary: Moves the character to the tile above in the 2D array.
		//Precondition: Ensure character does not go out of bounds.
		//Postcondition: An 'x' should be placed at this location, unless
		// there is a zombie. If there is a zombie, update total_scratches
		// and set isVisible to true. 
		//
		//*************************************
		//

		//*************************************
		void moveDown();
		//Summary: Moves the character to the tile below in the 2D array.
		//Precondition: Refer to moveUp().
		//Postcondition: Refer to moveUp().
		//
		//*************************************
		//

		//*************************************
		void moveLeft();
		//Summary: Moves the character to the tile to the left in the 2D array.
		//Precondition: Refer to moveUp().
		//Postcondition: Refer to moveUp().
		//
		//*************************************
		//

		//*************************************
		void moveRight();
		//Summary: Moves the character to the tile to the right in the 2D array.
		//Precondition: Refer to moveUp().
		//Postcondition: Refer to moveUp().
		//
		//*************************************
		//

		//*************************************
		void upDiag();
		//Summary: Moves the character to the tile 1 up and 1 right in the 2D array. 
		//Precondition: Refer to moveUp().
		//Postcondition: Refer to moveUp().
		//
		//*************************************
		//

		//*************************************
		void downDiag();
		//Summary: Moves the character 1 down and 1 right in the 2D array.
		//Precondition: Refer to moveUp().
		//Postcondition: Refer to moveUp().
		//
		//*************************************
		//

	//MEMBER METHODS: GAME STATUS
		//*************************************
		void newGame();
		//Summary: Reset the 2D array of tiles and create a new random number of zombies.
		//
		//*************************************
		//

		//*************************************
		void displayBoard();
		//Summary: Display current 2D array board.
		//
		//*************************************
		//

		//*************************************
		void displayGameOver();
		//Summary: Display "GAME OVER" and the 2D array board with all zombies.
		//
		//*************************************
		//

		//*************************************
		bool isGameOver() 
			{return 
				((board_game_grid[row_coordinate][column_coordinate].getTotalScratches() > 2) 
				 && (row_coordinate != 29) 
				 && (column_coordinate != 29));}
		//Summary: Returns true is total_scratches > 2 and
		// player is not at location [29][29]; else, return false.
		//
		//*************************************
		//

		//*************************************
		bool didWin()
			{return(row_coordinate == 29 && column_coordinate == 29);}
		//Summary: Returns true if the user makes it to location[29][29];
		// else, return false.
		//
		//*************************************
		//

		//*************************************
		void checkEndGame();
		//Summary: Checks if the game is over or if the player won.
		// If any of these occurred, display the result and ask 
		// if the user wants to play again. If they do, create a new game.
		//
		//*************************************
		//

		//*************************************
		void runGame();
		//Summary: Run the game with following conditions:
		// 1) start using at location [0][0],
		// 2) continuously ask if they want to go: [1] up, [2] down,
		//		[3] right, [4] left, [5] up diagonal, [6] down diagonal.
		// 3) After each move, display the board with unzeen zombies as invisible.
		// 4) Display total_zombies on board.
		// Keep running the game until game is over.
		//
		//*************************************
		//

};

#endif