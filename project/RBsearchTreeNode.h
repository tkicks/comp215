// rbst class has fout from bst
using namespace std;

class RBsearchTreeNode: public treeNode {
	public:
		enum RBcolor {RED, BLACK};
		RBcolor color;
		RBsearchTreeNode *left;
		RBsearchTreeNode *right;
		RBsearchTreeNode *parent;
		RBsearchTreeNode(dictEntry *d);
		RBsearchTreeNode(dictEntry *d, RBsearchTreeNode *p);
		RBsearchTreeNode(dictEntry *d, RBsearchTreeNode *l, RBsearchTreeNode *r, RBsearchTreeNode *p);
};