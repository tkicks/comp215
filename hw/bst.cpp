/*
Author: Tyler Kickham

NOTES: There was no description on what to do when key == leaf->value in
	   insert_help().  I took it as not duplicating and did not re-insert it
	   into the tree.  It's weird though that it shows up in inOrderTraversal.

15. It traverses the tree and displays the output. It seems to display the
	first node to the left, then its child node. Then it displays back up
	to the root, then traverses down the right and displays back up to the root
	again, resulting in a double cout of each node.
*/

#include <iostream>
#include <string>

using namespace std;

class treeNode
{
	public:
		int value;
		treeNode *left;
		treeNode *right;
		treeNode(int x);
};

class binarySearchTree
{
	private:
		treeNode *root;
		void destroy_tree(treeNode *leaf);
		void insert_help(int key, treeNode *leaf);
		void inOrder_help(treeNode *leaf);
		bool search_help(int key, treeNode *leaf);
	public:
		void insert(int key);
		void inOrderTraversal();
		bool search(int key);
		binarySearchTree();
		~binarySearchTree();
};

int main()
{
	int answer;
	bool found;
	binarySearchTree tree;
	cout << "Enter a positive number (0 or -x quits): ";
	cin >> answer;
	while (answer > 0)
	{
		tree.insert(answer);
		cout << "Enter a positive number (0 or -x quits): ";
		cin >> answer;
	}
	cout << "Search for a positive number (0 or -x quits): ";
	cin >> answer;
	while (answer > 0)
	{
		found = tree.search(answer);
		if (found)
		{
			cout << "Found " << answer << endl;
		}
		else
		{
			cout << answer << " not found\n";
		}
		cout << "Search for a positive number (0 or -x quits): ";
		cin >> answer;
	}
	tree.inOrderTraversal();
}

treeNode::treeNode(int x)
{
	// treeNode constructor
	this->value = x;
	this->left = NULL;
	this->right = NULL;
}

binarySearchTree::binarySearchTree()
{
	root = NULL;
}

binarySearchTree::~binarySearchTree()
{
	destroy_tree(root);
}


void binarySearchTree::destroy_tree(treeNode *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete(leaf);
	}
}

void binarySearchTree::insert(int key)
{
	// test made it in
	if (root == NULL)
	{
		root = new treeNode(key);
	}
	else
	{
		insert_help(key, root);
	}
}

void binarySearchTree::insert_help(int key, treeNode *leaf)
{
	if (key < leaf->value && leaf->left != NULL)
	{
		insert_help(key, leaf->left);
	}
	else if (key < leaf->value && leaf->left == NULL)
	{
		leaf->left = new treeNode(key);
	}
	else if (key > leaf->value && leaf->right != NULL)
	{
		insert_help(key, leaf->right);
	}
	else if (key > leaf->value && leaf->right == NULL)
	{
		leaf->right = new treeNode(key);
	}
	else if (key == leaf->value)
	{
		cout << "insert_help() Value already entered. Not sure whethere to put left or right. Value not duplicated (last entry not stored.)\n";
	}
	else
	{
		cout << "This should never show up. insert_help bug\n";
	}
}

bool binarySearchTree::search(int key)
{
	search_help(key, root);
}

bool binarySearchTree::search_help(int key, treeNode *leaf)
{
	if (leaf == NULL)
	{
		return false;
	}
	else if (leaf->value == key)
	{
		return true;
	}
	else if (leaf->value > key)
	{
		return search_help(key, leaf->left);
	}
	else
	{
		return search_help(key, leaf->right);
	}
}

void binarySearchTree::inOrderTraversal()
{
	inOrder_help(root);
}

void binarySearchTree::inOrder_help(treeNode *leaf)
{
	if (leaf == NULL)
	{
		return;
	}
	else if (leaf != NULL)
	{
		inOrder_help(leaf->left);
		cout << leaf->value << endl;
		inOrder_help(leaf->right);
		cout << leaf->value << endl;
	}
	else
	{
		cout << "This should never show up. inOrder_help bug\n";
	}
}