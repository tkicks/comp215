#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <math.h>

using namespace std;

void InsertionSort(int* array, int size);
void BinarySearch(int* array, int size, int element);

int main()
{
	string filename, line;
	int a, nbLines;
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

	InsertionSort(array, nbLines);
}


void InsertionSort(int* array, int size)
{
	int v, j;
	for (int i = 1; i < size; i++)
	{
		v = array[i];
		j = i-1;
		while ((j >= 0) and (array[j] > v))
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = v;
	}



	for (int ij = 0; ij < size; ij++)
	{
		cout << array[ij] << ", ";
	}

	cout << endl;

	BinarySearch(array, size, 0);
}


void BinarySearch(int* array, int size, int element)
{
	bool inArray = true;
	bool found = false;
	// l = left
	// r = right
	// m = middle
	int l, r, m;
	while (inArray)
	{
		found = false;
		cout << "Search for: ";
		cin >> element;

		l = 0;
		r = size-1;
		while ((l <= r) and (found == false))
		{
			m = floor((l+r)/2);
			if (element == array[m])
			{
				cout << "Found at index " << m << endl;
				found = true;
			}
			else if (element < array[m])
			{
				r = m-1;
			}
			else
			{
				l = m+1;
			}
		}

		if (found == false)
		{
			cout << "Not found\n";
			inArray = false;
		}
	}
}