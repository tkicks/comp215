#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <math.h>

using namespace std;

int numLines()
{
	readFileIn(1);
}


int readFileIn(int elemsPerLine)
{
	string filename, line;
	int nbLines;
	int counter = 0;

	cout << "Enter a file name: ";
	cin >> filename;

	char *char_filename = new char[filename.length()+1];
	strcpy(char_filename, filename.c_str());

	ifstream myFile(char_filename);

	getline(myFile, line);
	istringstream iss(line);
	iss >> nbLines;

	int *array = new int[nbLines];

	while (getline(myFile, line))
	{
		istringstream iss(line);
		iss >> a;
		array[counter] = a;
		counter++;
	}

	return 
}