// Tyler Kickham
//
// NOTE: The swapLines will work, just without the strings concatenated
//		 and the second line is a bit messed up. If it's couted it will
//		 display the correct numbers for the values, but when writing
//		 it's a bit messed up.
//		 The correct numbers are: 715727 476424 284794


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

void reverseFile();
void swapLines(int evens, int div3, int div5, int nbLines);

int main()
{
	reverseFile();
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
	int evens = 0;
	int div3 = 0;
	int div5 = 0;
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

		if(firstNum%2 == 0)
		{
			evens++;
		}
		if(firstNum%3 == 0)
		{
			div3++;
		}
		if(firstNum%5 == 0)
		{
			div5++;
		}
		if(secondNum%2 == 0)
		{
			evens++;
		}
		if(secondNum%3 == 0)
		{
			div3++;
		}
		if(secondNum%5 == 0)
		{
			div5++;
		}
		if(thirdNum%2 == 0)
		{
			evens++;
		}
		if(thirdNum%3 == 0)
		{
			div3++;
		}
		if(thirdNum%5 == 0)
		{
			div5++;
		}
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

	swapLines(evens, div3, div5, nbLines);
}


void swapLines(int evens, int div3, int div5, int nbLines)
{
	cout << "evens: " << evens << " div3: " << div3 << " div5: " << div5 << endl;

	int counter = 0;
	int insertHere = nbLines - 2;
	int firstNum, num1, num2, num3;
	string *intArray = new string[3*nbLines];
	string line, word1, word2, token;
	string delim = ",";
	size_t position = 0;


	ifstream myFile("reverse.dat");
	ofstream myOutFile;
	myOutFile.open("swap.dat");

	getline(myFile, line);
	istringstream iss(line);
	iss >> word1 >> word2 >> firstNum;
	nbLines = firstNum;
	myOutFile << "There are also " << firstNum << " lines in this file.\n";

	while(getline(myFile, line))
	{
		
		istringstream firstWord(line);
		firstWord >> word1;
		getline(myFile, line);
		istringstream secondWord(line);
		secondWord >> word2;
		swap(word1, word2);

		if (nbLines%2!=0 and counter == insertHere)
		{
			myOutFile << evens << " " << div3 << " " << div5 << endl << endl;
		}
		else
			myOutFile << word1 << endl << word2 << endl;

		counter += 2;
	}
}