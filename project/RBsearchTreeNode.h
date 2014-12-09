// rbst class has fout from bst
using namespace std;

enum RBcolor {RED, BLACK};

class RBsearchTreeNode: public treeNode {
	public:
		RBsearchTreeNode *left;
		RBsearchTreeNode *right;
		RBsearchTreeNode *parent;
		RBcolor color;
		RBsearchTreeNode(dictEntry *d);
		RBsearchTreeNode(dictEntry *d, RBsearchTreeNode *p);
		RBsearchTreeNode(dictEntry *d, RBsearchTreeNode *l, RBsearchTreeNode *r, RBsearchTreeNode *p);
};