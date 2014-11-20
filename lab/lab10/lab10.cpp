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
void fillTable(long *table, int n);
void initTable(long *table);

int numberOfItems = 90000;

int main()
{
	long emptySpaces, highestNumberCollisions, numToFull;
	long *table = new long[numberOfItems];
	initTable(table);

	// 2-way collisions
	int n = 2;
	fillTable(table, n);

	// 5-way collisions
	initTable(table);
	n = 5;
	fillTable(table, n);

	// total collisions
	initTable(table);
	n = -1;
	fillTable(table, n);

	emptySpaces = countEmpties(table);
	highestNumberCollisions = countHighest(table);
	
	initTable(table);
	numToFull = untilItsFull(table);

	cout << "There were " << emptySpaces << " empty spaces in the table\n";
	cout << "There were " << highestNumberCollisions << " collisions in the most filled space\n";
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
	long highestKey = 0;
	long lowestKey = 90000;
	long numberKeys = 0;
	while (!full)
	{
		key = generateRandomKey();
		hashedKey = hashFunction(key);

		if (lowestKey == 0)
		{
			cout << empties << endl;
			for (int j = 0; j < numberOfItems; j++)
			{
				if (table[j] == 0)
				{
					cout << "first empty: " << j << endl;
					break;
				}
			}
			break;
		}

		if (empties <= 34948)
		{
			// 34948 gets it down to 10,732 empties
			hashedKey += 3;
			if (hashedKey > highestKey)
				highestKey = hashedKey;
			if (hashedKey < lowestKey)
				lowestKey = hashedKey;
			// cout << highestKey << endl;
			cout << lowestKey << endl;
		}

		if (hashedKey < lowestKey)
			lowestKey = hashedKey;
			// cout << highestKey << endl;
		cout << lowestKey << endl;

		table[hashedKey] += 1;
		numberKeys++;
		empties = 0;
		for (int i = 0; i < numberOfItems; i++)
		{
			if (table[i] == 0)
			{
				empties++;
			}
		}
		if (empties == 0)
			return numberKeys;
		// else
			// cout << "not full, " << numberKeys << " keys so far, " << empties << " empties\n";
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