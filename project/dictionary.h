#include <string>
using namespace std;

class dictionary {
	public:
		dictionary(searchTree *n);
		~dictionary();
		string search(string word);
		void add(dictEntry entry);
		void remove(string word);
		void readFile(string filename);
		void writeFilePreorder(string filename);
		void writeFileInorder(string filename);
		void writeFilePostorder(string filename);
	protected:
		searchTree *dict;
};

string makeCap(string word);