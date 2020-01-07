//  Main.cpp

#include <iostream>
#include <stdlib.h>
#include "Player.h"

using std::cout;
using std::cin;
using std::endl;

//  This holds the information on the players in the database.
Player * players;
size_t size = 1;
size_t index = 0;

///<summary>
///  This increases the size of the array.
///</summary>
Player * IncreaseSize(Player * arr, size_t arrSize)
{
	Player * newArr = new Player[arrSize + 1];
	for (size_t i = 0; i < arrSize; i++)
	{
		if (i == index)
		{
			newArr[i] = arr[arrSize - 1];
		}
		else if (i > index)
		{
			newArr[i] = arr[i - 1];
		}
		else if (i < index)
		{
			newArr[i] = arr[i];
		}
	}
	size++;
	return newArr;
}

///<summary>
///  This decreases the size of the array.
///</summary>
Player * DecreaseSize(Player * arr, size_t arrSize)
{
	Player * newArr = new Player[arrSize - 1];
	for (size_t i = 0; i < arrSize - 1; i++)
	{
		if (i == index)
		{
			continue;
		}
		else if (i > index)
		{
			newArr[i - 1] = arr[i];
		}
		else if (i < index)
		{
			newArr[i] = arr[i];
		}
	}
	size--;
	return newArr;
}

///<summary>
///  This allows the player to select where, in the array, they want to add the player.
///</summary>
void AddIndex()
{
	system("CLS");
	while (true)
	{
		cout << "Enter the index of the location you want to access." << endl
			<< "You can access anywhere from 0 to " << size - 1 << endl << "> ";
		size_t input;
		cin >> input;
		if (cin.fail())
		{
			cout << "Invalid Input" << std::endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (input > size - 1 || input < 0)
		{
			cout << "Invalid Input" << std::endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			index = input;
			break;
		}
	}
}

///<summary>
///  This allows the player to select which player in the array, they want to access.
///</summary>
void SelectIndex()
{
	system("CLS");
	if (size > 1)
	{
		while (true)
		{
			cout << "Enter the index of the location you want to access." << endl
				<< "You can access anywhere from 0 to " << size - 2 << endl << "> ";
			size_t input;
			cin >> input;
			if (cin.fail())
			{
				cout << "Invalid Input" << std::endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (input > size - 2 || input < 0)
			{
				cout << "Invalid Input" << std::endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
			{
				index = input;
				break;
			}
		}
	}
	else
	{
		return;
	}
}

///<summary>
///  This allows the player to enter player info into the database.
///</summary>
Player EnterPlayer()
{
	system("CLS");
	Player player;
	char * firstName = new char[20];
	char * title = new char[50];
	char * lastName = new char[20];
	char * game = new char[30];
	int careerWins = 0;;
	int age = 0;

	while (true)
	{
		cout << "Enter the player's first name." << endl << "> ";
		cin >> firstName;
		if (cin.fail())
		{
			cout << "Invalid Input" << std::endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			cout << endl;
			break;
		}
	}
	while (true)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "If the " << firstName << " has a title, enter the that." << endl
			<< "Otherwise, Enter 'NULL' to skip this." << endl << "> ";
		cin.getline(title, 50);
		if (cin.fail())
		{
			cout << "Invalid Input" << std::endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (title[0] == 'N' && title[1] == 'U' && title[2] == 'L' && title[3] == 'L')
		{
			title = nullptr;
			cout << endl;
			break;
		}
		else
		{
			cout << endl;
			break;
		}
	}
	while (true)
	{
		cout << "Enter the player's last name." << endl << "> ";
		cin >> lastName;
		if (cin.fail())
		{
			cout << "Invalid Input" << std::endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			cout << endl;
			break;
		}
	}
	while (true)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Enter the name of the game that " << firstName << " plays." << endl << "> ";
		cin.getline(game, 30);
		if (cin.fail())
		{
			cout << "Invalid Input" << std::endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			cout << endl;
			break;
		}
	}
	while (true)
	{
		cout << "Enter the number of times " << firstName << " was won during their career." << endl << "> ";
		cin >> careerWins;
		if (cin.fail())
		{
			cout << "Invalid Input" << std::endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			cout << endl;
			break;
		}
	}
	while (true)
	{
		cout << "Enter " << firstName << "'s age." << endl << "> ";
		cin >> age;
		if (cin.fail())
		{
			cout << "Invalid Input" << std::endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			cout << endl;
			break;
		}
	}
	player = Player(firstName, title, lastName, game, careerWins, age);
	system("CLS");
	return player;
}

///<summary>
///  This is used to delete a player from the database. But it hasn't been tested yet.
///</summary>
void DeletePlayer()
{
	system("CLS");
	if (size > 1)
	{
		SelectIndex();
		players = DecreaseSize(players, size);
		system("CLS");
	}
	else
	{
		cout << "There is nothing to delete." << endl;
	}
}

///<summary>
///  This prints a player's info to the console.
///</summary>
void PrintInfo(Player player)
{
	system("CLS");
	if (size > 1)
	{
		cout << "Name: " << player.firstName << ' ';
		if (player.title != nullptr)
		{
			cout << '"' << player.title << '"' << ' ';
		}
		cout << player.lastName << endl;
		cout << "Game: " << player.game << endl;
		cout << "Wins: " << player.careerWins << endl;
		cout << "Age: " << player.age << endl;
		cout << endl;
	}
	else
	{
		cout << "There is nothing to print." << endl;
	}
}

///<summary>
///  This is where the main game is run.
///</summary>
int main()
{
	players = new Player[size];
	while (true)
	{
		cout << "Would you like to (A)dd a player to the database, (E)dit and existing player's info," << endl
			<< "(D)elete a player's info, or (P)rint a player's information?" << endl
			<< "Or, enter (C) if you want to close the program." << endl << "> ";
		char input;
		cin >> input;
		if (cin.fail())
		{
			cout << "Invalid Input" << std::endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (input == 'A' || input == 'a')
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			AddIndex();
			players[size - 1] = EnterPlayer();
			players = IncreaseSize(players, size);
			PrintInfo(players[index]);
		}
		else if (input == 'E' || input == 'e')
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (size > 1)
			{
				SelectIndex();
				players[index] = EnterPlayer();
				PrintInfo(players[index]);
			}
			else
			{
				system("CLS");
				cout << "There is nothing to edit." << endl;
			}
		}
		else if (input == 'D' || input == 'd')
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			DeletePlayer();
		}
		else if (input == 'P' || input == 'p')
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			SelectIndex();
			PrintInfo(players[index]);
		}
		else if (input == 'C' || input == 'c')
		{
			break;
		}
		else
		{
			cout << "Invalid Input" << std::endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	/*SelectIndex();
	players[index] = EnterPlayer();
	PrintInfo(players[index]);*/
	delete[] players;
}