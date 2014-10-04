#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <algorithm>	// for swap()

using namespace std;


class pairsAgain
{
	public:
		int val1, val2;
		pairsAgain() {};
		pairsAgain(int int1, int int2);
		bool operator==(pairsAgain&);
		bool operator>(pairsAgain&);
		bool operator>=(pairsAgain&);
		bool operator<(pairsAgain&);
		bool operator<=(pairsAgain&);
};

void fileType();
void openFileNum();
void openFileText();
void whichSearchNum(pairsAgain* myArray, int nbLines);
void selectionSort(pairsAgain* myArray, int nbLines);
void bubbleSort(pairsAgain* myArray, int nbLines);
void sequentialSearch(pairsAgain* myArray, int nbLines);
void stringMatching(char* newString, int nbLines);



int main()
{
	fileType();
}



void fileType()
{
	string response;

	cout << "Will you be using numbers or text? ";
	cin >> response;
	if (response == "numbers")
	{
		openFileNum();
	}
	else if (response == "text")
	{
		openFileText();
	}
	else
	{
		cout << "Wrong. Ending.\n";
	}
}



// Chose a number
void openFileNum()
{
	string response, line;
	int a, b, nbLines, counter;

	cout << "Enter file name: ";
	cin >> response;


	char *c_response = new char[response.length()+1];
	strcpy(c_response, response.c_str());


	ifstream myfile(c_response);

	getline(myfile, line);
	istringstream iss(line);
	iss >> a;
	nbLines = a;
	counter = 0;

	pairsAgain *intArray = new pairsAgain[nbLines];

	while (getline(myfile, line))
	{
		istringstream iss(line);
		iss >> a >> b;
		intArray[counter] = pairsAgain(a, b);
		counter++;
	}
	cout << intArray[3].val1 << endl;

	whichSearchNum(intArray, nbLines);

}

void whichSearchNum(pairsAgain* myArray, int nbLines)
{
	string response, line;
	int a, b, counter;

	cout << "Selection, Bubble, or Sequential? ";
	cin >> response;

	if (response == "Selection" or response == "selection")
	{
		selectionSort(myArray, nbLines);
	}
	else if (response == "Bubble" || response == "bubble")
	{
		bubbleSort(myArray, nbLines);
	}
	else if (response == "Sequential" || response == "sequential")
	{
		sequentialSearch(myArray, nbLines);
	}
	else
		cout << "error\n";
}

void selectionSort(pairsAgain* myArray, int nbLines)
{
	int i, j, min, tempA, tempB;
	pairsAgain* temp;
	string response;

	cout << "Enter output filename: ";
	cin >> response;

	char *c_response = new char[response.length()+1];
	strcpy(c_response, response.c_str());

	ofstream myfile;
	myfile.open(c_response);

	for (i = 0; i < nbLines-2; i++)
	{
		min = i;
		for (j = i+1; j < nbLines-1; j++)
		{
			if (myArray[j] < myArray[min])
			{
				min = j;
			}
		}

		swap(myArray[i], myArray[min]);
	}

	for (i = 0; i < nbLines; i++)
		myfile << myArray[i].val1 << " " << myArray[i].val2 << "\n";
}

void bubbleSort(pairsAgain* myArray, int nbLines)
{
	int i, j, nbSwap;
	string response;

	cout << "Enter output filename: ";
	cin >> response;

	char *c_response = new char[response.length()+1];
	strcpy(c_response, response.c_str());

	ofstream myfile;
	myfile.open(c_response);

	for (i = 0; i < nbLines-1; i++)
	{
		nbSwap = 0;
		for (j = 0; j < nbLines-i-1; j++)
		{
			if (myArray[j] > myArray[j+1])
			{
				swap(myArray[j], myArray[j+1]);
				nbSwap++;
			}
		}
		if (nbSwap == 0)
			break;
	}

	for (i = 0; i < nbLines; i++)
		myfile << myArray[i].val1 << " " << myArray[i].val2 << "\n";
}

void sequentialSearch(pairsAgain* myArray, int nbLines)
{
	int i, searchValue;
	bool hasValue = true;

	while (hasValue == true)
	{
		cout << "Enter a value to search for: ";
		cin >> searchValue;
		cin.ignore();
		for (i = 0; i < nbLines; i++)
		{
			if (myArray[i].val1 == searchValue)
			{
				hasValue = true;
				break;
			}
			else
			{
				cout << "Searched " << i+2 << " values.\n";
				hasValue = false;
			}
		}
	}
	cout << "Value not in file.\n";
}

// ============================================================================


// Chose a text ===============================================================
void openFileText()
{
	string response, line;
	int a, nbLines;

	cout << "Enter file name: ";
	cin >> response;


	char *c_response = new char[response.length()+1];
	strcpy(c_response, response.c_str());


	ifstream myfile(c_response);

	getline(myfile, line);
	istringstream iss(line);
	iss >> a;
	nbLines = a;

	char newString[15000];
	char newLine[15000];

	while (getline(myfile, line))
	{
		strcpy(newLine, line.c_str());
		strcat(newString, newLine);
	}
	
	cout << newString << endl;

	stringMatching(newString, nbLines);
}

void stringMatching(char* newString, int nbLines)
{
	string response;
	int m, j;

	cout << "Enter string to find: ";
	cin >> response;
	m = response.length();


	char *c_response = new char[response.length()+1];
	strcpy(c_response, response.c_str());

	for (int i = 0; i < nbLines-m; i++)
	{
		j = 0;
		while ((j < m) and (c_response[j] == newString[i+j]))
		{
			j += 1;
		}
		if (j == m)
		{
			cout << "Found at index: " << j << endl;
			stringMatching(newString, nbLines);
		}
	}
	cout << "Not found\n";
}





pairsAgain::pairsAgain(int int1, int int2)
{
	val1 = int1;
	val2 = int2;
}


bool pairsAgain::operator==(pairsAgain& myArray)
{
	int a, c;
	a = this->val1;
	c = myArray.val1;
	if (a == c)
		return true;
	else
		return false;
}

bool pairsAgain::operator>(pairsAgain& myArray)
{
	int a, c;
	a = this->val1;
	c = myArray.val1;
	if (a > c)
		return true;
	else
		return false;
}

bool pairsAgain::operator>=(pairsAgain& myArray)
{
	int a, c;
	a = this->val1;
	c = myArray.val1;
	if (a >= c)
		return true;
	else
		return false;
}

bool pairsAgain::operator<(pairsAgain& myArray)
{
	int a, c;
	a = this->val1;
	c = myArray.val1;
	if (a < c)
		return true;
	else
		return false;
}

bool pairsAgain::operator<=(pairsAgain& myArray)
{
	int a, c;
	a = this->val1;
	c = myArray.val1;
	if (a <= c)
		return true;
	else
		return false;
}