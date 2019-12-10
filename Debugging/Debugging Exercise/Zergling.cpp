#include "Zergling.h"

Zergling::Zergling()
{
	health = 25;
}

Zergling::~Zergling()
{
}

int Zergling::attack()
{
	return 5;
}

void Zergling::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
		health = 0;
}

bool Zergling::isAlive()
{
	return health > 0;
}
