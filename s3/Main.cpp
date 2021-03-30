#include <iostream>
#include <iomanip>
#include "Data.h"
#include "Implementation.cpp"

using namespace std;
int main() {
	Graph g(7);
	int origin, destination;
	//adjacency list
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
	//adjacency matrix
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

	while (true) {
		cout << endl << '\t' << "MENU" << endl;
		cout << "1. Create Graph" << endl;
		cout << " a. Adjacency List" << endl;
		cout << " b. Adjacency Matrix" << endl;
		cout << "2. Traversal" << endl;
		cout << " a. BFS" << endl;
		cout << " b. DFS" << endl;
		cout << "3. Find Path" << endl;
		cout << "4. Path Cost" << endl;
		cout << "5. Exit Program" << endl;
		cout << endl << "Enter choice: ";
		int choice;
		cin >> choice;
		switch (choice) {
			char ch;
			case 1: 
				cout << endl << "CREATE GRAPH" << endl;
				cout << "a. Adjacency List" << endl;
				cout << "b. Adjacency Matrix" << endl;
				cout << endl << "Enter choice: ";
				cin >> ch;
				switch (ch) {
					case 'a':
						cout << endl;
						g.printGraph();
						break;
					case 'b':
						cout << endl;
						g.printGraph2();
						break;
					default:
						cout << endl << "Invalid. Please try again." << endl;
				}
				break;
			case 2:
				cout << endl << "TRAVERSAL" << endl;
				cout << "a. BFS" << endl;
				cout << "b. DFS" << endl;
				cout << "Enter choice: ";
				cin >> ch;
				switch (ch) {
					case 'a':
						cout << endl << "BFS Traversal" << endl;
						g.GetInput(1);
						break;
					case 'b':
						cout << endl << "DFS Traversal" << endl;
						g.GetInput(2);
						break;
					default:
						cout << "Invalid. Please try again." << endl;
				}
				break;
			case 3:
				cout << endl << "FIND PATH" << endl;
				break;
			case 4:
				cout << endl << "PATH COST" << endl;
				break;
			case 5:
				cout << endl << "Exiting the program..." << endl;
				return 0;
			default:
				cout << endl << "Invalid. Please try again." << endl;
		}
		while (true) {
			cout << endl << "Would you like to stay ?(Y/N): ";
			char ch;
			cin >> ch;
			if (ch == 'Y' || ch == 'y') {
				system("cls");
				break;
			} else if (ch == 'N' || ch == 'n') {
				cout << "Exiting the program..." << endl;
				return 0;
			} else {
				cout << "Invalid. Please try again..." << endl;	
			}
		}
	}
	return 0;
}
