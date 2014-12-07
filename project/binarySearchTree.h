#include <string.h>
#include <fstream>
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
		virtual void preOrder(string filename);
		virtual void postOrder(string filename);
		virtual void inOrder(string filename);

	protected:
		searchTreeNode *root;
		ofstream fout;
		virtual void preorder_h(searchTreeNode *n);
		virtual void postorder_h(searchTreeNode *n);
		virtual void inorder_h(searchTreeNode *n);
		virtual void visit(searchTreeNode *n);
		virtual string getWord(searchTreeNode *n);
		virtual string getDefinition(searchTreeNode *n);
};