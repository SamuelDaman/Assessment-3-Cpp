//  Player.h

#pragma once

class Player
{
public:
	char * firstName;
	char * lastName;
	int age;

	Player();
	Player(char * firstname, char * lastname, int age);
	~Player();
};