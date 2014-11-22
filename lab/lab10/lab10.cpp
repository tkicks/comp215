/*
	Tyler Kickham
	Questions
	a. I have to generate 175 keys to get my first collision.
	b. I have to generate 23305 keys to get my first 5-way collision.
	c. I had 33155 total collisions.
	d. I had 33155 empty spaces in the table.
	e. I had 7 collisions in the most filled space.
	f. It took 1012410 keys to fill the entire array.
	g. There were 26 collisions in the most filled space when array is full
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <random>

using namespace std;

long generateRandomKey();
long hashFunction(long key);
long countEmpties(long *table);
long countHighest(long *table);
long untilItsFull(long *table);
void fillTable(long *table, int n);
void initTable(long *table);

int numberOfItems = 90000;
default_random_engine generator;
uniform_int_distribution<long> distribution(0,180000);

int main()
{
	long emptySpaces, highestNumberCollisions, numToFull, highestNumberCollisionsFull;
	long *table = new long[numberOfItems];
	initTable(table);

	// 2-way collisions change n to desired number of collisions to check
	int n = 2;
	fillTable(table, n);

	// 5-way collisions change n to desired number of collisions to check
	initTable(table);
	n = 5;
	fillTable(table, n);

	// total collisions
	// ================== DON'T CHANGE n ==================
	initTable(table);
	n = -1;
	fillTable(table, n);

	emptySpaces = countEmpties(table);
	highestNumberCollisions = countHighest(table);
	
	initTable(table);
	numToFull = untilItsFull(table);

	highestNumberCollisionsFull = countHighest(table);

	cout << "There were " << emptySpaces << " empty spaces in the table\n";
	cout << "There were " << highestNumberCollisions << " collisions in the most filled space\n";
	cout << "It took " << numToFull << " keys to fill the entire array\n";
	cout << "There were " << highestNumberCollisionsFull << " collisions in the most filled space when array is full\n";
}

long generateRandomKey()
{
	return distribution(generator);
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

long untilItsFull(long* table)
{
	bool full = false;
	long key, hashedKey;
	long numberKeys = 0;
	while (full == false)
	{
		full = true;
		key = generateRandomKey();
		hashedKey = hashFunction(key);
		table[hashedKey] += 1;
		numberKeys++;
		for (int i = 0; i < numberOfItems; i++)
		{
			if (table[i] == 0)
			{
				full = false;
			}
		}
		if (full == true)
			return numberKeys;
	}
}

void initTable(long* table)
{
	for (int i = 0; i < numberOfItems; i++)
		table[i] = 0;
}

void fillTable(long* table, int n)
{	
	int collisionCount = 0;
	int totalCollisions = 0;
	long key, hashedKey, position;

	if (n == -1)
	{
		for (int i = 0; i < numberOfItems; i++)
		{
			position = i;
			key = generateRandomKey();
			hashedKey = hashFunction(key);
			table[hashedKey] += 1;
			if (table[hashedKey] > 1)
			{
				totalCollisions++;
			}
		}
		cout << totalCollisions << " total collisions\n";
	}

	else 
	{
		for (int i = 0; i < numberOfItems; i++)
		{
			position = i;
			key = generateRandomKey();
			hashedKey = hashFunction(key);
			table[hashedKey] += 1;

			if (table[hashedKey] == n)
			{
				collisionCount++;
				cout << collisionCount << "st " << n << "-way collision at " << i << "th key generated\n";
				break;
			}
		}
	}
}