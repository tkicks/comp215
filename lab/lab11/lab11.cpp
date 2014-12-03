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

void ChangeMaking(int n)
{
	int j, newminsofar, F[n+1];
	changeStruct counter;

	F[0] = 0;
	for (int i = 0; i < n+1; i++)
	{
		counter.minsofar = i;
		j = 0;
		while (j < m && D[j] <= i)
		{
			newminsofar = min(counter.minsofar, F[i-D[j]]+1);
			if (newminsofar < counter.minsofar)
			{
				counter.minsofar = newminsofar;
				for (int l = m-1; l >= 0; l--)
				{
					while (n - D[l] >= 0)
					{
						counter.numberEach[l]++;
						n -= D[l];
					}
				}
			}
			j++;
		}
		F[i] = counter.minsofar;
	}
	cout << "minsofar = " << counter.minsofar << endl;
	cout << counter.numberEach[0] << " 1 cent coins\n";
	cout << counter.numberEach[1] << " 7 cent coins\n";
	cout << counter.numberEach[2] << " 30 cent coins\n";
	cout << counter.numberEach[3] << " 84 cent coins\n";
	cout << counter.numberEach[4] << " 235 cent coins\n";
}