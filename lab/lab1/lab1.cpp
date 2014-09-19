#include <iostream>
#include <string>

using namespace std;

class cell {
	public:
		int value;
		cell *next;
		cell(int x);
		cell(int x, cell nextCell);
		cell(const cell& thisCell);
		cell operator+(cell cellTwo);
};

class queue {
	public:
		cell *first;
		cell *last;
		void pushLast(int x);
};


queue myQueue;

int main() {

	cell firstCell(3);
	cell *nextCell;
	cout << firstCell.value << "\n";

	cell secondCell(2, *nextCell);
	cout << secondCell.next << endl;

	cell thirdCell(firstCell);
	cout << thirdCell.value << "\t" << thirdCell.next << endl;

	cell fourthCell = firstCell + secondCell;
	cout << fourthCell.value << endl;

	myQueue.pushLast(2);
	cout << myQueue.last << "\n";
}

cell::cell(int x) {
	value = x;
}

cell::cell(int x, cell nextCell) {
	value = x;
	this->next = &nextCell;
}

cell::cell(const cell& thisCell) {
	this->value = thisCell.value;
	this->next = thisCell.next;
}

cell cell::operator+(cell cellTwo) {
	int values;
	values = this->value + cellTwo.value;
	cell fourthCell(values);
	return fourthCell;
}

void queue::pushLast(int x) {
	cell *toEnd;
	myQueue.last = toEnd;
}