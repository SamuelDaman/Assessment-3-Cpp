//  Main.cpp

#include <iostream>
#include <stdlib.h>
#include "Player.h"

using std::cout;
using std::cin;
using std::endl;

Player * players = new Player[100];
int index = 0;

void SelectIndex()
{
	system("CLS");
	while (true)
	{
		cout << "Enter the index of the player whose information you want to alter." << endl << "> ";
		int input;
		cin >> input;
		if (cin.fail())
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
	return player;
}

void DeletePlayer(Player player)
{
	system("CLS");
	SelectIndex();
	delete[]&players[index];
}

void PrintInfo(Player player)
{
	system("CLS");
	cout << "Name: " << player.firstName << ' ';
	if (player.title != nullptr)
	{
		cout << '"' << player.title << '"' << ' ';
	}
	cout << player.lastName << endl;
	cout << "Game: " << player.game << endl;
	cout << "Wins: " << player.careerWins << endl;
	cout << "Age: " << player.age << endl;
}

int main()
{
	SelectIndex();
	players[index] = EnterPlayer();
	PrintInfo(players[index]);
	while (true) {}
	delete players;
}