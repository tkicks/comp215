#include "RBsearchTreeNode.h"
using namespace std;

RBsearchTreeNode::RBsearchTreeNode(dictEntry *d)
// constructor setting data to passed in dictEntry
{
	RBcolor color;
	data = d;
	left = NULL;
	right = NULL;
	parent = NULL;
	color = RED;
}

RBsearchTreeNode::RBsearchTreeNode(dictEntry *d, RBsearchTreeNode *p)
// constructor setting data and parent to values passed in
{
	RBcolor color;
	data = d;
	parent = p;
	left = NULL;
	right = NULL;
	color = RED;
}

RBsearchTreeNode::RBsearchTreeNode(dictEntry *d, RBsearchTreeNode *l, RBsearchTreeNode *r, RBsearchTreeNode *p)
{
	RBcolor color;
	data = d;
	left = l;
	right = r;
	parent = p;
	color = RED;
}