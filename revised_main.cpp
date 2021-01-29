#include <iostream>
#include <string.h>
#include "data.h"
#include "implementation.cpp"

using namespace std;

int main() {
  MovieList ml;
  int codes[100];
  int code;
  int cnt = 0;
  string title;
  string genre;
  int year;
 
	while (true) {
    system("clear");
    
    switch (menu()) {
      case '1':
        cout << endl << " << Inserting a New Movie >> " << endl << endl;
        {
          
          while (true) {
            cout << "Enter Movie Code: ";
            cin >> code;
            bool checker = true;
            for (int i = 0; i < cnt; i++) {
              if (code == codes[i]) {
                checker = false;
              }
            }
            if (checker) {
              break;
            } else {
              cout << "Movie code already exists. Please try again." << endl;
            }
          }
          cin.ignore();
          cout << "Enter Movie Title: ";
          
          getline(cin, title);
          cout << "Enter Movie Genre: ";
         
          getline(cin, genre);
          cout << "Enter Year Released: ";
          
          cin >> year;
          ml.InsertNode(code, title, genre, year);
          codes[cnt++] = code;
        }
        break;
      case '2':
        cout << "Enter Movie Code: ";
            cin >> code;      
			  cout << endl << " << Renting a Movie >> " << endl << endl;         
        ml.DeleteNode(code);
        break;
      case '3':
          cout << "Enter Movie Code: ";
          cin >> code;  
          
          cin.ignore();
          cout << "Enter Movie Title: ";         
          getline(cin, title);

          cout << "Enter Movie Genre: ";        
          getline(cin, genre);

          cout << "Enter Year Released: ";      
          cin >> year;
          ml.AppendNode(code, title, genre, year);
          
   
        
        break;
    
      case '4':
        cout << endl << " << Movie Details >> " << endl << endl;
        cout << "Enter movie code: ";
        int code;
        cin >> code;
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
  return 0;
}
