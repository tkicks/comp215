#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

void reverseFile();
void swapLines();

int main()
{
	reverseFile();
	swapLines();
}

void reverseFile()
{
	// variables ====================
	int counter = 0;
	string line;
	stringstream stringNumber;
	ifstream myFile("barn.moo");
	ofstream myOutFile;
	myOutFile.open("reverse.dat");
	// ==============================
	
	int firstNum, secondNum, thirdNum;
	string word1, word2, word3, word4, word5, word6, word7;

	getline(myFile, line);
	istringstream iss(line);
	iss >> firstNum;
	myOutFile << "There are " << firstNum << " lines in this file.\n";

	// nbLines
	int nbLines = firstNum;

	int *intArray = new int[3*nbLines];

	while (getline(myFile, line))
	{
		istringstream iss(line);
		iss >> word1 >> firstNum >> word2 >> word3 >> secondNum >> word4 >> word5 >> word6 >> thirdNum >> word7;
		intArray[counter] = firstNum;
		counter++;
		intArray[counter] = secondNum;
		counter++;
		intArray[counter] = thirdNum;
		counter++;
	}

	int j = counter-1;
	while (j > 0)
	{
		thirdNum = intArray[j];
		secondNum = intArray[j-1];
		firstNum = intArray[j-2];
		myOutFile << firstNum << "," << secondNum << "," << thirdNum << "\n";
		j -= 3;
	}
}


void swapLines()
{
	int counter = 0;
	int firstNum, secondNum, thirdNum, fourthNum, fifthNum, sixthNum, nbLines;
	string line, word1, word2, word3, word4, word5, word6;
	stringstream stringNumber;
	ifstream myFile("reverse.dat");
	ofstream myOutFile;
	myOutFile.open("swap.dat");

	getline(myFile, line);
	istringstream iss(line);
	iss >> word1 >> word2 >> firstNum;
	nbLines = firstNum;
	myOutFile << "There are also " << firstNum << " lines in this file.\n";

	int *intArray = new int[3*nbLines];

	while(getline(myFile, line, ','))
	{
		cout << counter/3 << endl;
		istringstream iss(line);
		iss >> firstNum >> word1 >> secondNum >> word2 >> thirdNum;
		intArray[counter] = firstNum;
		counter++;
		intArray[counter] = secondNum;
		counter++;
		intArray[counter] = thirdNum;
		counter++;
	}

	int j = 0;
	while (j < counter-1)
	{
		sixthNum = intArray[j];
		fifthNum = intArray[j+1];
		fourthNum = intArray[j+2];
		thirdNum = intArray[j+3];
		secondNum = intArray[j+4];
		firstNum = intArray[j+5];
		myOutFile << "First integer: " << sixthNum << "Second integer: " << fifthNum << "Third integer: " << fourthNum << "\n" << "First integer: " << thirdNum << "Second integer: " << secondNum << "Third integer: " << firstNum << "\n";
		// myOutFile << "First integer: " << thirdNum << "Second integer: " << secondNum << "Third integer: " << firstNum << "\n";
		j -= 6;
	}
}