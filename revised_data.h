#ifndef MOVIELIST_H
#define MOVIELIST_H
#include <iostream>
#pragma once
using namespace std;

struct Movie {
  int movie_code = 0;
  string movie_title = " ";
  string movie_genre = " ";
  int year_released = 0;
};

class MovieList {
	private:
	struct MovieNode {
		Movie data;
		MovieNode *next;
   };
	MovieNode *rent_head;
	MovieNode *head;
		public:

		// Constructor
		MovieList();
		// Insert a Movie
		void InsertNode(int code, string title, string genre, int year);
		// Rent a Movie
		void DeleteNode(int code);
		void rentInsert(int code, string title, string genre,int year);
		void rentDelete(int code);
		// Return a Movie
		void AppendNode(int code);
		bool rentReturn(int code);
		// Show Movie Details
		void TraverseList(int code);
		// Print Movie List
		void DisplayList();
    bool isDuplicate(int code);
		void getCode(int* code);
		void getMovieData(string* title, string* genre, int* year);
		// Destructor
		~MovieList();
}; 
#endif
