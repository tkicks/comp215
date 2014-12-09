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
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void RBSearchTree::insert(dictEntry *in)
// insert a dictEntry into the binary search tree
{
	RBsearchTreeNode *z;
	if (root == NULL)
	{
		root = new RBsearchTreeNode(in);
		z = root;
	}
	else
		z = insert_h(in, root);
	if (z != NULL)
		insert_fixup(z);
}

RBsearchTreeNode* RBSearchTree::insert_h(dictEntry *in, RBsearchTreeNode *current)
// inserts a dictEntry into the binary search tree if
// there's already a root entry
{
	if ((*(in) < current->data->getWord()) and (current->left != NULL))
		return insert_h(in, current->left);
	else if (*(in) < current->data->getWord())
	{
		current->left = new RBsearchTreeNode(in, current);
		return (current->left);
	}
	else if ((*(in) > current->data->getWord()) and (current->right != NULL))
		return insert_h(in, current->right);
	else if (*(in) > current->data->getWord())
	{
		current->right = new RBsearchTreeNode(in, current);
		return current->right;
	}
	else
		return NULL;
}

void RBSearchTree::insert_fixup(RBsearchTreeNode *node)
// fixes the color of the node inserted
// node = node currently focused on fixing
// p = parent of node, g = parent of parent, u = uncle of node
{
	if (node->parent == NULL)
		node->color = BLACK;
	else if (node->parent->color == BLACK)
		return;
	else
	{
		RBsearchTreeNode *p = node->parent;
		RBsearchTreeNode *g = p->parent;
		RBsearchTreeNode *u = Uncle(node);
		if (Color(u) == BLACK)
		{
			if ((node == p->right) and (p == g->left))
			{
				rotate_left(p);
				swap(p, node);
			}
			if ((node == p->left) and (p == g->right))
			{
				rotate_right(p);
				swap(p, node);
			}
			p->color = BLACK;
			g->color = RED;
			if (node == p->left)
				rotate_right(g);
			else
				rotate_left(g);
		}
		else
		{
			p->color = BLACK;
			u->color = BLACK;
			g->color = RED;
			insert_fixup(g);
		}
	}
}

RBsearchTreeNode* RBSearchTree::Uncle(RBsearchTreeNode *node)
// finds the uncle node of the node that's currently
//		trying to be fixed
{
	if (node->parent != NULL)
	{
		RBsearchTreeNode *p = node->parent;
		if (p->parent != NULL)
		{
			RBsearchTreeNode *g = p->parent;
			if (p == g->left)
				return (g->right);
			else
				return (g->left);
		}
	}
	return NULL;
}

RBcolor RBSearchTree::Color(RBsearchTreeNode *node)
// finds the color of the uncle node to determine
//		which rotate to do
{
	if (node == NULL)
		return BLACK;
	else
		return (node->color);
}

void RBSearchTree::rotate_left(RBsearchTreeNode *node)
// rotates the current node left
{
	RBsearchTreeNode *y = node->right;
	node->right = y->left;
	if (y->left != NULL)
		y->left->parent = node;
	y->parent = node->parent;
	if (node->parent == NULL)
		root = y;
	else if (node == node->parent->left)
		node->parent->left = y;
	else
		node->parent->right = y;
	y->left = node;
	node->parent = y;
}

void RBSearchTree::rotate_right(RBsearchTreeNode *node)
// rotates the current node right
{
	RBsearchTreeNode *y = node->left;
	node->left = y->right;
	if (y->right != NULL)
		y->right->parent = node;
	y->parent = node->parent;
	if (node->parent == NULL)
		root = y;
	else if (node == node->parent->right)
		node->parent->right = y;
	else
		node->parent->left = y;
	y->right = node;
	node->parent = y;
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
// in save file: 0 = RED 1 = BLACK
{
	string word, definition;
	word = getWord(n);
	definition = getDefinition(n);
	fout << word << ": " << definition << ": " << n->color << "\n\n";
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
