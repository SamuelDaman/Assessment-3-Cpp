//  Player.cpp

#include "Player.h"

Player::Player()
{
	(*this).firstName = new char[5] {"John"};
	(*this).title = new char[7]{ "Boring" };
	(*this).lastName = new char[6] {"Smith"};
	(*this).game = new char[12] {"Tic-Tac-Toe"};
	(*this).careerWins = 12;
	(*this).age = 24;
}
Player::Player(char * firstName, char * lastName, int age)
{
	(*this).firstName = firstName;
	(*this).title = nullptr;
	(*this).lastName = lastName;
	(*this).game = new char[12] {"Tic-Tac-Toe"};
	(*this).careerWins = 12;
	(*this).age = age;
}
Player::Player(char * firstName, char * title, char * lastName, int age)
{
	(*this).firstName = firstName;
	(*this).title = title;
	(*this).lastName = lastName;
	(*this).game = new char[12] {"Tic-Tac-Toe"};
	(*this).careerWins = 12;
	(*this).age = age;
}
Player::Player(char * firstName, char * lastName, char * game, int careerWins, int age)
{
	(*this).firstName = firstName;
	(*this).title = nullptr;
	(*this).lastName = lastName;
	(*this).game = game;
	(*this).careerWins = careerWins;
	(*this).age = age;
}
Player::Player(char * firstName, char * title, char * lastName, char * game, int careerWins, int age)
{
	(*this).firstName = firstName;
	(*this).title = title;
	(*this).lastName = lastName;
	(*this).game = game;
	(*this).careerWins = careerWins;
	(*this).age = age;
}
Player::~Player() 
{
	/*delete[](*this).firstName;
	delete[](*this).title;
	delete[](*this).lastName;
	delete[](*this).game;
	delete[] & (*this).careerWins;
	delete[] & (*this).age;*/
}

Player Player::operator=(const Player &rhs)
{
	(*this).firstName = rhs.firstName;
	(*this).title = rhs.title;
	(*this).lastName = rhs.lastName;
	(*this).game = rhs.game;
	(*this).careerWins = rhs.careerWins;
	(*this).age = rhs.age;
	return (*this);
}