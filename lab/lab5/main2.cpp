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
	int nbLines, firstNum;
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

		while((position = word1.find(delim)) != word1.npos)
		{
			token = word1.substr(0, position);
			intArray[counter] = token;
			counter++;
			word1.erase(0, position + delim.length());
		}
		myOutFile << "First integer: " << intArray[counter-2] << "Second integer: " << intArray[counter-1] << "Third integer: " << intArray[counter] << "\n";
		counter += 3;

		while((position = word2.find(delim)) != word2.npos)
		{
			token = word2.substr(0, position);
			intArray[counter] = token;
			counter++;
			word1.erase(0, position + delim.length());
		}
		myOutFile << "First integer: " << intArray[counter-2] << "Second integer: " << intArray[counter-1] << "Third integer: " << intArray[counter] << "\n";
		counter += 3;
	}
}