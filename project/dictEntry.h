#include <string>

using namespace std;


class dictEntry {
	public:
		dictEntry(string w, string d);
		string getWord();
		string getDefinition();
		void updateWord(string word);
		void updateDefinition(string def);
		bool operator==(string str);
		bool operator>(string str);
		bool operator<(string str);
		bool operator>=(string str);
		bool operator<=(string str);
	protected:
		string word, definition;
};