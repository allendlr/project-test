#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

class Graph {
	private:
		int V;
		int totalCost;
		list <int> *adj;
		list<int> *cost;
		int **adj2;
		void DFSUtil(int v, bool visited[]);
		void PathUtil(int v, bool visited[], int des);
		void BFSUtil(int s, bool visited[]);
	public:
		Graph(int);
		void addEdge(int u, int v, int cost);
		void addEdge2(int u, int v, int cost);
		void printGraph();
		void printGraph2();
		void DFS(int v);
		void BFS(int s);
		void GetInput(int option);
		void findPath(int u, int v);
};

#endif
