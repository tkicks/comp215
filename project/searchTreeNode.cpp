#include "searchTreeNode.h"
using namespace std;

searchTreeNode::searchTreeNode(dictEntry *d)
// constructor setting data to passed in dictEntry
{
	data = d;
	left = NULL;
	right = NULL;
	parent = NULL;
}

searchTreeNode::searchTreeNode(dictEntry *d, searchTreeNode *p)
// constructor setting data and parent to values passed in
{
	data = d;
	parent = p;
	left = NULL;
	right = NULL;
}

searchTreeNode::searchTreeNode(dictEntry *d, searchTreeNode *l, searchTreeNode *r, searchTreeNode *p)
{
	data = d;
	left = l;
	right = r;
	parent = p;
}