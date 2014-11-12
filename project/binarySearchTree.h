#include <string>
using namespace std;

class binarySearchTree: public searchTree {
	public:
		binarySearchTree();
		virtual void insert(dictEntry *in);
		virtual void insert_h(dictEntry *in, searchTreeNode *root);
		virtual treeNode search(string w);
		virtual treeNode search_h(string w, searchTreeNode *root);
	protected:
		searchTreeNode *root;
};