//  Board.cpp

#include <iostream>
#include "Board.h"

///<summary>
///  This constructs the board with its default size value.
///</summary>
Board::Board()
{
	//  This sets the length of the array's first dimension.
	boardTiles = new char *[boardSize];
	//  This sets the length of the array's second dimension.
	for (size_t i = 0; i < boardSize; ++i)
	{
		boardTiles[i] = new char[boardSize];
	}
	//  This goes through the and sets all of the tiles to an empty space.
	for (size_t i = 0; i < boardSize; i++)
	{
		for (size_t j = 0; j < boardSize; j++)
		{
			boardTiles[i][j] = ' ';
		}
	}
}

///<summary>
///  This constructs the board with value given to it.
///</summary>
Board::Board(size_t size)
{
	boardSize = size;
	//  This sets the length of the array's first dimension.
	boardTiles =  new char *[size];
	//  This sets the length of the array's second dimension.
	for (size_t i = 0; i < size; ++i)
	{
		boardTiles[i] = new char[size];
	}
	//  This goes through the and sets all of the tiles to an empty space.
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			boardTiles[i][j] = ' ';
		}
	}
}

///<summary>
///  This deconstructs the board.
///</summary>
Board::~Board()
{
}