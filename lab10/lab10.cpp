/*
	Tyler Kickham
	Questions
	a. I have to generate 147 keys to get my first collision.
	b. I have to generate 20640 keys to get my first 5-way collision.
	c. I had 46539 total collisions.
	d. I had 46539 empty spaces in the table.
	e. I had 9 collisions in the most filled space.
*/
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

long generateRandomKey();
long hashFunction(long key);
long countEmpties(long *table);
long countHighest(long *table);
long untilItsFull(long *table);
void initTable(long *table);

int numberOfItems = 90000;

int main()
{
	int collisionCount2 = 0;
	int collisionCount5 = 0;
	int totalCollisions = 0;
	long key, hashedKey, emptySpaces, highestNumberCollisions, numToFull;
	long *table = new long[numberOfItems];
	initTable(table);

	// for (int i = 0; i < numberOfItems; i++)
	// {
	// 	key = generateRandomKey();
	// 	hashedKey = hashFunction(key);
	// 	table[hashedKey] += 1;

	// 	if (table[hashedKey] == 2)
	// 	{
	// 		collisionCount2++;
	// 		cout << collisionCount2 << "th 2-way collision at " << i << "th key generated\n";
	// 		// break;
	// 	}
	// 	if (table[hashedKey] == 5)
	// 	{
	// 		collisionCount5++;
	// 		cout << collisionCount5 << "th 5-way collision at " << i << "th key generated\n";
	// 		// break;
	// 	}
	// 	if (table[hashedKey] > 1)
	// 	{
	// 		totalCollisions++;
	// 	}
	// }

	// emptySpaces = countEmpties(table);
	// highestNumberCollisions = countHighest(table);
	numToFull = untilItsFull(table);
	// cout << "There were " << totalCollisions << " total collisions\n";
	// cout << "There were " << emptySpaces << " empty spaces in the table\n";
	// cout << "There were " << highestNumberCollisions << " collisions in the most filled space\n";
	cout << "It took " << numToFull << " keys to fill the entire array\n";
}

long generateRandomKey()
{
	return (rand()%numberOfItems);
}

long hashFunction(long key)
{
	return (((11057*key) % 179999) % numberOfItems);
}

long countEmpties(long* table)
{
	long numEmpties = 0;
	for (int i = 0; i < numberOfItems; i++)
	{
		if (table[i] == 0)
			numEmpties++;
	}
	return numEmpties;
}

long countHighest(long* table)
{
	long highest = 0;
	for (int i = 0; i < numberOfItems; i++)
	{
		if (table[i] > highest)
			highest = table[i];
	}
	return highest;
}

// long untilItsFull(long* table)
// {
// 	bool full = false;
// 	long key, hashedKey;
// 	long numberKeys = 0;
// 	while (full == false)
// 	{
// 		full = true;
// 		key = generateRandomKey();
// 		hashedKey = hashFunction(key);
// 		table[hashedKey] += 1;
// 		numberKeys++;
// 		for (int i = 0; i < numberOfItems; i++)
// 		{
// 			if (table[i] == 0)
// 			{
// 				full = false;
// 			}
// 		}
// 		if (full == true)
// 			return numberKeys;
// 		else
// 			cout << "not full and " << numberKeys << " keys so far\n";
// 	}
// }

long untilItsFull(long* table)
{
	bool full = false;
	long key, hashedKey, empties;
	long numberKeys = 0;
	while (full == false)
	{
		empties = 0;
		key = generateRandomKey();
		hashedKey = hashFunction(key);
		table[hashedKey] += 1;
		numberKeys++;
		for (int i = 0; i < numberOfItems; i++)
		{
			if (table[i] == 0)
			{
				empties++;
			}
		}
		if (empties == 0)
			return numberKeys;
		else
			cout << "not full, " << numberKeys << " keys so far, " << empties << " empties\n";
	}
}

void initTable(long* table)
{
	for (int i = 0; i < numberOfItems; i++)
		table[i] = 0;
}