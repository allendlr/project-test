#include <iostream>
#include <string.h>
#include "Data.h"
#include "Implementation.cpp"

using namespace std;

int main() {
	MovieList ml;
	int code;
	int year;
	string title;
	string genre;
	
	while (true) {
		system("clear");
		switch (menu()) {
			case '1':
				cout << endl << " << Insert a Movie >> " << endl << endl; 
				ml.getCode(&code);
				if (ml.isDuplicate(code)){ //check duplicates - allen
					cout<<"Movie Code already Existed";
					break;
				}
				ml.getMovieData(&title, &genre, &year);
				ml.InsertNode(code, title, genre, year);
				break;
			case '2':
				cout << endl << " << Renting a Movie >> " << endl << endl;     
				ml.getCode(&code);
				ml.DeleteNode(code);
				break;
			case '3':
				cout<< endl << " << Return a Movie >> " << endl << endl;
				ml.getCode(&code);
				if (!ml.rentReturn(code)){ //check duplicates in rent list - allen
					cout<<"Movie doesn't Exist in Rented List.";
					break;
				}
				ml.AppendNode(code);
				break;    
			case '4':
				cout << endl << " << Movie Details >> " << endl << endl; //fix this running even no data -allen
				ml.getCode(&code);
				ml.TraverseList(code);
				break;
			case '5':
				cout << endl << " << Movie List >> " << endl << endl; 
				ml.DisplayList();
				break;
			case '6':
				cout << endl << "Thank you for using the program!" << endl; 
				return 0;
			default:
				cout << endl << "Invalid Input!" << endl << endl;
				break;
		}
		
		while (true) {    
			char choice;
			cout << "\nUse JubiLoop's Movie Menu Again? (Y/N): ";
			cin.ignore();
			cin >> choice;
			if (choice == 'Y' || choice == 'y') {
				system("clear");
				break;
			} else if (choice == 'N' || choice == 'n') {
				cout << "Exiting...\n";
				ml.~MovieList();
				exit(0);
			} else {
				cout << "Please try again.\n";
			}
		}
	}
}
