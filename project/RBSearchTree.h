#include <string>
#include <fstream>
using namespace std;

class RBSearchTree: public searchTree {
// purely virtual functions by including = 0 at end
// functions never used, used as base class for other classes
	public:
		RBSearchTree();
		~RBSearchTree();
		virtual void insert(dictEntry *in);
		virtual RBsearchTreeNode* insert_h(dictEntry *in, RBsearchTreeNode *root);
		virtual void insert_fixup(RBsearchTreeNode *node);
		virtual RBsearchTreeNode* Uncle(RBsearchTreeNode *node);
		virtual RBcolor Color(RBsearchTreeNode *node);
		virtual void rotate_left(RBsearchTreeNode *node);
		virtual void rotate_right(RBsearchTreeNode *node);
		virtual void remove(string w);
		virtual void remove_fixup(RBsearchTreeNode *node);
		virtual RBsearchTreeNode* Sibling(RBsearchTreeNode *node);
		virtual RBsearchTreeNode* search(string w);
		virtual RBsearchTreeNode* search_h(string w, RBsearchTreeNode *root);
		virtual RBsearchTreeNode* successor(RBsearchTreeNode *n);
		virtual void preOrder(string filename);
		virtual void postOrder(string filename);
		virtual void inOrder(string filename);

	protected:
		RBsearchTreeNode *root;
		ofstream fout;
		virtual void preorder_h(RBsearchTreeNode *n);
		virtual void postorder_h(RBsearchTreeNode *n);
		virtual void inorder_h(RBsearchTreeNode *n);
		virtual void visit(RBsearchTreeNode *n);
		virtual void destroy_tree(RBsearchTreeNode *leaf);
		virtual string getWord(RBsearchTreeNode *n);
		virtual string getDefinition(RBsearchTreeNode *n);
};