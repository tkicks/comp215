#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

class mygraph {
	public:
		int nbVertices;
		int** adjMatrix;

		mygraph();
		mygraph(int nbLines);
		~mygraph();
		mygraph DFS(mygraph& G);
		// BFS();

	private:
		int count;
		void dfs(int vertex);
		// bfs();
};




int main()
{
	string response, line;
	// a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t,
	int nbLines;
	cout << "Enter a file name: ";
	cin >> response;

	char *c_response = new char[response.length()+1];
	strcpy(c_response, response.c_str());

	ifstream myFile(c_response);

	getline(myFile, line);
	istringstream iss(line);
	iss >> nbLines;

	mygraph G(nbLines);
	G = G.DFS(G);

	// while (getline(myFile, line))
	// {
	// 	istringstream iss(line);
	// 	iss >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l >> m >> n >> o >> p >> q >> r >> s >> t;
	// }
}



mygraph::mygraph()
{
	nbVertices = 0;
	adjMatrix = NULL;
}

mygraph::mygraph(int nbLines)
{
	nbVertices = nbLines;
	adjMatrix = new int* [nbVertices];
	for (int i = 0; i < nbVertices; i++)
	{
		adjMatrix[i] = new int [nbVertices];
	}
}

mygraph::~mygraph()
{
	for (int i = 0; i < nbVertices; i++)
	{
		delete[] adjMatrix[i];
	}
	delete[] adjMatrix;
}

mygraph mygraph::DFS(mygraph& G)
{
	cout << "In DFS\n";
	count = 0;
	for (int vertex = 0; vertex < nbVertices; vertex++)
	{
		if (vertex == 0)
		{
			dfs(vertex);
		}
	}
}

void mygraph::dfs(int vertex)
{
	cout << "In dfs\n";
	count += 1;
	vertex = count;
	for (int w = 0; w < nbVertices; w++)
	{
		if (w == 0)
		{
			dfs(w);
		}
	}
}