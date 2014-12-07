#include <string>
using namespace std;

class searchTree {
// purely virtual functions by including = 0 at end
// functions never used, used as base class for other classes
	public:
		virtual void insert(dictEntry *input) = 0;
		virtual treeNode* search(string input) = 0;
		virtual void remove(string input) = 0;
		virtual void preOrder(string filename) = 0;
		virtual void postOrder(string filename) = 0;
		virtual void inOrder(string filename) = 0;
};