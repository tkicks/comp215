#include "binarySearchTree.h"
using namespace std;

binarySearchTree::binarySearchTree()
// init the tree with a NULL root
{
	root = NULL;
}

void binarySearchTree::insert(dictEntry *in)
// insert a dictEntry into the binary search tree
{
	searchTreeNode *root = root;
	if (root == NULL)
		root = new searchTreeNode(in);
	else
		insert_h(in, root);
}

void binarySearchTree::insert_h(dictEntry *in, searchTreeNode *root)
// inserts a dictEntry into the binary search tree if
// there's already a root entry
{
	if (in == root->data)
		return;
	else if (in < root->data)
	{
		if (root->left == NULL)
			root->left = new searchTreeNode(in, root);
		else
			insert_h(in, root->left);
	}
	else
	{
		if (root->right == NULL)
			root->right = new searchTreeNode(in, root);
		else
			insert_h(in, root->right);
	}
}

searchTreeNode* binarySearchTree::search(string w)
// search for string w in tree and remove
// dictEntry with word == w
{
	searchTreeNode *root = root;
	return search_h(w, root);
}

searchTreeNode* binarySearchTree::search_h(string w, searchTreeNode *root)
// searches for string w in tree and removes
// dictEntry with word == w
// does the work for search()
{
	if (root == NULL)
		return NULL;
	else if (*(root->data) == w)
		return root;
	else if (*(root->data) < w)
		return search_h(w, root->left);
	else
		return search_h(w, root->right);
}	

