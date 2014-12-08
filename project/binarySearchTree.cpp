/*
TODO: successor in remove()
*/

#include "binarySearchTree.h"
#include <iostream>
#include <queue>
using namespace std;

binarySearchTree::binarySearchTree()
// init the tree with a NULL root
{
	root = NULL;
}

binarySearchTree::~binarySearchTree()
{
	destroy_tree(root);
}


void binarySearchTree::destroy_tree(searchTreeNode *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete(leaf);
	}
}

void binarySearchTree::insert(dictEntry *in)
// insert a dictEntry into the binary search tree
{
	// searchTreeNode *root = this->root;
	if (root == NULL)
		root = new searchTreeNode(in);
	else
		insert_h(in, root);
}

void binarySearchTree::insert_h(dictEntry *in, searchTreeNode *current)
// inserts a dictEntry into the binary search tree if
// there's already a root entry
{
	if (*(in) == current->data->getWord())
		return;
	else if (*(in) < current->data->getWord())
	{
		if (current->left == NULL)
			current->left = new searchTreeNode(in, current);
		else
			insert_h(in, current->left);
	}
	else
	{
		if (current->right == NULL)
			current->right = new searchTreeNode(in, current);
		else
			insert_h(in, current->right);
	}
}

searchTreeNode* binarySearchTree::search(string w)
// search for string w in tree and remove
// dictEntry with word == w
{
	return search_h(w, root);
}

searchTreeNode* binarySearchTree::search_h(string w, searchTreeNode *current)
// searches for string w in tree and removes
// dictEntry with word == w
// does the work for search()
{
	if (*(current->data) == w)
	{
		cout << w << " is the same as " << current->data->getWord() << endl;
		return current;
	}
	else if (*(current->data) > w)
	{
		cout << w << " is before " << current->data->getWord() << endl;
		if (current->left != NULL)
			return search_h(w, current->left);
		else
			return NULL;
	}
	else if (*(current->data) < w)
	{
		cout << w << " is after " << current->data->getWord() << endl;
		if (current->right != NULL)
			return search_h(w, current->right);
		else
			return NULL;
	}
	else
		return NULL;
}	

void binarySearchTree::remove(string w)
// actually does the removing and restructuring of the tree
// dictEntry with word == w
{
	searchTreeNode* toDelete = search(w);
	if (toDelete != NULL)
	{
		if (toDelete->parent != NULL)
		{
			if (toDelete->left == NULL)
			{
				if (toDelete == toDelete->parent->left)
				{
					toDelete->parent->left = toDelete->right;
					delete toDelete;
				}
				else
				{
					toDelete->parent->right = toDelete->right;
					delete toDelete;
				}
			}
			else if (toDelete->right == NULL)
			{
				if (toDelete == toDelete->parent->left)
				{
					toDelete->parent->left = toDelete->left;
					delete toDelete;
				}
				else
				{
					toDelete->parent->right = toDelete->left;
					delete toDelete;
				}
			}
			else
			{
				// searchTreeNode* toDeleteSucc = toDelete->successor(toDelete);
				// toDelete->definition = toDeleteSucc->definition;
				if (toDelete == toDelete->parent->left)
				{
					toDelete->parent->left = toDelete->right;
					delete toDelete;
				}
				else
				{
					toDelete->parent->right = toDelete->right;
					delete toDelete;
				}
			}
		}
	}
}

void binarySearchTree::preOrder(string filename)
// calls protected helper function to visit nodes
// protected b/c don't want people messing w/ order
// 		or else new tree will be messed up
{
	char* c_file;
	strcpy(c_file, filename.c_str());
	fout.open(c_file, ofstream::out);
	preorder_h(root);
	fout.close();
}

void binarySearchTree::preorder_h(searchTreeNode *n)
// does the work for preorder
// visits nodes in increasing order == sorts
// recursive
{
	if (n != NULL)
	{
		preorder_h(n->left);
		visit(n);
		preorder_h(n->right);
	}
}

void binarySearchTree::postOrder(string filename)
// calls protected helper function to visit nodes
{
	char* c_file;
	strcpy(c_file, filename.c_str());
	fout.open(c_file, ofstream::out);
	postorder_h(root);
	fout.close();
}

void binarySearchTree::postorder_h(searchTreeNode *n)
// does the work for postorder
// visits nodes in decreasing order == reverse sort/sort backwards
// recursive
{
	if (n != NULL)
	{
		postorder_h(n->right);
		visit(n);
		postorder_h(n->left);
	}
}

void binarySearchTree::inOrder(string filename)
// calls protected helper function to visit nodes
{
	char* c_file;
	strcpy(c_file, filename.c_str());
	fout.open(c_file, ofstream::out);
	inorder_h(root);
	fout.close();
}

void binarySearchTree::inorder_h(searchTreeNode *n)
// does the work for inorder
// visits nodes level by level left-right
// 		starting at root
// good for writing to file
{
	searchTreeNode *current;
	queue<searchTreeNode*> Q;
	Q.push(n);
	while (!Q.empty())
	{
		current = Q.front();
		visit(n);
		if (current->left != NULL)
			Q.push(current->left);
		if (current->right != NULL)
			Q.push(current->right);
	}
}

void binarySearchTree::visit(searchTreeNode *n)
// does the work for when each non-NULL node is visited
// gets the word and definition and writes it to the file
// file fout is part of class and declared in function calling
//		visit
{
	string word, definition;
	word = getWord(n);
	definition = getDefinition(n);
	fout << "[" << word << "]: [" << definition << "]\n";
}

string binarySearchTree::getWord(searchTreeNode *n)
// does the work for getting the word from visit
// function getDefinition is a part of dictEntry class
// pointer to data allows call of protected function
{
	return n->data->getWord();
}

string binarySearchTree::getDefinition(searchTreeNode *n)
// does the work for getting the definition from visit
// function getDefinition is a part of dictEntry class
// pointer to data allows call of protected function
{
	return n->data->getDefinition();
}