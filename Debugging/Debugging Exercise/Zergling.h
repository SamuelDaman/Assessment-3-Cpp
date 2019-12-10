#pragma once

#include "Entity.h"

class Zergling : public Entity
{
public:
	Zergling();
	~Zergling();

	int attack();
	void takeDamage(int damage);
	bool isAlive();

private:
	int health;
	int maxHealth;
};

