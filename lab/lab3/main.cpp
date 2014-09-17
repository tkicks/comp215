// Tyler Kickham

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

void generateFile();
int readFile(int nbLines);

class integerPairs
{
	private:
		int value1, value2;
	public:
		integerPairs(int a, int b);
		bool operator==(integerPairs&);
		bool operator>(integerPairs&);
		bool operator>=(integerPairs&);
		bool operator<(integerPairs&);
		bool operator<=(integerPairs&);
};

void generateFile()
{
	// commented out to avoid collecting 200,000,000 every time
	ofstream myfile;
	srand(time(NULL));
	myfile.open("InputNumbers.dat");
	int firstRand, secondRand;
	for (int i = 0; i < 1000; i++) {
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

int readFile(int nbLines)
{
	int* intArray = new int[2*nbLines];
	int counter = 0;
	string line;

	ifstream myfile("InputNumbers.dat");
	while (getline(myfile, line))
	{
		istringstream firstString(line[0]);
		istringstream secondString(line[2]);
		int firstNumber, secondNumber;

		firstString >> firstNumber;
		secondString >> secondNumber;

		intArray[counter] = firstNumber;
		counter++;
		intArray[counter] = secondNumber;
		counter++;
	}

	cout << intArray[0] << " " << intArray[1] << " " << intArray[3] << " " << intArray[4] << " " << intArray[5] << " " << intArray[6] << endl;

	return *intArray;
}


int main()
{
	// int nbLines = 100000000;
	// int intArray = [];
	generateFile();
	int array;
	array = readFile(1000);
	// intArray = readFile(nbLines);
	// cout << intArray[2];
}