#include <iostream>
#include <string>
#include "dictEntry.h"
#include "treeNode.h"
#include "searchTree.h"
#include "searchTreeNode.cpp"
#include "binarySearchTree.cpp"
#include "RBsearchTreeNode.cpp"
#include "dictionary.cpp"

using namespace std;

dictEntry::dictEntry(string w, string d)
// add a word and its definition to the dictionary
{
	word = w;
	definition = d;
}

string dictEntry::getWord()
// get the word value of the word the function is called on
{
	return this->word;
}

string dictEntry::getDefinition()
// get the definition of the word the function is called on
{
	return this->definition;
}

void dictEntry::updateDefinition(string def)
// update definition of a string
{
	this->definition = def;
}

bool dictEntry::operator==(string str)
// returns true if the strings are equal
{
	if (this->word.compare(str) == 0)
		return true;
	else
		return false;
}

bool dictEntry::operator>(string str)
// returns true if the value of the first nonmatching character
// is greater in the this->word or if this->word is longer
{
	if (this->word.compare(str) > 0)
		return true;
	else
		return false;
}

bool dictEntry::operator<(string str)
// returns true if the value of the first nonmatching character
// is lower in the this->word or if this->word is shorter
{
	if (this->word.compare(str) < 0)
		return true;
	else
		return false;
}

bool dictEntry::operator>=(string str)
// returns true if the value of the first nonmatching character
// is greater in the this->word or if this->word is longer or
// if the strings are equal
{
	if ((this->word.compare(str)) == 0 or (this->word.compare(str) > 0))
		return true;
	else
		return false;
}

bool dictEntry::operator<=(string str)
// returns true if the value of the first nonmatching character
// is lower in the this->word or if this->word is shorter or
// if the strings are equal
{
	if ((this->word.compare(str)) == 0 or (this->word.compare(str) < 0))
		return true;
	else
		return false;
}


int main() {
	// prevent errors compiling
}