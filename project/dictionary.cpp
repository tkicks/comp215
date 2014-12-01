#include "dictionary.h"
#include <string>
#include <iostream>
#include <locale>	// toupper
using namespace std;

dictionary::dictionary(searchTree *n)
{
	dict = n;
}

string dictionary::search(string word)
{
	string theWord, definition;
	word = makeCap(word);
	treeNode* entry = dict->search(word);
	if (entry == NULL)
		cout << "The word " << word << " was not found in the dictionary.\n";
	else
	{
		theWord = entry->getword();
		definition = entry->getDefinition();
		cout << word << ": " << definition << endl;
	}
}





string makeCap(string word)
{
	int i = 0;
	while (word[i] != "\0")
	{
		word[i] = word[i].toupper();
	}
	return word;
}