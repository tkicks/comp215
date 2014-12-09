#include "RBSearchTree.h"
using namespace std;

RBSearchTree::RBSearchTree()
{
	root = NULL;
}

RBSearchTree::~RBSearchTree()
{
	destroy_tree(root);
}


void RBSearchTree::destroy_tree(RBsearchTreeNode *leaf)
{
	if (leaf != NULL)
	{
		// cout << leaf->data->getWord() << endl;
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void RBSearchTree::insert(dictEntry *in)
// insert a dictEntry into the binary search tree
{
	if (root == NULL)
		root = new RBsearchTreeNode(in);
	else
		insert_h(in, root);
}

void RBSearchTree::insert_h(dictEntry *in, RBsearchTreeNode *current)
// inserts a dictEntry into the binary search tree if
// there's already a root entry
{
	if (*(in) == current->data->getWord())
		return;
	else if (*(in) < current->data->getWord())
	{
		if (current->left == NULL)
			current->left = new RBsearchTreeNode(in, current);
		else
			insert_h(in, current->left);
	}
	else
	{
		if (current->right == NULL)
			current->right = new RBsearchTreeNode(in, current);
		else
			insert_h(in, current->right);
	}
}

RBsearchTreeNode* RBSearchTree::search(string w)
// search for string w in tree and remove
// dictEntry with word == w
{
	return search_h(w, root);
}

RBsearchTreeNode* RBSearchTree::search_h(string w, RBsearchTreeNode *current)
// searches for string w in tree and removes
// dictEntry with word == w
// does the work for search()
{
	if (*(current->data) == w)
	{
		// cout << w << " is the same as " << current->data->getWord() << endl;
		return current;
	}
	else if (*(current->data) > w)
	{
		// cout << w << " is before " << current->data->getWord() << endl;
		if (current->left != NULL)
			return search_h(w, current->left);
		else
			return NULL;
	}
	else if (*(current->data) < w)
	{
		// cout << w << " is after " << current->data->getWord() << endl;
		if (current->right != NULL)
			return search_h(w, current->right);
		else
			return NULL;
	}
	else
		return NULL;
}	

void RBSearchTree::remove(string w)
// actually does the removing and restructuring of the tree
// dictEntry with word == w
{
	string newWord, newDefinition;
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
				RBsearchTreeNode* toDeleteSucc = successor(toDelete);
				newDefinition = toDeleteSucc->data->getDefinition();
				// cout << "successor: " << toDeleteSucc->data->getWord() << endl;
				toDelete->data->updateDefinition(newDefinition);
				if (toDelete == toDelete->parent->left)
				{
					toDeleteSucc->left = toDelete->left;
					toDeleteSucc->right = toDelete->right;
					toDelete->parent->left = toDeleteSucc;
					delete toDelete;
				}
				else
				{
					toDeleteSucc->left = toDelete->left;
					toDeleteSucc->right = toDelete->right;
					toDelete->parent->right = toDeleteSucc;
					delete toDelete;
				}
			}
		}
	}
}

RBsearchTreeNode* RBSearchTree::successor(RBsearchTreeNode *toDelete)
// ensures that all child nodes are still in tree
//		when removing a parent node with two children
{
	RBsearchTreeNode* current;
	if ((toDelete == NULL) or (toDelete->right == NULL))
		return NULL;
	else
	{
		current = toDelete->right;
		while (current->left != NULL)
			current = current->left;
		return current;
	}
}

void RBSearchTree::preOrder(string filename)
// calls protected helper function to visit nodes
// protected b/c don't want people messing w/ order
// 		or else new tree will be messed up
{
	fout.open(filename.c_str(), ofstream::out);
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
	fout.open(filename.c_str(), ofstream::out);
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
	fout.open(filename.c_str(), ofstream::out);
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
		Q.pop();
		visit(current);
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
	fout << word << ": " << definition << "\n";
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
