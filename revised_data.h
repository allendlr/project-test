#ifndef MOVIELIST_H
#define MOVIELIST_H
#include <iostream>
#pragma once
using namespace std;

struct Movie {
  int movie_code = 0;
  string movie_title;
  string movie_genre;
  int year_released = 0;
};

class MovieList {
 private:
   struct MovieNode {
     Movie mov[100];
     Movie data;
     MovieNode *next = NULL;
   };
    MovieNode *head = NULL;
    int id = 0;
 public:
  // Constructor
   MovieList();
  // Insert a Movie
   void InsertNode(int code, string title, string genre, int year);
  // Rent a Movie
   void DeleteNode(int code);
  // Return a Movie
   void AppendNode(int code, string title, string genre, int year);
  // Show Movie Details
   void TraverseList(int code);
  // Print Movie List
   void DisplayList();
  // Destructor
  ~MovieList();
};



#endif
