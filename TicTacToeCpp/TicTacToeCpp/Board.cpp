//Board.cpp

#include <iostream>
#include "Board.h"

Board::Board()
{
	boardTiles = new char *[boardSize];
	for (size_t i = 0; i < boardSize; ++i)
		boardTiles[i] = new char[boardSize];
	for (size_t i = 0; i < boardSize; i++)
	{
		for (size_t j = 0; j < boardSize; j++)
		{
			boardTiles[i][j] = ' ';
		}
	}
}

Board::Board(size_t size)
{
	boardSize = size;
	boardTiles =  new char *[size];
	for (size_t i = 0; i < size; ++i)
		boardTiles[i] = new char[size];
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			boardTiles[i][j] = ' ';
		}
	}
}

Board::~Board()
{
}