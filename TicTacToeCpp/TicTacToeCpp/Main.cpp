//  Main.cpp

#include <iostream>
#include "Board.h"

//  This stores the information about the board on which the game takes place.
Board gameBoard;

///<summary>
///  This allows the player to set the size of the board.
///</summary>
Board SetBoard()
{
	Board board;
	int size = 0;
	while (true)
	{
		std::cout << "How large should the board be?" << std::endl;
		size = 0;
		std::cin >> size;
		//  This is used to check if the players enters an invalid input.
		if (std::cin.fail())
		{
			std::cout << "Invalid Input" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		//  The board is allowed to be 2x2 at the smallest...
		else if (size < 2)
		{
			std::cout << "Number is too small" << std::endl;
		}
		//  ...and 20x20 at the largest.
		else if (size > 20)
		{
			std::cout << "Number is too large" << std::endl;
		}
		//  if none of the above statements are true, the board will be set.
		else
		{
			break;
		}
	}
	board = Board(size);
	return board;
}

///<summary>
///  This is used to draw any changes made to the board.
///</summary>
void DrawBoard(Board board)
{
	//  A set of for loops is used to draw each tile of the board from a 2D array.
	for (size_t i = 0; i < board.boardSize; i++)
	{
		for (size_t j = 0; j < board.boardSize; j++)
		{
			std::cout << '|' << board.boardTiles[i][j] << '|';
		}
		std::cout << std::endl;
	}
}


///<summary>
///  This is where the X player takes their turn.
///</summary>
void PlayerX()
{
	while (true)
	{
		//  These variables are used to find the tile on which the X will be placed.
		size_t row = 0, column = 0;
		while (true)
		{
			std::cout << "Player X, in which row will you place your X?" << std::endl;
			std::cin >> row;
			//  If the check fails, it restarts the loop.
			if (std::cin.fail())
			{
				std::cout << "Invalid Input" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			//  If the input is too low, it restarts the loop.
			else if (row < 1)
			{
				std::cout << "Number is too small" << std::endl;
			}
			//  If the input is too high, it restarts the loop.
			else if (row > gameBoard.boardSize)
			{
				std::cout << "Number is too large" << std::endl;
			}
			// Otherwise, it moves on to the next input.
			else
			{
				break;
			}
		}
		while (true)
		{
			std::cout << "Player X, in which column will you place your X?" << std::endl;
			std::cin >> column;
			//  If the check fails, it restarts the loop.
			if (std::cin.fail())
			{
				std::cout << "Invalid Input" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			//  If the input is too low, it restarts the loop.
			else if (column < 1)
			{
				std::cout << "Number is too small" << std::endl;
			}
			//  If the input is too high, it restarts the loop.
			else if (column > gameBoard.boardSize)
			{
				std::cout << "Number is too large" << std::endl;
			}
			// Otherwise, it moves on.
			else
			{
				break;
			}
		}
		//  This checks if the selected tile is available...
		if (gameBoard.boardTiles[row - 1][column - 1] != 'X' && gameBoard.boardTiles[row - 1][column - 1] != 'O')
		{
			//  ...and, if so, places it..
			gameBoard.boardTiles[row - 1][column - 1] = 'X';
			DrawBoard(gameBoard);
			break;
		}
		else
		{
			//  ...if not, it restarts the process, completely.
			std::cout << "That spot is already taken." << std::endl;
		}
	}
}

///<summary>
///  This is where the O player takes their turn.
///</summary>
void PlayerO()
{
	while (true)
	{
		//  These variables are used to find the tile on which the O will be placed.
		size_t row, column = 0;
		while (true)
		{
			std::cout << "Player O, in which row will you place your O?" << std::endl;
			std::cin >> row;
			//  If the check fails, it restarts the loop.
			if (std::cin.fail())
			{
				std::cout << "Invalid Input" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			//  If the input is too low, it restarts the loop.
			else if (row < 1)
			{
				std::cout << "Number is too small" << std::endl;
			}
			//  If the input is too high, it restarts the loop.
			else if (row > gameBoard.boardSize)
			{
				std::cout << "Number is too large" << std::endl;
			}
			// Otherwise, it moves on to the next input.
			else
			{
				break;
			}
		}
		while (true)
		{
			std::cout << "Player O, in which column will you place your O?" << std::endl;
			std::cin >> column;
			//  If the check fails, it restarts the loop.
			if (std::cin.fail())
			{
				std::cout << "Invalid Input" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			//  If the input is too low, it restarts the loop.
			else if (column < 1)
			{
				std::cout << "Number is too small" << std::endl;
			}
			//  If the input is too high, it restarts the loop.
			else if (column > gameBoard.boardSize)
			{
				std::cout << "Number is too large" << std::endl;
			}
			// Otherwise, it moves on.
			else
			{
				break;
			}
		}
		//  This checks if the selected tile is available...
		if (gameBoard.boardTiles[row - 1][column - 1] != 'X' && gameBoard.boardTiles[row - 1][column - 1] != 'O')
		{
			//  ...and, if so, places it..
			gameBoard.boardTiles[row - 1][column - 1] = 'O';
			DrawBoard(gameBoard);
			break;
		}
		else
		{
			//  ...if not, it restarts the process, completely.
			std::cout << "That spot is already taken." << std::endl;
		}
	}
}

//  These booleans are used to check if a player has won and if the game is over.
bool gameOver = false;
bool xWin = false;
bool oWin = false;

///<summary>
///  This function is used to check whether the game has been, won, tied, or neither.
///</summary>
void EndGameCheck()
{
	for (size_t i = 0; i < gameBoard.boardSize; i++)
	{
		//  Row Check.
		if (gameBoard.boardTiles[i][0] == 'X' || gameBoard.boardTiles[i][0] == 'O')
		{
			//  Here, the "Win" booloeans are to true...
			xWin = true;
			oWin = true;
			for (size_t j = 0; j < gameBoard.boardSize; j++)
			{
				//  ...but, if any one of the tiles, in the row being checked, doesn't line up... 
				if (gameBoard.boardTiles[i][j] != 'X')
				{
					//  ...it's set back to false.
					xWin = false;
				}
				if (gameBoard.boardTiles[i][j] != 'O')
				{
					oWin = false;
				}
			}
			//  If xWin is true, The X player wins.
			if (xWin == true)
			{
				std::cout << "Player X wins!" << std::endl;
				gameOver = true;
				break;
			}
			//  If oWin is true, The O player wins.
			else if (oWin == true)
			{
				std::cout << "Player O wins!" << std::endl;
				gameOver = true;
				break;
			}
		}
		if (gameOver == true)
		{
			break;
		}

		//  Column Check.
		if (gameBoard.boardTiles[0][i] == 'X' || gameBoard.boardTiles[0][i] == 'O')
		{
			//  Here, the "Win" booloeans are to true...
			xWin = true;
			oWin = true;
			for (size_t j = 0; j < gameBoard.boardSize; j++)
			{
				//  ...but, if any one of the tiles, in the column being checked, doesn't line up... 
				if (gameBoard.boardTiles[j][i] != 'X')
				{
					xWin = false;
				}
				if (gameBoard.boardTiles[j][i] != 'O')
				{
					oWin = false;
				}
			}
			//  If xWin is true, The X player wins.
			if (xWin == true)
			{
				std::cout << "Player X wins!" << std::endl;
				gameOver = true;
				break;
			}
			//  If oWin is true, The O player wins.
			else if (oWin == true)
			{
				std::cout << "Player O wins!" << std::endl;
				gameOver = true;
				break;
			}
		}
		if (gameOver == true)
		{
			break;
		}

		//  Down Diagonal Check.
		if (gameBoard.boardTiles[i][i] == 'X' || gameBoard.boardTiles[i][i] == 'O')
		{
			//  Here, the "Win" booloeans are to true...
			xWin = true;
			oWin = true;
			for (size_t j = 0; j < gameBoard.boardSize; j++)
			{
				if (gameBoard.boardTiles[j][j] != 'X')
				{
					xWin = false;
				}
				if (gameBoard.boardTiles[j][j] != 'O')
				{
					oWin = false;
				}
			}
			//  If xWin is true, The X player wins.
			if (xWin == true)
			{
				std::cout << "Player X wins!" << std::endl;
				gameOver = true;
				break;
			}
			//  If oWin is true, The O player wins.
			else if (oWin == true)
			{
				std::cout << "Player O wins!" << std::endl;
				gameOver = true;
				break;
			}
		}
		if (gameOver == true)
		{
			break;
		}

		//  Up Diagonal Check.
		if (gameBoard.boardTiles[gameBoard.boardSize - 1 - i][i] == 'X' || gameBoard.boardTiles[gameBoard.boardSize - 1 - i][i] == 'O')
		{
			//  Here, the "Win" booloeans are to true...
			xWin = true;
			oWin = true;
			for (size_t j = 0; j < gameBoard.boardSize; j++)
			{
				if (gameBoard.boardTiles[gameBoard.boardSize - 1 - j][j] != 'X')
				{
					xWin = false;
				}
				if (gameBoard.boardTiles[gameBoard.boardSize - 1 - j][j] != 'O')
				{
					oWin = false;
				}
			}
			//  If xWin is true, The X player wins.
			if (xWin == true)
			{
				std::cout << "Player X wins!" << std::endl;
				gameOver = true;
				break;
			}
			//  If oWin is true, The O player wins.
			else if (oWin == true)
			{
				std::cout << "Player O wins!" << std::endl;
				gameOver = true;
				break;
			}
		}
		if (gameOver == true)
		{
			break;
		}

		//  Stalemate Check.
		//  GameOver is set to true...
		gameOver = true;
		for (size_t i = 0; i < gameBoard.boardSize; i++)
		{
			for (size_t j = 0; j < gameBoard.boardSize; j++)
			{
				//  ...so that it can be set to false if any spaces are free.
				if (gameBoard.boardTiles[i][j] == ' ')
				{
					gameOver = false;
					break;
				}
			}
		}
		//  If gameOver is true, the players stalemate.
		if (gameOver == true)
		{
			std::cout << "Stalemate! Both players tie!" << std::endl;
			break;
		}
	}
}

///<summary>
///  This is used to call all of the functions in the main gameplay loop.
///</summary>
void Game()
{
	while (true)
	{
		PlayerX();
		EndGameCheck();
		//  If gameOver is still true after the end of the X player's turn...
		if (gameOver == true)
		{
			//  ...break the loop.
			break;
		}
		PlayerO();
		EndGameCheck();
		//  If gameOver is still true after the end of the O player's turn...
		if (gameOver == true)
		{
			//  ...break the loop.
			break;
		}
	}
}

///<summary>
///  This is the function that runs the game.
///</summary>
int main()
{
		gameBoard = SetBoard();
		DrawBoard(gameBoard);
		Game();
		while (true) {}
}