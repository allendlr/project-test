#include <iostream>
#include <string.h>
#include "Data.h"
using namespace std;

char menu(){  //Jubilee
  char ch;
	cout << " << JubiLoop's Movie Menu >> " << endl << endl;
	cout << "[1] Insert a New Movie " << endl;
  cout << "[2] Rent a Movie" << endl;
  cout << "[3] Return a Movie" << endl;
  cout << "[4] Show Movie Details" << endl;
  cout << "[5] Print Movie List" << endl;
  cout << "[6] Quit the Program" << endl << endl;    
    
  cout << "Enter Choice: ";
  cin >> ch;
  return ch;
}

MovieList::MovieList() {
	head = NULL;
  rent_head = NULL;
}

MovieList::~MovieList() {
	MovieNode *nodePtr, *nextNode;
	nodePtr = head;
	while (nodePtr != NULL) {
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	cout << "Movies have been removed!" << endl;
}

bool MovieList::isDuplicate(int code){ //added duplicate - allen
    MovieNode *nodePtr;
    nodePtr = head;

    if (head){
        while(nodePtr){
            if(nodePtr->data.movie_code == code){
                return true;
            }
            nodePtr = nodePtr->next;
        }
    }
    nodePtr = rent_head; //added this to check duplicates in rent list - allen
    if (rent_head){
      while(nodePtr){
        if(nodePtr->data.movie_code == code){
          return true;
        }
        nodePtr = nodePtr->next;
      }
    }
    return false;
}

void MovieList::getCode(int *code){
	cout<<"Enter Movie Code: ";
    cin>> *code;
}

void MovieList::getMovieData(string* title, string* genre, int* year){
	cin.ignore();
    cout << "Enter Movie Title: ";
    getline(cin, *title);
	cout << "Enter Movie Genre: ";
	getline(cin, *genre);
	cout << "Enter Year Released: ";
    cin >> *year;
}
//fixed duplicate problem insert - allen
void MovieList::InsertNode(int code, string title, string genre, int year) {	
	MovieNode *newNode, *nodePtr, *previousNode;
 	newNode = new MovieNode();
	newNode->data.movie_code = code;
 	newNode->data.movie_title = title;
  newNode->data.movie_genre = genre;
  newNode->data.year_released = year;
	
	if (!head) {
		head = newNode;
		newNode->next = NULL;
	} else {
		nodePtr = head;
		previousNode = NULL;
		while (nodePtr != NULL && nodePtr->data.year_released < year) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (previousNode == NULL) {
			head = newNode;
			newNode->next = nodePtr;
		} else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
	cout << endl << "Movie has been successfully Inserted!" << endl;
}
void MovieList::rentInsert(int code, string title, string genre, int year){ //added this function - allen
  MovieNode *newNode, *nodePtr, *previousNode;
  int count = 0;
 	newNode = new MovieNode();
  newNode->data.movie_code = code;
  newNode->data.movie_title = title;
  newNode->data.movie_genre = genre;
  newNode->data.year_released = year;
  if (!rent_head) {
		rent_head = newNode;
		newNode->next = NULL;
	} else {
		nodePtr = rent_head;
		previousNode = NULL;
		while (nodePtr != NULL && nodePtr->data.year_released < year) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (previousNode == NULL) {
			rent_head = newNode;
			newNode->next = nodePtr;
		} else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
  nodePtr = rent_head;
  cout<<endl<<"<<Rented List>>"<<endl;
  while(nodePtr){
    count++;
    cout<<count<<".) "<<"Movie Code: "<<nodePtr->data.movie_code<<endl;
    nodePtr = nodePtr->next;
  }
  cout<<endl;
}

bool MovieList::rentReturn(int code){ //added this - allen
  MovieNode *nodePtr;
  if(rent_head){
    nodePtr = rent_head;
    while(nodePtr){
      if(nodePtr->data.movie_code == code){
        return true;
      }
      nodePtr = nodePtr->next;
    }
  }
  return false;
}

void MovieList::rentDelete(int code){ //added -allen
  MovieNode *nodePtr, *previousNode;
  string title;
  nodePtr = rent_head;
  int found = 0;
  if (rent_head == NULL){
    cout<<"The list is Empty!"<<endl;
    return;
  }
  if (rent_head->data.movie_code == code){
    nodePtr = rent_head->next;
    title = rent_head->data.movie_title;
    delete rent_head;
    rent_head = nodePtr;
    found = 1;
    cout<<"You Returned the Movie: "<< title <<endl;
  }
  else{
    nodePtr = rent_head;
    while(nodePtr != NULL){
      if(nodePtr->data.movie_code != code){
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
      }
      else{
        previousNode->next = nodePtr->next;
        title = nodePtr->data.movie_title;
        delete nodePtr;
        found = 1;
        cout<<"You Returned the Movie: "<< title <<endl;
        break;
      }
    }
    if (found == 0){
        cout<<"Couldn't find the movie." <<endl;
      }
  }
}
void MovieList::DeleteNode(int code) { //fixed bug deleting incorrect movie - allen
  MovieNode *nodePtr, *previousNode;
  int codes, year;
  string title, genre;
  nodePtr = head;
  int found = 0;
	
  if (head == NULL){
    cout<<"The list is Empty!"<<endl;
    return;
  }
  if (head->data.movie_code == code){
    nodePtr = head->next;
    codes = head->data.movie_code;
    title = head->data.movie_title;
    genre = head->data.movie_genre;
    year = head->data.year_released;
    rentInsert(code, title,genre,year);
    delete head;
    head = nodePtr;
    found = 1;
    cout<<"You Rented the Movie: "<< title <<endl;
  }
  else{
    nodePtr = head;
    while(nodePtr != NULL){
      if(nodePtr->data.movie_code != code){
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
      }
      else{
        previousNode->next = nodePtr->next;
        codes = nodePtr->data.movie_code;
        title = nodePtr->data.movie_title;
        genre = nodePtr->data.movie_genre;
        year = nodePtr->data.year_released;
        rentInsert(codes, title, genre, year);
        delete nodePtr;
        found = 1;
        cout<<"You Rented the Movie: "<< title <<endl;
        break;
      }
    }
    if (found == 0){
        cout<<"Couldn't find the movie." <<endl;
      }
  }
}

void MovieList::AppendNode(int code) { //changed
  MovieNode *nodePtr, *newNode;
  int codes;
  newNode  = new MovieNode();
  nodePtr = rent_head;
  while(nodePtr){
    if(nodePtr->data.movie_code == code){
      newNode->data.movie_code = nodePtr->data.movie_code;
      newNode->data.movie_title = nodePtr->data.movie_title;
      newNode->data.movie_genre = nodePtr->data.movie_genre;
      newNode->data.year_released = nodePtr->data.year_released;
      break;
    }
    nodePtr = nodePtr->next;
  }
  newNode->next = NULL;
  if (!head) {
    head = newNode;
   } 
  else {
    nodePtr = head;
    while (nodePtr->next) {
      nodePtr = nodePtr->next;
    }
    nodePtr->next = newNode;
  }
  rentDelete(code);
}

void MovieList::TraverseList(int code) { //fixed - allen
	MovieNode *nodePtr;
	nodePtr = head;	
    bool exist = false; //added this to check existence
	if(!head){
		cout<<"The Movie List is Empty";
        exist = true; //this makes sure that if statement below doesn't execute
	}else{
		
		while(nodePtr != NULL){
			if(nodePtr->data.movie_code != code){
					nodePtr = nodePtr->next;					
			}else{
                cout << "\nDetails of the chosen movie: " << endl;
				cout << "Movie Code: " << nodePtr->data.movie_code << endl;
				cout << "Movie Title: " << nodePtr->data.movie_title << endl;
				cout << "Movie Genre: " << nodePtr->data.movie_genre << endl;
				cout << "Year Released: " << nodePtr->data.year_released << endl;
                exist =true;
				break;
			}	
		}
	}

    if (!exist)
        cout<<"Movie Code doesn't Exist!"<<endl;
}

void MovieList::DisplayList(){  
  MovieNode *nodePtr;
	if(!head){
		cout<<"The Movie List is Empty!\a\n";
	}else{
	nodePtr = head;
		while(nodePtr!=NULL){	
			cout<<nodePtr->data.movie_code<<". ";
			cout<<nodePtr->data.movie_title<<endl;
			nodePtr = nodePtr -> next;
		}	
	}
}
