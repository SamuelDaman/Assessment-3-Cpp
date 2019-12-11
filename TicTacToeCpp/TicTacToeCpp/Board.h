//  Board.h

#pragma once

#include <iostream>

///<summary>
///  This stores the information used to construct the game board.
///</summary>
class Board
{
public:
	//  This is the length and width of the board.
	size_t boardSize = 3;
	//  This hold all of the tiles in the board.
	char ** boardTiles;

	//  This is the default constructor.
	Board();
	//  This constructs the board based a number passed into it.
	Board(size_t size);
	//  This is the board destructor.
	~Board();
};
