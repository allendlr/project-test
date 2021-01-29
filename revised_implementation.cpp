#include <iostream>
#include <string.h>
#include "data.h"
using namespace std;

char menu(){
  cout << " << JubiLoop's Movie Menu >> " << endl << endl;
    cout << "[1] Insert a New Movie " << endl;
    cout << "[2] Rent a Movie" << endl;
    cout << "[3] Return a Movie" << endl;
    cout << "[4] Show Movie Details" << endl;
    cout << "[5] Print Movie List" << endl;
    cout << "[6] Quit the Program" << endl << endl;    
    char ch;
    cout << "Enter Choice: ";
    cin >> ch;
    return ch;
}

MovieList::MovieList() {
	head = NULL;
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

void MovieList::InsertNode(int code, string title, string genre, int year) {
	MovieNode *newNode, *nodePtr;
  newNode = new MovieNode();
	newNode->mov[id].movie_code = code;
  newNode->mov[id].movie_title = title;
  newNode->mov[id].movie_genre = genre;
  newNode->mov[id].year_released = year;
  
	if (!head) {
		head = newNode;
  } else {
		nodePtr = head;
		while (nodePtr->next) {
			nodePtr = nodePtr->next;
    }
		nodePtr->next = newNode;
	}
  id++;
	cout << endl << "Movie has been successfully Inserted!" << endl;
}

void MovieList::DeleteNode(int code) { //Done
  MovieNode *nodePtr, *previousNode;
  nodePtr = head;
  int found = 0;
  if (head == NULL){
    cout<<"The list is Empty!"<<endl;
    return;
  }
  if (head->data.movie_code == code){
    cout<<"found";
    nodePtr = head->next;
    delete head;
    head = nodePtr;
    found = 1;
  }
  else{
    nodePtr = head;
    while(nodePtr != NULL){
      if(nodePtr->data.movie_code != code){
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
      }
      if(nodePtr){
        previousNode->next = nodePtr->next;
        delete nodePtr;
        cout<<"You Deleted the movie." <<endl;
        found = 1;
      }
      if (found == 0){
        cout<<"Couldn't find the movie." <<endl;
      }
    }
  }
}

void MovieList::AppendNode(int code, string title, string genre, int year) {
  MovieNode *nodePtr, *newNode;
  newNode  = new MovieNode();
  newNode->next = NULL;
  newNode->data.movie_code = code;
  newNode->data.movie_title = title;
  newNode->data.movie_genre = genre;
  newNode->data.year_released = year;
  
  if (!head) {
		head = newNode;
  } else {
		nodePtr = head;
		while (nodePtr->next) {
			nodePtr = nodePtr->next;
    }
		nodePtr->next = newNode;
	}
 
}

void MovieList::TraverseList(int code) {
  /*
  MovieNode *nodePtr;
	if (head == NULL) {
		cout << "The movie list is empty!" << endl;
  } else {
		nodePtr = head;
    bool checker = false;
    int tmp = 0;
    for (int i = 0; i < id; i++) {
      while (nodePtr != NULL) {
        if (code == nodePtr->mov[i].movie_code) {
          checker = true;
          tmp = i;
          break;
        } else {
          nodePtr = nodePtr->next;
        }
      }
      if (checker) {
        break;
      } else {
        nodePtr = head;
      }
    }
    if (checker) {
      cout << "\nDetails of the chosen movie: " << endl;
      cout << "Movie Code: " << nodePtr->mov[tmp].movie_code << endl;
      cout << "Movie Title: " << nodePtr->mov[tmp].movie_title << endl;
      cout << "Movie Genre: " << nodePtr->mov[tmp].movie_genre << endl;
      cout << "Year Released: " << nodePtr->mov[tmp].year_released << endl;
    } else {
      cout << "Movie does not exist." << endl;
    }
	}
  */
  
  MovieNode *nodePtr;
	nodePtr = head;
	cout << "\nDetails of the chosen movie: " << endl;
	while(nodePtr){
		if(code == nodePtr->data.movie_code){
	    	cout << "Movie Code: " << nodePtr->data.movie_code << endl;
	    	cout << "Movie Title: " << nodePtr->data.movie_title << endl;
	    	cout << "Movie Genre: " << nodePtr->data.movie_genre << endl;
	    	cout << "Year Released: " << nodePtr->data.year_released << endl;
	    	break;
		}else{
			nodePtr = nodePtr->next;
		}
	}
}

void MovieList::DisplayList() {
  
  /*
	MovieNode *nodePtr;
	if (head == NULL) {
		cout << "The movie list is empty!" << endl;
  } else {
		cout << "The movies in the list are: " << endl;
		nodePtr = head;
    for (int i = 0; i < id; i++) {
      cout << i + 1 << ". ";
      while (nodePtr != NULL) {
        cout << nodePtr->mov[i].movie_title;
        nodePtr = nodePtr->next;
      }
      cout << endl;
      nodePtr = head;
    }
	}
  */
  
  MovieNode *nodePtr;
	
	nodePtr = head;
	while(nodePtr!=NULL){	
		cout<<nodePtr->data.movie_code<<". ";
		cout<<nodePtr->data.movie_title<<endl;
		nodePtr = nodePtr -> next;
	}
}
