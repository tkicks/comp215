#include "binarySearchTree.h"
#include <queue>
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

void binarySearchTree::preorder()
// calls protected helper function to visit nodes
// protected b/c don't want people messing w/ order
// 		or else new tree will be messed up
{
	preorder_h(root);
}

void binarySearchTree::preorder_h(searchTreeNode *n)
// does the work for preorder
// visits nodes in increasing order == sorts
// recursive
{
	if (n != NULL)
	{
		preorder_h(n->left);
		// do stuff tbd
		preorder_h(n->right);
	}
}

void binarySearchTree::postorder()
// calls protected helper function to visit nodes
{
	postorder_h(root);
}

void binarySearchTree::postorder_h(searchTreeNode *n)
// does the work for postorder
// visits nodes in decreasing order == reverse sort/sort backwards
// recursive
{
	if (n != NULL)
	{
		postorder_h(n->right);
		// do stuff tbd
		postorder_h(n->left);
	}
}

void binarySearchTree::inorder()
// calls protected helper function to visit nodes
{
	inorder_h(root);
}

void binarySearchTree::inorder_h(searchTreeNode *n)
// does the work for inorder
// visits nodes level by level left-right
// 		starting at root
// good for writing to file
{
	searchTreeNode *current;
	queue<searchTreeNode> Q;
	Q.push(n);
	while (!Q.empty())
	{
		current = Q.front();
		// do stuff to Q tbd
		if (current->left != NULL)
			Q.push(current->left);
		if (current->right != NULL)
			Q.push(current->right);
	}
}