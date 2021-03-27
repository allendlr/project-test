#include <iostream>
#include "Implementation.cpp"
using namespace std;

int main()
{
	int ch;
	Graph g(7);
	cout << "Graph Operations" << endl;
	cout << "[1] Adjacency List" << endl;
	cout << "[2] Adjacency Matrix" << endl;
	cout << "Enter choice: ";
	cin >> ch;
	if (ch == 1)
	{
		g.addEdge(0, 6, 600);
		g.addEdge(0, 5, 800);
		g.addEdge(1, 5, 160);
		g.addEdge(1, 3, 200);	
		g.addEdge(2, 4, 1000);
		g.addEdge(3, 1, 200);
		g.addEdge(3, 4, 780);
		g.addEdge(3, 2, 900);
		g.addEdge(4, 2, 1000);
		g.addEdge(4, 0, 1400);	
		g.addEdge(5, 0, 800);
		g.addEdge(6, 0, 600);
		g.addEdge(6, 3, 1300);
		g.printGraph();
		cout << endl << "DFS Traversal..." << endl;
		g.DFS(1);
		cout << endl << endl;
		cout << endl << "BFS Traversal..." << endl;
		g.BFS(3);
	}
	else if (ch == 2)
	{
		g.addEdge2(0, 6, 600);
		g.addEdge2(0, 5, 800);
		g.addEdge2(1, 5, 160);
		g.addEdge2(1, 3, 200);
		g.addEdge2(2, 4, 1000);
		g.addEdge2(3, 1, 200);
		g.addEdge2(3, 4, 780);
		g.addEdge2(3, 2, 900);
		g.addEdge2(4, 2, 1000);
		g.addEdge2(4, 0, 1400);
		g.addEdge2(5, 0, 800);
		g.addEdge2(6, 0, 600);
		g.addEdge2(6, 3, 1300);
		g.printGraph2();
		cout << endl << "DFS Traversal..." << endl;
		g.DFS(1);
		cout << endl << endl;
		cout << endl << "BFS Traversal..." << endl;
		g.BFS(3);
	}
	cout << endl << endl;
}


