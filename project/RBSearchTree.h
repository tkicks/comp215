#include <string>
#include <fstream>
using namespace std;

class RBSearchTree: public searchTree {
// purely virtual functions by including = 0 at end
// functions never used, used as base class for other classes
	public:
		RBSearchTree();
		virtual void insert(dictEntry input) = 0;
		virtual treeNode* search(string input) = 0;
		virtual void remove(string input) = 0;
		virtual void preOrder() = 0;
		virtual void postOrder() = 0;
		virtual void inOrder() = 0;
		virtual void insert(dictEntry *in);
		virtual void insert_h(dictEntry *in, searchTreeNode *root);
		virtual void remove(string w);
		virtual searchTreeNode* search(string w);
		virtual searchTreeNode* search_h(string w, searchTreeNode *root);
		// virtual searchTreeNode* successor(searchTreeNode *n);
		virtual void preorder(string filename);
		virtual void postorder(string filename);
		virtual void inorder(string filename);

	protected:
		RBsearchTreeNode *root;
		ofstream fout;
};