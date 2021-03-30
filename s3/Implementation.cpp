#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <cctype>
#include "Data.h"

using namespace std;

string countries[] = {"Atlanta", "Austin", "Chicago", "Dallas", "Denver", "Houston", "Washington"};

Graph::Graph(int x) {
	V = x;
	totalCost = 0;
	cost = new list <int> [V];
	adj = new list <int> [V];
	adj2 = new int* [V];
	for (int i = 0; i < V; i++) {
		adj2[i] = new int[V];
	}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			adj2[i][j] = 0;
		}
	}
}

void Graph::GetInput(int option) {
	char temp;
	string check[7] = {"atlanta", "austin", "chicago", "dallas", "denver", "houston", "washington"};
	cout << endl << "List of Countries (Choose Origin) " << endl;
	for (int i = 0; i < V; i++) {
		cout << (i == 0 ? "[" : "") << countries[i] << (i < V - 1 ? ", " : "]");
	}
	string origin, destination;
	cout << endl << endl << "Enter origin: ";
	cin >> origin;
	//converts origin string to lowercase to avoid cases when comparing
	for(int i = 0; i < origin.length(); i++){
		temp = origin[i];
		temp = tolower(temp);
		origin[i] = temp;
	}
	int origin_index = 0;
	bool exist = false;
	//compares if the origin exist in the fixed graph
	for(string s: check){
		if(origin == s){
			exist = true;
			break;
		}
		else{
			origin_index++;
		}
	}
	// for (int i = 0; i < V; i++) {       removed - allen
	// 	if (countries[i] == origin) {
	// 		exist = true;
	// 	} 
	// }
	if(exist){							//added -allen to check if it exist
		if (option == 1){
			BFS(origin_index);
		}
		else{
			DFS(origin_index);
		}
		cout << endl;
	}
	else{
		cout<<"\n Origin State Doesn't Exist!";
	}
	
}

void Graph::addEdge(int u, int v, int price) {
	cost[u].push_back(v);
	adj[u].push_back(v);
}

void Graph::addEdge2(int u, int v, int cost) {
	adj2[u][v] = cost;
}

void Graph::printGraph() {
	cout << "Adjacency List..." << endl;
	for (int v = 0; v < V; v++) {
		cout << countries[v];
		for (auto x : adj[v]) {
			cout << " -> " << countries[x];
		}
		cout << endl;
	}
}

void Graph::printGraph2() {
	cout << "Adjacency Matrix..." << endl << endl;
	cout << "\t\t";
	for (int i = 0; i < V; i++) {
		cout << countries[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < V; i++) {
		cout << countries[i] << "\t";
		if (i != V - 1) {
			cout << '\t';
		}
		for (int j = 0; j < V; j++) {
			cout << adj2[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void Graph::DFSUtil(int v, bool visited[]) {
	visited[v] = true;
	cout << "[" << v << "] " << countries[v] << " ";
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); i++) {
		if (!visited[*i]) {
			DFSUtil(*i, visited);
		}
	}
}

void Graph::DFS(int v) {
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
	DFSUtil(v, visited);
	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			DFSUtil(i, visited);
		}
	}
	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			cout << "[" << i << "] " << countries[i] << " ";
		}
	}
}

void Graph::BFS(int s) {
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
	BFSUtil(s, visited);
	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			BFSUtil(i, visited);
		}
	}
	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			cout << "[" << i << "] " << countries[i] << " ";
		}
	}
}

void Graph::BFSUtil(int s, bool visited[]) {
	list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	list<int>::iterator i;
	while (!queue.empty()) {
		s = queue.front();
		cout << "[" << s << "] " << countries[s] << " ";
		queue.pop_front();
		for (i = adj[s].begin(); i != adj[s].end(); i++) {
			if (!visited[*i]) {
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

void Graph::findPath(int u, int v){
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	//first traverse
	PathUtil(u, visited, v);
	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
		{
			PathUtil(i, visited, v);
		}
	}
	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
		{
			cout << "[" << i << "] " << countries[i] << " ";
		}
	}
}

void Graph::PathUtil(int u, bool visited[], int v){
	visited[u] = true;
	cout << "[" << u << "] " << countries[u] << " ";
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); i++)
	{
		if (!visited[*i])
		{
			PathUtil(*i, visited, v);
		}
	}
}

