// Tyler Kickham


#include <iostream>
#include <string>

using namespace std;


class monkey {
public:
	bool hungry;
	monkey();
	monkey(bool);
	~monkey() {cout << "\nmonkey destructor called.\n";}
	virtual void eatBanana();
	virtual void scratchHead();
	void swingFromTree();
};

class ape: public monkey {
public:
	ape();
	ape(bool);
	~ape() {cout << "\nape destructor called\n";}
	void eatBanana();
	virtual void scratchHead();
};

class parrot {
public:
	char *vocabulary;
	parrot();
	parrot(char *character);
	~parrot() {cout << "\nparrot destructor called\n";}
	void talk();
};

class human: public ape, public parrot {
public:
	human();
	human(bool newtorf);
	human(bool thirdtorf, char *newChar);
	~human() {cout << "\nhuman destructor called\n";}
	void eatBanana();
	void scratchHead();
};



// MAIN

int main() {
	monkey *m;
	ape *a;
	human *h;

	m = new ape(true);

	m->eatBanana();

	a = new human;

	delete m;
	m = a;

	m->scratchHead();

	a->scratchHead();

	m->eatBanana();

	a->eatBanana();

	h = dynamic_cast <human*>(a);

	delete h;
	h = new human(true, NULL);

	h->talk();

	delete h;
	h = new human(true);

	h = dynamic_cast <human*>(m);
	h->swingFromTree();

	delete a;
	a = new ape();
	a = dynamic_cast <ape*>(m);
	a->swingFromTree();
}






// Definitions

monkey::monkey()
{
	cout << "\ninside monkey() CTOR\n";
}

monkey::monkey(bool)
{
	cout << "\ninside monkey(bool) CTOR\n";
}

void monkey::eatBanana()
{
	cout << "\nmonkey is eating a banana\n";
}

void monkey::scratchHead()
{
	cout << "\nmonkey is scratching its head\n";
}

void monkey::swingFromTree()
{
	cout << "\nmonkey is swinging from tree\n";
}

ape::ape()
{
	cout << "\ninside ape() CTOR\n";
}

ape::ape(bool torf): monkey(torf)
{
	cout << "\ninside ape(bool) CTOR\n";
}

void ape::eatBanana() {
	cout << "\nape is eating a banana\n";
}

void ape::scratchHead()
{
	cout << "\nape is scratching its head\n";
}

parrot::parrot()
{
	cout << "\ninside parrot() CTOR\n";
}

parrot::parrot(char *character)
{
	cout << "\ninside parrot(char*) CTOR\n";
}

void parrot::talk()
{
	cout << "\nparrot is talking\n";
}

human::human()
{
	cout << "\ninside human CTOR\n";
}

human::human(bool newtorf): ape(newtorf)
{
	cout << "\ninside human(bool) CTOR\n";
}

human::human(bool thirdtorf, char *newChar): ape(thirdtorf), parrot(newChar)
{
	cout << "\ninside human(bool, char*) CTOR\n";
}

void human::eatBanana()
{
	cout << "\nhuman is eating a banana\n";
}

void human::scratchHead()
{
	cout << "\nhuman is scratching its head\n";
}