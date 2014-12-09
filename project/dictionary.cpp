#include "dictEntry.cpp"
#include "treeNode.h"
#include "searchTree.h"
#include "searchTreeNode.cpp"
#include "binarySearchTree.cpp"
#include "RBsearchTreeNode.cpp"
#include "RBSearchTree.cpp"
#include "dictionary.h"
#include <string>
#include <iostream>
#include <locale>	// toupper
#include <fstream>
using namespace std;

dictionary::dictionary(searchTree *n)
// constructor for dictionary
// creates object dict of class searchTree
{
	this->dict = n;
}

dictionary::~dictionary()
// destructor for dictionary
// calls destructor on the tree then deletes itself
{
	// cout << "deleted dict\n";
}

void dictionary::search(string word)
// uses searchTree search() to find a treeNode*
// if treeNode != NULL calls getWord() and getDef()
// 		from its dictEntry (data)
{
	string theWord, definition;
	word = makeCap(word);
	treeNode *entry = dict->search(word);
	cout << "made treeNode\n";
	if (entry == NULL)
		cout << "The word " << word << " was not found in the dictionary.\n";
	else
	{
		cout << "entry not null\n";
		theWord = entry->data->getWord();
		definition = entry->data->getDefinition();
		cout << word << ": " << definition << endl;
	}
}

void dictionary::add(dictEntry *entry)
// adds a dictEntry to the chosen tree by calling
// 		searchTree insert()
{
	dict->insert(entry);
}

void dictionary::remove(string word)
// calls searchTree remove() to remove dictEntry
//		containing word param from chosen tree
{
	dict->remove(word);
}

void dictionary::readFile(string filename)
// enters dictionary entries from filename param
//		file into chosen searchTree tree
// endWord = index of ':' which signifies end WORD
// only stores lines that aren't blank (length() > 0)
{
	dictEntry *entry;
	int endWord;
	string line, word, definition;
	ifstream dictionaryFile(filename.c_str());
	while (getline(dictionaryFile, line))
	{
		if (line.length() > 0)
		{
			endWord = line.find(':', 0);
			word = line.substr(0, endWord);
			definition = line.substr(word.length()+ 2);
			cout << word << endl;
			cout << definition << endl;

			entry = new dictEntry(word, definition);
			add(entry);
		}
	}
}

void dictionary::writeFilePreorder(string filename)
// calls searchTree preOrder() file writing function
//		on filename parameter
{
	dict->preOrder(filename);
}

void dictionary::writeFileInorder(string filename)
// calls searchTree inOrder() file writing function
//		on filename parameter
{
	dict->inOrder(filename);
}

void dictionary::writeFilePostorder(string filename)
// calls searchTree postOrder() file writing function
//		on filename parameter
{
	dict->postOrder(filename);
}

string makeCap(string word)
// make the words capital for accurate string matching
{
	int i = 0;
	while (word[i] != '\0')
	{
		word[i] = toupper(word[i]);
		i++;
	}
	return word;
}

int main()
{
	dictEntry *entry;
	int whichTree, whichOption, whichOrder;
	string filename, newWord, newDefinition, wordToGet, removeWord;
	cout << "Binary Tree [1] or Red-Black [2] Tree? ";
	cin >> whichTree;
	if (whichTree == 1)
	{
		binarySearchTree tree;
		dictionary dict(&tree);
		do {
			cin.clear();
			cout << "Read [1], Add [2], Search [3], Remove [4], Save [5], Close [0]: ";
			cin >> whichOption;
			switch (whichOption) {
				case 1:
					cout << "Enter file name: ";
					cin >> filename;
					// dict.readFile("testEntries.txt");
					dict.readFile(filename);
					break;
				case 2:
					// in brackets so other tree doesn't cross define dictEntry entry
					{
						cout << "Enter word: ";
						cin >> newWord;
						newWord = makeCap(newWord);
						cout << "Enter definition: ";
						getline(cin.ignore(), newDefinition);
						entry = new dictEntry(newWord, newDefinition);
						dict.add(entry);
					}
					break;
				case 3:
					cout << "Enter word to search for: ";
					cin >> wordToGet;
					dict.search(wordToGet);
					break;
				case 4:
					cout << "Enter word to remove: ";
					cin >> removeWord;
					removeWord = makeCap(removeWord);
					dict.remove(removeWord);
					break;
				case 5:
					cout << "Preorder [1], Inorder [2], Postorder [3]: ";
					cin >> whichOrder;
					cout << "Enter filename: ";
					cin >> filename;
					switch (whichOrder) {
						case 1:
							dict.writeFilePreorder(filename);
							break;
						case 2:
							dict.writeFileInorder(filename);
							break;
						case 3:
							dict.writeFilePostorder(filename);
							break;
						default:
							cout << "Not a valid option\n";
					}
					break;
				case 0:
					cout << "successfully deleted everything\n";
					break;
				default:
					cout << "Invalid input.";
			}
		} while (whichOption != 0);
		// dict.readFile("testEntries.txt");
	}
	else if (whichTree == 2)
	{
		RBSearchTree tree;
		dictionary dict(&tree);
		do {
			cin.clear();
			cout << "Read [1], Add [2], Search [3], Remove [4], Save [5], Close [0]: ";
			cin >> whichOption;
			switch (whichOption) {
				case 1:
					cout << "Enter file name: ";
					cin >> filename;
					// dict.readFile("testEntries.txt");
					dict.readFile(filename);
					break;
				case 2:
					// in brackets so other tree doesn't cross define dictEntry entry
					{
						cout << "Enter word: ";
						cin >> newWord;
						newWord = makeCap(newWord);
						cout << "Enter definition: ";
						getline(cin.ignore(), newDefinition);
						entry = new dictEntry(newWord, newDefinition);
						dict.add(entry);
					}
					break;
				case 3:
					cout << "Enter word to search for: ";
					cin >> wordToGet;
					dict.search(wordToGet);
					break;
				case 4:
					cout << "Enter word to remove: ";
					cin >> removeWord;
					removeWord = makeCap(removeWord);
					dict.remove(removeWord);
					break;
				case 5:
					cout << "Preorder [1], Inorder [2], Postorder [3]: ";
					cin >> whichOrder;
					cout << "Enter filename: ";
					cin >> filename;
					switch (whichOrder) {
						case 1:
							dict.writeFilePreorder(filename);
							break;
						case 2:
							dict.writeFileInorder(filename);
							break;
						case 3:
							dict.writeFilePostorder(filename);
							break;
						default:
							cout << "Not a valid option\n";
					}
					break;
				case 0:
					cout << "successfully deleted everything\n";
					break;
				default:
					cout << "Invalid input.\n";
			}
		} while (whichOption != 0);
	}
	else
	{
		cout << "You broke me with invalid input.\nClosing dictionary.\n";
		return -1;
	}
}