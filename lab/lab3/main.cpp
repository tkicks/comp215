// Tyler Kickham

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <time.h>

using namespace std;

void generateFile();


class integerPairs
{
	public:
		int value1, value2;
		integerPairs(){};
		integerPairs(int a, int b);
		bool operator==(integerPairs&);
		bool operator>(integerPairs&);
		bool operator>=(integerPairs&);
		bool operator<(integerPairs&);
		bool operator<=(integerPairs&);
};


integerPairs* readFile(int nbLines);
void ourSort(integerPairs* array, int n);
integerPairs findMax(integerPairs* array, int n, int& x);
void ourSortTiming(int size);

void generateFile()
{
	// commented out to avoid collecting 200,000,000 every time
	ofstream myfile;
	srand(time(NULL));
	myfile.open("InputNumbers.dat");
	int firstRand, secondRand;
	for (int i = 0; i < 10; i++) {
		firstRand = rand()%100;
		secondRand = rand()%100;
		myfile << firstRand << " " << secondRand << "\n";
	}
	myfile.close();
}

integerPairs::integerPairs(int a, int b)
{
	value1 = a;
	value2 = b;
}

bool integerPairs::operator==(integerPairs&)
{
	int a, b, c, d;
	if ((a == c) && (b == d))
		return true;
	else
		return false;
}

bool integerPairs::operator>(integerPairs&)
{
	int a, b, c, d;
	if ((a > c) || ((a == c) && (b > d)))
		return true;
	else
		return false;
}

bool integerPairs::operator>=(integerPairs&)
{
	int a, b, c, d;
	if ((a == c) && (b == d))
		return true;
	else if ((a > c) || ((a == c) && (b > d)))
		return true;
	else
		return false;
}

bool integerPairs::operator<(integerPairs&)
{
	int a, b, c, d;
	if ((a < c) || ((a == c) && (b < d)))
		return true;
	else
		return false;
}

bool integerPairs::operator<=(integerPairs&)
{
	int a, b, c, d;
	if ((a == c) && (b == d))
		return true;
	else if ((a < c) || ((a == c) && (b < d)))
		return true;
	else
		return false;
}

integerPairs* readFile(int nbLines)
{
	integerPairs *intArray = new integerPairs[nbLines];
	int counter = 0;
	int firstNumber, secondNumber;
	string line;
	stringstream stringNumber;

	ifstream myfile("InputNumbers.dat");
	while (getline(myfile, line))
	{
		istringstream iss(line);
		int a, b;
		iss >> a >> b;
		intArray[counter].value1 = a;
		intArray[counter].value2 = b;
		counter++;
	}
	cout << intArray[3].value1 << endl;
	return intArray;
}

integerPairs findMax(integerPairs* array, int n, int& x)
{
	integerPairs highest;
	integerPairs current;
	int startingNum = n;
	current = array[n];
	while (n > 0)
	{
		if(current > highest)
		{
			highest = current;
			x = n;
		}
		n--;
		current = array[n];
	}
	return highest;
}

void ourSort(integerPairs* array, int n)
{
	integerPairs i;	// i is the highest element
	int x;
	integerPairs temp;
	while (n > 0)
	{
		i = findMax(array, n, x);
		temp = i;
		i = array[n-1];
		array[n-1] = temp;
		n--;
	}
}

void ourSortTiming(int size)
{
	clock_t start, end;
	int totalTime;
	integerPairs* array;

	array = readFile(size);
	start = clock();
	ourSort(array, size);
	end = clock();

	totalTime = end - start;
	cout << "Total time: " << totalTime << endl;
}


int main()
{
	// int nbLines = 10;
	// int intArray = [];
	int nbLines = 40;
	generateFile();
	// integerPairs* myArray = readFile(nbLines);
	// int max = findMax(myArray, nbLines);
	// cout << max << endl;
	// ourSort(myArray, nbLines);
	// cout << intArray[2];
	ourSortTiming(nbLines);
}