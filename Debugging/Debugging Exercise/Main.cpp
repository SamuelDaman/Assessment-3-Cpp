// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

// Last modified by Terry Nguyen (terryn@aie.edu.au)
// 10/09/2018

#include <iostream>
#include "Marine.h"
#include "Zergling.h"

using std::cout;
using std::endl;

bool marineAlive(Marine * squadArr, size_t arrSize);
bool zerglingAlive(Zergling * swarmArr, size_t arrSize);

int main()
{
	const size_t SQUADSIZE = 10;
	Marine squad[SQUADSIZE];
	size_t targetZerg = 0;

	const size_t SWARMSIZE = 20;
	Zergling swarm[SWARMSIZE];
	size_t targetMarine = 0;

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;
	// Attack each other until only one team is left alive
	while (marineAlive(squad, SQUADSIZE) && zerglingAlive(swarm, SWARMSIZE)) // If anyone is left alive to fight . . .
	{
		if (marineAlive(squad, SQUADSIZE)) // if there's at least one marine alive
		{
			for (size_t i = targetMarine; i < SQUADSIZE; i++) // go through the squad
			{
				// each marine will attack the first zergling in the swarm
				cout << "A marine fires for " << squad->attack() << " damage. " << endl;
				swarm[targetZerg].takeDamage(squad->attack());
				if (!swarm[targetZerg].isAlive()) // if the zergling dies, it is marked as such
				{
					targetZerg++;
					cout << "The zergling target dies" << endl;
					cout << "There are " << SWARMSIZE - targetZerg << " zerglings left." << endl;
				}
				if (targetZerg >= SWARMSIZE)
				{
					break;
				}
			}
			cout << endl;
		}
		if (zerglingAlive(swarm, SWARMSIZE)) // if there's at least one zergling alive
		{
			for (size_t i = targetZerg; i < SWARMSIZE; i++) // loop through zerglings
			{
				cout << "A zergling attacks for " << swarm->attack() << " damage." << endl;
				squad[targetMarine].takeDamage(swarm->attack());
				if (!squad[targetMarine].isAlive())
				{
					targetMarine++;
					cout << "The marine succumbs to his wounds." << endl;
					cout << "There are " << SQUADSIZE - targetMarine  << " marines left." << endl;
				}
				if (targetMarine >= SQUADSIZE)
				{
					break;
				}
			}
			cout << endl;
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (marineAlive(squad, SQUADSIZE))
	{
		cout << "The Marines win." << endl;
	} else {
		cout << "The Zerg win." << endl;
	}
}

// Is there a Marine Alive?
bool marineAlive(Marine * squadArr, size_t arrSize)
{
	for (size_t i = 0; i < arrSize; i++)
	{
		if (squadArr[i].isAlive())
		{
			return true;
		}
	}
	return false;
}

// Is there a zergling Alive
bool zerglingAlive(Zergling * swarmArr, size_t arrSize)
{
	for (size_t i = 0; i < arrSize; i++)
	{
		if (swarmArr[i].isAlive())
		{
			return true;
		}
	}
	return false;
}
