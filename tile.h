//Name: Chanel Aquino
//Date Created: 25 March 2016
//Description: Tile Header File

#ifndef TILE_H
#define TILE_H

class Tile
{
	private:
		char tile_icon;

		bool isZombie,
			 isZombieVisible;

		static unsigned int total_zombies,
							total_scratches;

	public:
	//CONSTRUCTORS
		//*************************************
		Tile();
		//Summary: Default constructor that assigns default values to member variables.
		// tile_icon = char(176)
		// isZombie = false
		// isZombieVisible = false
		// total_zombies = 0
		// total_scratches = 0
		// total_zombies = 0
		//
		//*************************************
		//

		//*************************************
		Tile(bool isZombie, unsigned int total_scratches);
		//Summary: Overloaded constructor that assigns values to member varibles.
		// tile_icon = char(176)
		// this->isZombie = isZombie
		// isZombieVisible = false
		// total_zombies = 0
		// this->total_scratches = total_scratches
		//Poscondition: If isZombie is true, increment total_zombies by 1.
		//
		//*************************************
		//

	//ACCESSOR METHODS
		//*************************************
		bool getIsZombieVisible() {return isZombieVisible;}
		//Summary: Returns isZombieVisible.
		//
		//*************************************
		//

		//*************************************
		char getTileIcon();
		//Summary: Returns tile_icon's character value.
		//
		//*************************************
		//

		//*************************************
		bool getIsZombie() {return isZombie;}
		//Summary: Returns the value of isZombie.
		//
		//******************  *******************
		//

		//*************************************
		unsigned int getTotalZombies()const {return total_zombies;}
		//Summary: Return total_zombies.
		//
		//*************************************
		//

		//*************************************
		unsigned int getTotalScratches()const {return total_scratches;}
		//Summary: Return total_scratches.
		//
		//*************************************
		//

	//MUTATOR METHODS
		//*************************************
		void setIsZombieVisible(bool is_visible) 
			{isZombieVisible = is_visible;}
		//Summary: Sets corresponding value to isZombieVisible.
		//Postcondition: If zombie is now vibislble, set the tile_icon to '*'.
		//
		//*************************************
		//

		//*************************************
		void setTileIcon(char icon_value);
		//Summary: Assigns icon_value to tile_icon.
		//Precondition: icon_value must be 'x' or '*'.
		//
		//*************************************
		//

		//*************************************
		void setIsZombie(bool is_zombie);
		//Summary: Assign value to isZombie.
		//Postcondition: If the value is true, increment total_zombies by 1.
		//
		//*************************************
		//

		//*************************************
		void setTotalZombies(unsigned int total_zombies)
			{this->total_zombies = total_zombies;}
		//Summary: Assigns value to this->total_zombies.
		//
		//*************************************
		//

		//*************************************
		void setTotalScratches(unsigned int total_scratches)
			{this->total_scratches = total_scratches;}
		//Summary: Assigns value to this->total_zombies.
		//
		//*************************************
		//

	//OTHER MEMBER METHODS
		//*************************************
		void exploreTile();
		//Summary: If the tile is a zombie, then setIsZombieVisible to true,
		// and increment total_scratches by 1; else, set the tile_icon to 'x'.
		//
		//*************************************
		//

		//*************************************
		void resetTile();
		//Summary: Resets all the values in the tile to the specifications of the default constructor.
		//Precondition: If the original Tile was a zombie then subtract 1 from total_zombies.
		//	If total_zombies is 0, do not subtract.
		//
		//*************************************
		//	
};

#endif