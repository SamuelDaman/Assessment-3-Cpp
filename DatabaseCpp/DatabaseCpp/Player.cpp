//  Player.cpp

#include "Player.h"

// These are different constuctor overloads for the Player class.
Player::Player()
{
	(*this).firstName = new char[12] {"[FirstName]"};
	(*this).title = nullptr;
	(*this).lastName = new char[11] {"[LastName]"};
	(*this).game = new char[7] {"[Game]"};
	(*this).careerWins = 0;
	(*this).age = 0;
}
Player::Player(char * firstName, char * lastName, int age)
{
	(*this).firstName = firstName;
	(*this).title = nullptr;
	(*this).lastName = lastName;
	(*this).game = new char[7] {"[Game]"};
	(*this).careerWins = 0;
	(*this).age = age;
}
Player::Player(char * firstName, char * title, char * lastName, int age)
{
	(*this).firstName = firstName;
	(*this).title = title;
	(*this).lastName = lastName;
	(*this).game = new char[7]{ "[Game]" };
	(*this).careerWins = 0;
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
	(*this).firstName = nullptr;
	(*this).title = nullptr;
	(*this).lastName = nullptr;
	(*this).game = nullptr;
	(*this).careerWins = 0;
	(*this).age = 0;
}

//  This is used to set two 'Player' classes equal to each other.
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