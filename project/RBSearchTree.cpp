#include "RBSearchTree.h"
using namespace std;

RBSearchTree::RBSearchTree()
{
	root = NULL;
}

void RBSearchTree::insert(dictEntry *in)
// insert a dictEntry into the binary search tree
{
	RBsearchTreeNode *root = this->root;
	if (root == NULL)
		root = new RBsearchTreeNode(in);
	else
		insert_h(in, root);
}

void RBSearchTree::insert_h(dictEntry *in, RBsearchTreeNode *root)
// inserts a dictEntry into the binary search tree if
// there's already a root entry
{
	if (in == root->data)
		return;
	else if (in < root->data)
	{
		if (root->left == NULL)
			root->left = new RBsearchTreeNode(in, root);
		else
			insert_h(in, root->left);
	}
	else
	{
		if (root->right == NULL)
			root->right = new RBsearchTreeNode(in, root);
		else
			insert_h(in, root->right);
	}
}

RBsearchTreeNode* RBSearchTree::search(string w)
// search for string w in tree and remove
// dictEntry with word == w
{
	RBsearchTreeNode *root = this->root;
	return search_h(w, root);
}

RBsearchTreeNode* RBSearchTree::search_h(string w, RBsearchTreeNode *root)
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

void RBSearchTree::remove(string w)
// actually does the removing and restructuring of the tree
// dictEntry with word == w
{
	RBsearchTreeNode* toDelete = search(w);
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
				// RBsearchTreeNode* toDeleteSucc = toDelete->successor(toDelete);
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

void RBSearchTree::preOrder(string filename)
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

void RBSearchTree::preorder_h(RBsearchTreeNode *n)
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

void RBSearchTree::postOrder(string filename)
// calls protected helper function to visit nodes
{
	char* c_file;
	strcpy(c_file, filename.c_str());
	fout.open(c_file, ofstream::out);
	postorder_h(root);
	fout.close();
}

void RBSearchTree::postorder_h(RBsearchTreeNode *n)
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

void RBSearchTree::inOrder(string filename)
// calls protected helper function to visit nodes
{
	char* c_file;
	strcpy(c_file, filename.c_str());
	fout.open(c_file, ofstream::out);
	inorder_h(root);
	fout.close();
}

void RBSearchTree::inorder_h(RBsearchTreeNode *n)
// does the work for inorder
// visits nodes level by level left-right
// 		starting at root
// good for writing to file
{
	RBsearchTreeNode *current;
	queue<RBsearchTreeNode*> Q;
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

void RBSearchTree::visit(RBsearchTreeNode *n)
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

string RBSearchTree::getWord(RBsearchTreeNode *n)
// does the work for getting the word from visit
// function getDefinition is a part of dictEntry class
// pointer to data allows call of protected function
{
	return n->data->getWord();
}

string RBSearchTree::getDefinition(RBsearchTreeNode *n)
// does the work for getting the definition from visit
// function getDefinition is a part of dictEntry class
// pointer to data allows call of protected function
{
	return n->data->getDefinition();
}