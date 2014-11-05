/*
	NOTE: To see sorted lists, use test.txt and change nbLines to 5, and
		  uncomment the cout statements in main
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;

class myItem {
	public:
		int serialNumber;
		string name;
		myItem() {};
		myItem(int sn, string s);
		bool operator==(myItem myObject[]);
		bool operator<(myItem myObject[]);
		bool operator<=(myItem myObject[]);
		bool operator>(myItem myObject[]);
		bool operator>=(myItem myObject[]);
		bool operator==(myItem myObject);
		bool operator<(myItem myObject);
		bool operator<=(myItem myObject);
		bool operator>(myItem myObject);
		bool operator>=(myItem myObject);
};

void MergeSort(myItem original[], int size);
void Merge(myItem Left[], myItem Right[], myItem original[], int sizeL, int sizeR);
int LomutoPartition(myItem A[], int l, int r);
void LomutoQuickSort(myItem A[], int l, int r);
void HoareQuickSort(myItem A[], int l, int r);
int HoarePartition(myItem A[], int l, int r);
void cMergeSort(myItem original[], int size);
void cMerge(myItem Left[], myItem Right[], myItem original[], int sizeL, int sizeR);
int cLomutoPartition(myItem A[], int l, int r);
void cLomutoQuickSort(myItem A[], int l, int r);
void cHoareQuickSort(myItem A[], int l, int r);
int cHoarePartition(myItem A[], int l, int r);

int count = 0;

int main()
{
	string filename, line, lineString;
	int a;
	int counter = 0;
	int nbLines = 30000;
	int l = 0;

	// file for MergeSort =================================
	cout << "Enter a file name to MergeSort: ";
	cin >> filename;
	if (filename == "")
	{
		exit(EXIT_FAILURE);
	}
	char* char_filenameM = new char[filename.length()+1];
	strcpy(char_filenameM, filename.c_str());
	ifstream myFileM(char_filenameM);
	myItem arrayM[nbLines];
	while (getline(myFileM, line))
	{
		istringstream iss(line);
		iss >> a >> lineString;
		arrayM[counter].serialNumber = a;
		arrayM[counter].name = lineString;
		counter++;
	}
	// end MergeSort file =================================

	counter = 0;
	// file for LomutoSort ================================
	cout << "Enter a file name to LomutoSort: ";
	cin >> filename;
	if (filename == "")
	{
		exit(EXIT_FAILURE);
	}
	char* char_filenameL = new char[filename.length()+1];
	strcpy(char_filenameL, filename.c_str());
	ifstream myFileL(char_filenameL);
	myItem arrayL[nbLines];
	while (getline(myFileL, line))
	{
		istringstream iss(line);
		iss >> a >> lineString;
		arrayL[counter].serialNumber = a;
		arrayL[counter].name = lineString;
		counter++;
	}
	// end LomutoSort file ================================

	counter = 0;
	// file for HoareSort =================================
	cout << "Enter a file name to HoareSort: ";
	cin >> filename;
	if (filename == "")
	{
		exit(EXIT_FAILURE);
	}
	char* char_filenameH = new char[filename.length()+1];
	strcpy(char_filenameH, filename.c_str());
	ifstream myFileH(char_filenameH);
	myItem arrayH[nbLines];
	while (getline(myFileH, line))
	{
		istringstream iss(line);
		iss >> a >> lineString;
		arrayH[counter].serialNumber = a;
		arrayH[counter].name = lineString;
		counter++;
	}
	// end HoareSort file =================================


	clock_t start, end;

	start = clock();
	MergeSort(arrayM, nbLines);
	end = clock();
	cout << "MergeSort\n";	
	// for (int i = 0; i < nbLines; i++)
	// {
	// 	cout << arrayM[i].serialNumber << ", ";
	// }
	cout << "\nMergeSort took " << (end - start) << " clock ticks.\n";

	start = clock();
	LomutoQuickSort(arrayL, l, nbLines);
	end = clock();
	cout << "\n\n\nLomutoQuickSort\n";
	// for (int i = 0; i < nbLines; i++)
	// {
	// 	cout << arrayL[i].serialNumber << ", ";
	// }
	cout << "\nLomutoQuickSort took " << (end - start) << " clock ticks.\n";

	start = clock();
	HoareQuickSort(arrayH, l, nbLines-1);
	end = clock();
	cout << "\n\n\nHoareQuickSort\n";
	// for (int i = 0; i < nbLines; i++)
	// {
	// 	cout << arrayH[i].serialNumber << ", ";
	// }
	cout << "\nHoareQuickSort took " << (end - start) << " clock ticks.\n";
	cout << "\n\n\n\n";

	
	cMergeSort(arrayM, nbLines);
	cout << "cMergeSort\n";	
	// for (int i = 0; i < nbLines; i++)
	// {
	// 	cout << arrayM[i].serialNumber << ", ";
	// }
	// cout << endl;
	cout << "made " << count << " comparisons\n";
	count = 0;

	cLomutoQuickSort(arrayL, l, nbLines);
	cout << "\n\n\ncLomutoQuickSort\n";
	// for (int i = 0; i < nbLines; i++)
	// {
	// 	cout << arrayL[i].serialNumber << ", ";
	// }
	// cout << endl;
	cout << "made " << count << " comparisons\n";
	count = 0;

	cHoareQuickSort(arrayH, l, nbLines-1);
	cout << "\n\n\ncHoareQuickSort\n";
	// for (int i = 0; i < nbLines; i++)
	// {
	// 	cout << arrayH[i].serialNumber << ", ";
	// }
	// cout << endl;
	cout << "made " << count << " comparisons\n";





	cout << "\n\ncompleted all sorts\n";
	cout << "\n\n";
	main();
}

void MergeSort(myItem original[], int size)
{
	if (size > 1)
	{
		// allocate arrays
		int numFloor = floor((size/2));
		int numCeiling = size - numFloor;
		myItem Left[numFloor];
		myItem Right[numCeiling];

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

void Merge(myItem Left[], myItem Right[], myItem original[], int sizeL, int sizeR)
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
}

void cMergeSort(myItem original[], int size)
{
	if (size > 1)
	{
		count++;
		// allocate arrays
		int numFloor = floor((size/2));
		int numCeiling = size - numFloor;
		myItem Left[numFloor];
		myItem Right[numCeiling];

		// copy to left (B) and right (C)
		for (int i = 0; i < numFloor; i++)
		{
			count++;
			Left[i] = original[i];
		}
		count++;
		for (int j = numFloor, k = 0; j < size; j++, k++)
		{
			count++;
			Right[k] = original[j];
		}
		count++;

		// mergesort Left then Right
		cMergeSort(Left, numFloor);
		cMergeSort(Right, numCeiling);
		cMerge(Left, Right, original, numFloor, numCeiling);
	}
	count++;
}

void cMerge(myItem Left[], myItem Right[], myItem original[], int sizeL, int sizeR)
{
	int i = 0;	// how far in Left
	int j = 0;	// how far in Right
	int k = 0;	// how far in original

	// while loop
	while ((i < sizeL) and (j < sizeR))
	{
		count += 3;
		if (Left[i] <= Right[j])
		{
			count++;
			original[k] = Left[i];
			i++;
		}
		else
		{
			count++;
			original[k] = Right[j];
			j++;
		}
		k++;
	}
	count += 3;
	if (i == sizeL)
	{
		count++;
		for (; j < sizeR; j++, k++)
		{
			count++;
			original[k] = Right[j];
		}
	}
	else
	{
		count++;
		for (; i < sizeL; i++, k++)
		{
			count++;
			original[k] = Left[i];
		}
	}
}

void LomutoQuickSort(myItem A[], int l, int r)
{
	if (l < r)
	{
		int s = LomutoPartition(A, l, r);
		LomutoQuickSort(A, l, s-1);
		LomutoQuickSort(A, s+1, r);
	}
}

int LomutoPartition(myItem A[], int l, int r)
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

void cLomutoQuickSort(myItem A[], int l, int r)
{
	if (l < r)
	{
		count++;
		int s = cLomutoPartition(A, l, r);
		cLomutoQuickSort(A, l, s-1);
		cLomutoQuickSort(A, s+1, r);
	}
	count++;
}

int cLomutoPartition(myItem A[], int l, int r)
{
	int pivot = A[l].serialNumber;
	int s = l;
	for (int i = l+1; i < r; i++)
	{
		count++;
		if (A[i].serialNumber < pivot)
		{
			count++;
			s += 1;
			swap(A[s], A[i]);
		}
		count++;
	}
	count++;
	swap(A[l], A[s]);
	return s;
}

void HoareQuickSort(myItem A[], int l, int r)
{
	if (l < r)
	{
		int s = HoarePartition(A, l, r);
		HoareQuickSort(A, l, s-1);
		HoareQuickSort(A, s+1, r);
	}
}

int HoarePartition(myItem A[], int l, int r)
{
	myItem pivot;

	if (A[l] < A[r]) 
    {
        pivot = A[l] ;
    } 
    else
    {
        swap(A[l],  A[r]) ;
        pivot = A[l] ;
    } 
	int i = l;
	int j = r+1;

	do {
		do {
			i += 1;
		} while (A[i] < pivot);
		do {
			j -= 1;
		} while (A[j] > pivot);
		swap(A[i], A[j]);
	} while (i < j);

	swap(A[i], A[j]);
	swap(A[l], A[j]);
	return j;
}

void cHoareQuickSort(myItem A[], int l, int r)
{
	if (l < r)
	{
		count++;
		int s = cHoarePartition(A, l, r);
		cHoareQuickSort(A, l, s-1);
		cHoareQuickSort(A, s+1, r);
	}
	count++;
}

int cHoarePartition(myItem A[], int l, int r)
{
	myItem pivot;

	if (A[l] < A[r]) 
    {
    	count++;
        pivot = A[l] ;
    } 
    else
    {
    	count++;
        swap(A[l],  A[r]) ;
        pivot = A[l] ;
    } 
	int i = l;
	int j = r+1;

	do {
		count++;

		do {
			count++;
			i += 1;
		} while (A[i] < pivot);

		do {
			count++;
			j -= 1;
		} while (A[j] > pivot);

		swap(A[i], A[j]);
	} while (i < j);
	count++;

	swap(A[i], A[j]);
	swap(A[l], A[j]);
	return j;
}

myItem::myItem(int sn, string s)
{
	serialNumber = sn;
	name = s;
}

bool myItem::operator==(myItem myObject[])
{
	int a, b;
	a = this->serialNumber;
	b = myObject->serialNumber;
	if (a == b)
		return true;
	else
		return false;
}
		
bool myItem::operator<(myItem myObject[])
{
	int a, b;
	a = this->serialNumber;
	b = myObject->serialNumber;
	if (a < b)
		return true;
	else
		return false;
}

bool myItem::operator<=(myItem myObject[])
{
	int a, b;
	a = this->serialNumber;
	b = myObject->serialNumber;
	if (a <= b)
		return true;
	else
		return false;
}

bool myItem::operator>(myItem myObject[])
{
	int a, b;
	a = this->serialNumber;
	b = myObject->serialNumber;
	if (a > b)
		return true;
	else
		return false;
}

bool myItem::operator>=(myItem myObject[])
{
	int a, b;
	a = this->serialNumber;
	b = myObject->serialNumber;
	if (a >= b)
		return true;
	else
		return false;
}

bool myItem::operator==(myItem myObject)
{
	int a, b;
	a = this->serialNumber;
	b = myObject.serialNumber;
	if (a == b)
		return true;
	else
		return false;
}
		
bool myItem::operator<(myItem myObject)
{
	int a, b;
	a = this->serialNumber;
	b = myObject.serialNumber;
	if (a < b)
		return true;
	else
		return false;
}

bool myItem::operator<=(myItem myObject)
{
	int a, b;
	a = this->serialNumber;
	b = myObject.serialNumber;
	if (a <= b)
		return true;
	else
		return false;
}

bool myItem::operator>(myItem myObject)
{
	int a, b;
	a = this->serialNumber;
	b = myObject.serialNumber;
	if (a > b)
		return true;
	else
		return false;
}

bool myItem::operator>=(myItem myObject)
{
	int a, b;
	a = this->serialNumber;
	b = myObject.serialNumber;
	if (a >= b)
		return true;
	else
		return false;
}
