#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <math.h>

using namespace std;

class myItem {
	public:
		int serialNumber;
		string name;
		myItem() {};
		myItem(int sn, string s);
		bool operator==(myItem&);
		bool operator<(myItem&);
		bool operator<=(myItem&);
		bool operator>(myItem&);
		bool operator>=(myItem&);
};

void MergeSort(myItem* original, int size);
void Merge(myItem* Left, myItem* Right, myItem* original, int sizeL, int sizeR);

int main()
{
	string filename, line, lineString;
	int a;
	int counter = 0;
	int nbLines = 5;

	cout << "Enter a file name: ";
	cin >> filename;

	char *char_filename = new char[filename.length()+1];
	strcpy(char_filename, filename.c_str());

	ifstream myFile(char_filename);

	myItem *array = new myItem[nbLines];

	while (getline(myFile, line))
	{
		istringstream iss(line);
		iss >> a >> lineString;
		array[counter].serialNumber = a;
		array[counter].name = lineString;
		counter++;
	}

	MergeSort(array, nbLines);
}

void MergeSort(myItem* original, int size)
{
	if (size > 1)
	{
		// allocate arrays
		int numFloor = floor((size/2));
		int numCeiling = ceil((size/2));
		myItem *Left = new myItem[numFloor];
		myItem *Right = new myItem[numCeiling];

		// copy to left (B) and right (C)
		for (int i = 0; i < numFloor-1; i++)
		{
			Left[i] = original[i];
		}
		for (int j = numFloor; j = size-1; j++)
		{
			Right[j] = original[j];
		}

		// mergesort Left then Right
		MergeSort(Left, numFloor);
		cout << "merged left\n";
		MergeSort(Right, numCeiling);
		Merge(Left, Right, original, numFloor, numCeiling);
	}
}

void Merge(myItem* Left, myItem* Right, myItem* original, int sizeL, int sizeR)
{
	int i = 0;	// how far in Left
	int j = 0;	// how far in Right
	int k = 0;	// how far in original

	// while loop
	while ((i < sizeL) and (j < sizeR))
	{
		if (Left[i] <= Right[j])
		{
			original[k] = Left[i];
			i++;
		}
		else
		{
			original[k] = Right[j];
			j++;
		}
		k++;
	}
	if (i == sizeL)
	{
		for (; j < sizeR; j++, k++)
		{
			original[k] = Right[j];
		}
	}
	else
	{
		for (; i < sizeL; i++, k++)
		{
			original[k] = Left[i];
		}
	}

	for (int n = 0; n < (sizeL + sizeR); n++)
	{
		cout << original[n].serialNumber << endl;
	}
}

myItem::myItem(int sn, string s)
{
	serialNumber = sn;
	name = s;
}

bool myItem::operator==(myItem& myObject)
{
	int a, b;
	a = this->serialNumber;
	b = myObject.serialNumber;
	if (a == b)
		return true;
	else
		return false;
}
		
bool myItem::operator<(myItem& myObject)
{
	int a, b;
	a = this->serialNumber;
	b = myObject.serialNumber;
	if (a < b)
		return true;
	else
		return false;
}

bool myItem::operator<=(myItem& myObject)
{
	int a, b;
	a = this->serialNumber;
	b = myObject.serialNumber;
	if (a <= b)
		return true;
	else
		return false;
}

bool myItem::operator>(myItem& myObject)
{
	int a, b;
	a = this->serialNumber;
	b = myObject.serialNumber;
	if (a > b)
		return true;
	else
		return false;
}

bool myItem::operator>=(myItem& myObject)
{
	int a, b;
	a = this->serialNumber;
	b = myObject.serialNumber;
	if (a >= b)
		return true;
	else
		return false;
}