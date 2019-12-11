//  Player.cpp

#include "Player.h"

Player::Player()
{
	(*this).firstName = new char[]{ "John" };
	(*this).lastName = new char[] {"Smith"};
	(*this).age = 21;
}
Player::Player(char * firstName, char * lastName, int age)
{
	(*this).firstName = firstName;
	(*this).lastName = lastName;
	(*this).age = age;
}
Player::~Player() {}