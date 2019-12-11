//  Player.h

#pragma once

class Player
{
public:
	char * firstName;
	char * title;
	char * lastName;
	char * game;
	int careerWins;
	int age;

	Player();
	Player(char * firstName, char * lastName, int age);
	Player(char * firstName, char * title, char * lastName, int age);
	Player(char * firstname, char * lastname, char * game, int careerWins, int age);
	Player(char * firstname, char * title, char * lastname, char * game, int careerWins, int age);
	~Player();

	Player operator=(const Player &rhs);
};