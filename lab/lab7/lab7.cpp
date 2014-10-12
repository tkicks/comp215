/*
	NOTE: Lines 74 and 75 are commented out.  Uncomment one at a time.  I don't think
	I got the functions to work correctly, but I got them to go through each
	vertex, so I threw in some cout statements to show where it's reaching.
	Uncommenting both at once will produce too much output for a single run.
	It's sort of just to show the work I've done.
*/




#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <queue>
#include <deque>

using namespace std;

class mygraph {
	public:
		int nbVertices;
		int** adjMatrix;
		int** mark;

		mygraph();
		mygraph(int nbLines);
		~mygraph();
		void DFS(mygraph& G);
		void BFS(mygraph& G);

	private:
		int count;
		void dfs(int vertex);
		void bfs(int vertex);
};




int main()
{
	string response, line;
	// a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t,
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, row, column, nbLines;
	cout << "Enter a file name: ";
	cin >> response;

	char *c_response = new char[response.length()+1];
	strcpy(c_response, response.c_str());

	ifstream myFile(c_response);

	getline(myFile, line);
	istringstream iss(line);
	iss >> nbLines;

	mygraph G(nbLines);
	

	row = 0;	// which row it is
	while (getline(myFile, line))
	{
		column = 0;	// which column it is
		istringstream iss(line);
		iss >> G.adjMatrix[row][column] >> G.adjMatrix[row][column+1] >> G.adjMatrix[row][column+2] >> G.adjMatrix[row][column+3] >> G.adjMatrix[row][column+4] >> G.adjMatrix[row][column+5] >> G.adjMatrix[row][column+6] >> G.adjMatrix[row][column+7] >> G.adjMatrix[row][column+8] >> G.adjMatrix[row][column+9] >> G.adjMatrix[row][column+10] >> G.adjMatrix[row][column+11] >> G.adjMatrix[row][column+12] >> G.adjMatrix[row][column+13] >> G.adjMatrix[row][column+14] >> G.adjMatrix[row][column+15] >> G.adjMatrix[row][column+16] >> G.adjMatrix[row][column+17] >> G.adjMatrix[row][column+18] >> G.adjMatrix[row][column+19];

		// cout << G.adjMatrix[row][column] << G.adjMatrix[row][column+1] << G.adjMatrix[row][column+2] << G.adjMatrix[row][column+3] << G.adjMatrix[row][column+4] << G.adjMatrix[row][column+5] << G.adjMatrix[row][column+6] << G.adjMatrix[row][column+7] << G.adjMatrix[row][column+8] << G.adjMatrix[row][column+9] << G.adjMatrix[row][column+10] << G.adjMatrix[row][column+11] << G.adjMatrix[row][column+12] << G.adjMatrix[row][column+13] << G.adjMatrix[row][column+14] << G.adjMatrix[row][column+15] << G.adjMatrix[row][column+16] << G.adjMatrix[row][column+17] << G.adjMatrix[row][column+18] << G.adjMatrix[row][column+19] << endl;

		row++;
	} 

	// G.DFS(G);
	// G.BFS(G);
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
	mark = new int* [nbVertices];
	for (int i = 0; i < nbVertices; i++)
	{
		adjMatrix[i] = new int [nbVertices];
		mark[i] = new int [nbVertices];
	}
}

mygraph::~mygraph()
{
	for (int i = 0; i < nbVertices; i++)
	{
		delete[] adjMatrix[i];
		delete[] mark[i];
	}
	delete[] adjMatrix;
	delete[] mark;
}

void mygraph::DFS(mygraph& G)
{
	count = 0;
	for (int i = 0; i < nbVertices; i++)
	{
		for (int j = i+1; j < nbVertices; j++)
		{
			mark[i][j] = 0;
		}
	}
	for (int vertex = 0; vertex < nbVertices; vertex++)
	{
		if (mark[vertex][vertex] == 0)
		{
			dfs(vertex);
		}
	}
	cout << count << endl;
	cout << "It pops them in FIFO order\n";
}

void mygraph::dfs(int vertex)
{
	count += 1;
	*mark[vertex] = count;
	for (int w = 0; w < nbVertices; w++)
	{
		cout << "X Coordinate (" << w << ")" << endl;
		if (mark[w] == 0)
		{
			dfs(w);
		}
	}
	cout << "\n\n\n";
}

void mygraph::BFS(mygraph& G)
{
	count = 0;
	for (int vertex = 0; vertex < nbVertices; vertex++)
	{
		if (mark[vertex][vertex] == 0)
		{
			bfs(vertex);
		}
	}
	cout << "It goes through all ys for each x before moving on to the next x\n";
}

void mygraph::bfs(int vertex)
{
	count += 1;
	*mark[vertex] = count;
	deque<int> myQueue(vertex);
	queue<int> queues(myQueue);
	while (!queues.empty())
	{
		for (int w = 0; w < nbVertices; w++)
		{
			for (int j = 0; j < nbVertices; j++)
			{
				if (mark[w][j] == 0)
				{
					count += 1;
					mark[w][j] = count;
					queues.push(w);
					cout << "Coordinate (" << w << ", " << j << ")" << endl;
				}
			}
			
		}

		
		queues.pop();
	}
}