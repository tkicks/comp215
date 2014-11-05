#include <iostream>
#include <string>
#include <math.h>

using namespace std;

template <class type>
type roundThis(type a, type b, type c)
// int(a) to ensure that all a values are int to % correctly
{
	a = round(a);
	return (int(a)%2==0?b:c);
}

template <class type>
class cell {
public:
	type value;
	cell() {};
	cell(type a)
	{
		value = a;
	}
};


int main()
{
	float a = 9.2, b = 1.41, c = 5.97, d;
	d = roundThis <float>(a, b, c);
	cout << d << endl;
	a = 8.2;
	d = roundThis <float>(a, b, c);
	cout << d << endl;

	int e = 12;
	// create a cell f
	cell <int>(f);
	// put int e as the value of cell f
	f = cell <int>(e);
	cout << f.value << endl;
}