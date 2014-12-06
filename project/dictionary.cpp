#include "dictionary.h"
#include <string>
#include <iostream>
#include <locale>	// toupper
#include <fstream>
#include <sstream>
using namespace std;

dictionary::dictionary(searchTree *n)
// constructor for dictionary
// creates object dict of class searchTree
{
	dict = n;
}

string dictionary::search(string word)
// uses searchTree search() to find a treeNode*
// if treeNode != NULL calls getWord() and getDef()
// 		from its dictEntry (data)
{
	string theWord, definition;
	word = makeCap(word);
	treeNode* entry = dict->search(word);
	if (entry == NULL)
		cout << "The word " << word << " was not found in the dictionary.\n";
	else
	{
		theWord = entry->data->getWord();
		definition = entry->data->getDefinition();
		cout << word << ": " << definition << endl;
	}
}

void dictionary::add(dictEntry entry)
// adds a dictEntry to the chosen tree by calling
// 		searchTree insert()
{
	cout << "made it into add()\n";
	searchTree *tree;
	cout << "initialized searchTree\n";
	tree->insert(entry);
	cout << "inserted dictEntry into tree\n";
}

void dictionary::remove(string word)
// calls searchTree remove() to remove dictEntry
//		containing word param from chosen tree
{
	searchTree *tree;
	tree->remove(word);
}

void dictionary::readFile(string filename)
// enters dictionary entries from filename param
//		file into chosen searchTree tree
{
	string line, word, definition;
	int endWord;
	ifstream dictionaryFile(filename.c_str());
	while (getline(dictionaryFile, line))
	{
		if (line.length() > 0)
		{
			endWord = line.find(':', 0);
			word = line.substr(0, endWord);
			definition = line.substr(word.length()+ 2);
			// istringstream iss(line);
			// iss >> word >> definition;
			cout << word << endl;
			cout << definition << endl;
			// for (int i = 0; i < word.length(); i++)
			// {
			// 	word[i] = word[i];
			// }
			// cout << word << endl;
			// dictEntry entry(word, definition);
			// cout << "dictEntry created successfully\n";
			// add(entry);
			// cout << "dictEntry added successfully to the dictionary\n";
		}
	}
}


string makeCap(string word)
// make the words capital for accurate string matching
{
	int i = 0;
	while (word[i] != '\0')
	{
		word[i] = toupper(word[i]);
	}
	return word;
}