#include <iostream>
using namespace std;


void ChangeMaking(int n);

class changeStruct {
	public:
		int minsofar, *numberEach;
		changeStruct();
};

int D[] = {1, 7, 30, 84, 235};
int m = 5;	// number of coins

int main()
{
	// cin.clear();
	int input;
	do {
		cout << "Enter change to make: ";
		cin >> input;
		ChangeMaking(input);
	} while (input >= 0 && cin);

	if (!cin) {
		cout << "That wasn't a number.\n";
		// main();
	}
	else
		cout << "Done.\n";
}

changeStruct::changeStruct()
{
	minsofar = 0;
	numberEach = new int[m];
	for (int i = 0; i < m; i++)
		numberEach[i] = 0;
}

// void ChangeMaking(int n)
// {
// 	int j;
// 	changeStruct counter, F[n+1];

// 	for (int i = 0; i < n+1; i++)
// 	{
// 		while (j < 5 && i >= D[j])
// 		{
// 			if (F[i-D[j]].minsofar+1 < counter.minsofar)
// 			{
// 				counter.minsofar = F[i-D[j]].minsofar+1;
// 				for (int z = 0; z < m; z++)
// 				{
// 					if (z != j)
// 						counter.numberEach[z] = F[i-D[j]].numberEach[z];
// 					else
// 						counter.numberEach[z] = F[i-D[j]].numberEach[z] + 1;
// 				}
// 			}
// 			j++;
// 		}
// 		F[i] = counter;
// 	}
// 	cout << "minsofar = " << counter.minsofar << endl;
// 	cout << counter.numberEach[0] << " 1 cent coins\n";
// 	cout << counter.numberEach[1] << " 7 cent coins\n";
// 	cout << counter.numberEach[2] << " 30 cent coins\n";
// 	cout << counter.numberEach[3] << " 84 cent coins\n";
// 	cout << counter.numberEach[4] << " 235 cent coins\n";
// }

void ChangeMaking(int n)
{
	int j, newminsofar;
	changeStruct F[n+1];
	changeStruct counter;

	for (int i = 0; i < n+1; i++)
	{
		counter.minsofar = i;
		j = 0;
		while (j < m && i >= D[j])
		{
			if (F[i-D[j]].minsofar+1 < counter.minsofar)
			{
				counter.minsofar = F[i-D[j]].minsofar+1;
				for (int z = 0; z < m; z++)
				{
					if (z != j)
					{
						counter[z].numberEach = F[i-D[j]].minsofar;
					}
					else
						counter[z].numberEach = F[i-D[j]].minsofar+1;
				}
			}
			j++;
		}
		F[i].minsofar = counter.minsofar;
	}
	cout << "minsofar = " << counter.minsofar << endl;
	cout << counter.numberEach[0] << " 1 cent coins\n";
	cout << counter.numberEach[1] << " 7 cent coins\n";
	cout << counter.numberEach[2] << " 30 cent coins\n";
	cout << counter.numberEach[3] << " 84 cent coins\n";
	cout << counter.numberEach[4] << " 235 cent coins\n";
}