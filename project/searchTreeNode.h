#include <string>

using namespace std;

class searchTreeNode: public treeNode {
	public:
		searchTreeNode *left;
		searchTreeNode *right;
		searchTreeNode *parent;
		searchTreeNode(dictEntry *d);
		searchTreeNode(dictEntry *d, searchTreeNode *p);
		searchTreeNode(dictEntry *d, searchTreeNode *l, searchTreeNode *r, searchTreeNode *p);
};