//Board.h

#pragma once

#include <iostream>

class Board
{
public:
	size_t boardSize = 3;
	char ** boardTiles;

	Board();
	Board(size_t size);
	~Board();
};
