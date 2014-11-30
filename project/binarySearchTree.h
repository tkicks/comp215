#include <string>
using namespace std;

class binarySearchTree: public searchTree {
	public:
		binarySearchTree();
		virtual void insert(dictEntry *in);
		virtual void insert_h(dictEntry *in, searchTreeNode *root);
		virtual void remove(string w);
		virtual searchTreeNode* search(string w);
		virtual searchTreeNode* search_h(string w, searchTreeNode *root);
		// virtual searchTreeNode* successor(searchTreeNode *n);
		virtual void preorder();
		virtual void postorder();
		virtual void inorder();

	protected:
		searchTreeNode *root;
		virtual void preorder_h(searchTreeNode *n);
		virtual void postorder_h(searchTreeNode *n);
		virtual void inorder_h(searchTreeNode *n);
};