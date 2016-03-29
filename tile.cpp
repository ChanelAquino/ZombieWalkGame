//Name: Chanel Aquino
//Date Created: 25 March 2016
//Description: Tile Implementation File

#include "tile.h"

unsigned int Tile::total_zombies = 0;
unsigned int Tile::total_scratches = 0;

//*************************************
Tile::Tile()
{
	tile_icon = '#';
	isZombie = false;
	isZombieVisible = false;
}
//
//*************************************
//


//*************************************
Tile::Tile(bool isZombie, unsigned int total_scratches)
{

	this->total_scratches = total_scratches;
	tile_icon = '#';
	this->isZombie = isZombie;
	isZombieVisible = false;
}
//
//*************************************
//


//*************************************
char Tile::getTileIcon()
{
	if(isZombie && !isZombieVisible)
		return '#';
	return tile_icon;
}
//
//*************************************
//


//*************************************
void Tile::setTileIcon(char icon_value)
{
	if(icon_value == 'X' || icon_value == '*' || icon_value == '#')
		tile_icon = icon_value;
}
//
//*************************************
//

//*************************************
void Tile::setIsZombie(bool is_zombie)
{
	isZombie = is_zombie;
	if(isZombie)
		total_zombies++;

	setTileIcon('*');
	setIsZombieVisible(false);
}
//
//*************************************
//


//*************************************
void Tile::exploreTile()
{
	if(isZombie)
	{
		setIsZombieVisible(true);
		setTileIcon('*');
		total_scratches++;
	}
	else
	{
		setTileIcon('X');
	}
}
//
//*************************************
//


//*************************************
void Tile::resetTile()
{
	if(isZombie && total_zombies != 0)
		total_zombies--;

	setTileIcon('#');
	setIsZombie(false);
	setIsZombieVisible(false);
}
//
//*************************************
//