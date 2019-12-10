//Main.cpp

#include <iostream>
#include "Board.h"

Board gameBoard;

Board SetBoard()
{
	Board board;
	int size = 0;
	while (true)
	{
		std::cout << "How large should the board be?" << std::endl;
		size = 0;
		std::cin >> size;
		if (std::cin.fail())
		{
			std::cout << "Invalid Input" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (size < 2)
		{
			std::cout << "Number is too small" << std::endl;
		}
		else if (size > 20)
		{
			std::cout << "Number is too large" << std::endl;
		}
		else
		{
			break;
		}
	}
	board = Board(size);
	return board;
}

void DrawBoard(Board board)
{
	for (size_t i = 0; i < board.boardSize; i++)
	{
		for (size_t j = 0; j < board.boardSize; j++)
		{
			std::cout << '|' << board.boardTiles[i][j] << '|';
		}
		std::cout << std::endl;
	}
}

void PlayerX()
{
	while (true)
	{
		size_t row = 0, column = 0;
		while (true)
		{
			std::cout << "Player X, in which row will you place your X?" << std::endl;
			std::cin >> row;
			if (std::cin.fail())
			{
				std::cout << "Invalid Input" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (row < 1)
			{
				std::cout << "Number is too small" << std::endl;
			}
			else if (row > gameBoard.boardSize)
			{
				std::cout << "Number is too large" << std::endl;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			std::cout << "Player X, in which column will you place your X?" << std::endl;
			std::cin >> column;
			if (std::cin.fail())
			{
				std::cout << "Invalid Input" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (column < 1)
			{
				std::cout << "Number is too small" << std::endl;
			}
			else if (column > gameBoard.boardSize)
			{
				std::cout << "Number is too large" << std::endl;
			}
			else
			{
				break;
			}
		}
		if (gameBoard.boardTiles[row - 1][column - 1] != 'X' && gameBoard.boardTiles[row - 1][column - 1] != 'O')
		{
			gameBoard.boardTiles[row - 1][column - 1] = 'X';
			DrawBoard(gameBoard);
			break;
		}
		else
		{
			std::cout << "That spot is already taken." << std::endl;
		}
	}
}

void PlayerO()
{
	while (true)
	{
		size_t row, column = 0;
		while (true)
		{
			std::cout << "Player O, in which row will you place your O?" << std::endl;
			std::cin >> row;
			if (std::cin.fail())
			{
				std::cout << "Invalid Input" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (row < 1)
			{
				std::cout << "Number is too small" << std::endl;
			}
			else if (row > gameBoard.boardSize)
			{
				std::cout << "Number is too large" << std::endl;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			std::cout << "Player O, in which column will you place your O?" << std::endl;
			std::cin >> column;
			if (std::cin.fail())
			{
				std::cout << "Invalid Input" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (column < 1)
			{
				std::cout << "Number is too small" << std::endl;
			}
			else if (column > gameBoard.boardSize)
			{
				std::cout << "Number is too large" << std::endl;
			}
			else
			{
				break;
			}
		}
		if (gameBoard.boardTiles[row - 1][column - 1] != 'X' && gameBoard.boardTiles[row - 1][column - 1] != 'O')
		{
			gameBoard.boardTiles[row - 1][column - 1] = 'O';
			DrawBoard(gameBoard);
			break;
		}
		else
		{
			std::cout << "That spot is already taken." << std::endl;
		}
	}
}

bool gameOver = false;
bool xWin = false;
bool oWin = false;

void EndGameCheck()
{
	for (size_t i = 0; i < gameBoard.boardSize; i++)
	{
		//Row Check
		if (gameBoard.boardTiles[i][0] == 'X' || gameBoard.boardTiles[i][0] == 'O')
		{
			xWin = true;
			oWin = true;
			for (size_t j = 0; j < gameBoard.boardSize; j++)
			{
				if (gameBoard.boardTiles[i][j] != 'X')
				{
					xWin = false;
				}
				if (gameBoard.boardTiles[i][j] != 'O')
				{
					oWin = false;
				}
			}
			if (xWin == true)
			{
				std::cout << "Player X wins!" << std::endl;
				gameOver = true;
				break;
			}
			else if (oWin == true)
			{
				std::cout << "Player O wins!" << std::endl;
				gameOver = true;
				break;
			}
		}
		if (gameOver == true)
			break;

		//Column Check
		if (gameBoard.boardTiles[0][i] == 'X' || gameBoard.boardTiles[0][i] == 'O')
		{
			xWin = true;
			oWin = true;
			for (size_t j = 0; j < gameBoard.boardSize; j++)
			{
				if (gameBoard.boardTiles[j][i] != 'X')
				{
					xWin = false;
				}
				if (gameBoard.boardTiles[j][i] != 'O')
				{
					oWin = false;
				}
			}
			if (xWin == true)
			{
				std::cout << "Player X wins!" << std::endl;
				gameOver = true;
				break;
			}
			else if (oWin == true)
			{
				std::cout << "Player O wins!" << std::endl;
				gameOver = true;
				break;
			}
		}
		if (gameOver == true)
			break;

		//Down Diagonal Check
		if (gameBoard.boardTiles[i][i] == 'X' || gameBoard.boardTiles[i][i] == 'O')
		{
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
			if (xWin == true)
			{
				std::cout << "Player X wins!" << std::endl;
				gameOver = true;
				break;
			}
			else if (oWin == true)
			{
				std::cout << "Player O wins!" << std::endl;
				gameOver = true;
				break;
			}
		}
		if (gameOver == true)
			break;

		//Up Diagonal Check
		if (gameBoard.boardTiles[gameBoard.boardSize - 1 - i][i] == 'X' || gameBoard.boardTiles[gameBoard.boardSize - 1 - i][i] == 'O')
		{
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
			if (xWin == true)
			{
				std::cout << "Player X wins!" << std::endl;
				gameOver = true;
				break;
			}
			else if (oWin == true)
			{
				std::cout << "Player O wins!" << std::endl;
				gameOver = true;
				break;
			}
		}
		if (gameOver == true)
			break;

		//Stalemate Check
		gameOver = true;
		for (size_t i = 0; i < gameBoard.boardSize; i++)
		{
			for (size_t j = 0; j < gameBoard.boardSize; j++)
			{
				if (gameBoard.boardTiles[i][j] == ' ')
				{
					gameOver = false;
					break;
				}
			}
		}
		if (gameOver == true)
		{
			std::cout << "Stalemate! Both players tie!" << std::endl;
			break;
		}
	}
}

void Game()
{
	while (true)
	{
		PlayerX();
		EndGameCheck();
		if (gameOver == true)
			break;
		PlayerO();
		EndGameCheck();
		if (gameOver == true)
			break;
	}
}

int main()
{
	while (true)
	{
		gameBoard = SetBoard();
		DrawBoard(gameBoard);
		Game();
		while (true) {}
	}
	return 0;
}