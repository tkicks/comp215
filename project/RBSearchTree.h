#include <string>
#include <fstream>
using namespace std;

class RBSearchTree: public searchTree {
// purely virtual functions by including = 0 at end
// functions never used, used as base class for other classes
	public:
		RBSearchTree();
		virtual void insert(dictEntry *in);
		virtual void insert_h(dictEntry *in, RBsearchTreeNode *root);
		virtual void remove(string w);
		virtual RBsearchTreeNode* search(string w);
		virtual RBsearchTreeNode* search_h(string w, RBsearchTreeNode *root);
		// virtual RBsearchTreeNode* successor(RBsearchTreeNode *n);
		virtual void preorder(string filename);
		virtual void postorder(string filename);
		virtual void inorder(string filename);

	protected:
		RBsearchTreeNode *root;
		ofstream fout;
		virtual void preorder_h(RBsearchTreeNode *n);
		virtual void postorder_h(RBsearchTreeNode *n);
		virtual void inorder_h(RBsearchTreeNode *n);
		virtual void visit(RBsearchTreeNode *n);
		virtual string getWord(RBsearchTreeNode *n);
		virtual string getDefinition(RBsearchTreeNode *n);
};