/*
Author: Tyler Kickham
NOTE: I commented out the function calls that are not in use
	  Currently commented out is the results, running will show clock
	  ticks.

5. Results: 4483, seg fault, seg fault, seg fault
   The stack overflows and results in segmentation faults for the tests
   above 25000.
6. Clock ticks: 17,075,431 - 15,810,986 - 13,986 - 10,087
7. Noticeable difference between expmod3 (13,986) and expmod4(10,087)
   bigTime()s not run
*/
#include <iostream>
#include <time.h>

using namespace std;

unsigned long expmod1(unsigned long b, unsigned long n, unsigned long m);
unsigned long expmod2(unsigned long b, unsigned long n, unsigned long m);
unsigned long expmod3(unsigned long b, unsigned long n, unsigned long m);
unsigned long expmod4(unsigned long b, unsigned long n, unsigned long m);
void time1();
void time2();
void time3();
void time4();
bool tester(unsigned long b, unsigned long m);

unsigned long b = 21415;
unsigned long n = 25000;
unsigned long m = 31457;

int main() {
	unsigned long results;
	bool testBool = true;
	
	if (b > m) {
		b = b%m;
	}
	testBool = tester(b, m);

	if (testBool) {

		clock_t start, end;

		start = clock();
		time1();
		end = clock();
		cout << "The computation took " << (end - start) << " clock ticks.\n";

		start = clock();
		time2();
		end = clock();
		cout << "The computation took " << (end - start) << " clock ticks.\n";

		start = clock();
		time3();
		end = clock();
		cout << "The computation took " << (end - start) << " clock ticks.\n";

		start = clock();
		time4();
		end = clock();
		cout << "The computation took " << (end - start) << " clock ticks.\n";

		// results = expmod1(b, n, m);
		// cout << results << endl;

		// results = expmod2(b, n, m);
		// cout << results << endl;

		// results = expmod3(b, n, m);
		// cout << results << endl;

		// results = expmod4(b, n, m);
		// cout << results << endl;
	}
	else {
		cout << "Base too small or modulo too large\n";
	}
}


unsigned long expmod1(unsigned long b, unsigned long n, unsigned long m) {
	//cout << b << " " << n << " " << m << endl;
	if (n <= 0) {
		return 1;
	}
	else {
		//cout << n << endl;
		return (b*(expmod1(b, n-1, m))%m);
	}
}

unsigned long expmod2(unsigned long b, unsigned long n, unsigned long m) {
	unsigned long result = 1;
	while (n > 0) {
		result = (result * b) % m;
		n -= 1;
	}
	return result;
}

unsigned long expmod3(unsigned long b, unsigned long n, unsigned long m) {

	if (n == 0) {
		return 1;
	}
	else {
		if (n%2 != 0) {
			return (b*(expmod3(b, n-1, m))%m);
		}
		else {
			return (expmod3((b*b)%m, (n*0.5), m));
		}
	}
}

unsigned long expmod4(unsigned long b, unsigned long n, unsigned long m) {
	unsigned long result = 1;
	unsigned long base = b;
	unsigned long exponent = n;

	while (exponent != 0) {
		if (exponent % 2 != 0) {
			result = ((result * base)%m);
			exponent -= 1;
		}
		else {
			base = ((base * base)%m);
			exponent = exponent/2;
		}
	}
	return result;
}

void time1() {
int numTimes = 50000;
	while (numTimes >= 0) {
		expmod1(b, n, m);
		numTimes -= 1;
	}
}

void time2() {
int numTimes = 50000;
	while (numTimes >= 0) {
		expmod2(b, n, m);
		numTimes -= 1;
	}
}

void time3() {
int numTimes = 50000;
	while (numTimes >= 0) {
		expmod3(b, n, m);
		numTimes -= 1;
	}
}

void time4() {
int numTimes = 50000;
	while (numTimes >= 0) {
		expmod4(b, n, m);
		numTimes -= 1;
	}
}

bool tester(unsigned long b, unsigned long m) {
	if (b <= 1 || m > 65536) {
		return false;
	}
}