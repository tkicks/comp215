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
int LomutoPartition(myItem* A, int l, int r);
void LomutoQuickSort(myItem* A, int l, int r);
void HoareQuickSort(myItem* A, int l, int r);
int HoarePartition(myItem* A, int l, int r);

int main()
{
	string filename, line, lineString;
	int a;
	int counter = 0;
	int nbLines = 5;
	int l = 0;

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

	// cout << "MergeSort\n";
	// MergeSort(array, nbLines);
	// cout << "\n\n\nLomutoQuickSort\n";
	// LomutoQuickSort(array, l, nbLines);
	cout << "\n\n\nHoareQuickSort\n";
	HoareQuickSort(array, l, nbLines);
	cout << "\n\n";
}

void MergeSort(myItem* original, int size)
{
	if (size > 1)
	{
		// allocate arrays
		int numFloor = floor((size/2));
		int numCeiling = size - numFloor;
		myItem *Left = new myItem[numFloor];
		myItem *Right = new myItem[numCeiling];

		// copy to left (B) and right (C)
		for (int i = 0; i < numFloor; i++)
		{
			Left[i] = original[i];
		}
		for (int j = numFloor, k = 0; j < size; j++, k++)
		{
			Right[k] = original[j];
		}

		// mergesort Left then Right
		MergeSort(Left, numFloor);
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
		cout << original[n].serialNumber << ", ";
	}
	cout << "\n";
}

void LomutoQuickSort(myItem* A, int l, int r)
{
	if (l < r)
	{
		int s = LomutoPartition(A, l, r);
		LomutoQuickSort(A, l, s-1);
		LomutoQuickSort(A, s+1, r);
	}

	for (int i = l; i < r; i++)
	{
		cout << A[i].serialNumber << ", ";
	}
	cout << "\n";
}

int LomutoPartition(myItem* A, int l, int r)
{
	int pivot = A[l].serialNumber;
	int s = l;
	for (int i = l+1; i < r; i++)
	{
		if (A[i].serialNumber < pivot)
		{
			s += 1;
			swap(A[s], A[i]);
		}
	}
	swap(A[l], A[s]);
	return s;
}

void HoareQuickSort(myItem* A, int l, int r)
{
	cout << "l: " << l << "\t\tr: " << r << "\n";
	if (l < r)
	{
		int s = HoarePartition(A, l, r);
		cout << "partitioned\n";
		HoareQuickSort(A, l, s-1);
		HoareQuickSort(A, s+1, r);
	}

	// for (int i = l; i < r; i++)
	// {
	// 	cout << A[i].serialNumber << ", ";
	// }
	cout << "\n";
}

int HoarePartition(myItem* A, int l, int r)
{
	int pivot = A[l].serialNumber;
	cout << "pivot: " << pivot << "\n";
	int i = l;
	int j = r+1;
	cout << "j: " << j << endl;
	do {
		do {
			i += 1;
			cout << "i: " << i << endl;
		} while (A[i].serialNumber <= pivot);
		do {
			j -= 1;
			cout << "j: " << j << endl;
		} while (A[j].serialNumber >= pivot);
		cout << "no swaps\n";
		swap(A[i], A[j]);
		cout << "one swap\n";
	} while (i < j);
	cout << "completed all dos\n";
	swap(A[i], A[j]);
	cout << "two swaps\n";
	swap(A[l], A[j]);
	cout << "three swaps\n";
	return j;
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