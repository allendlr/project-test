#ifndef MOVIELIST_H
#define MOVIELIST_H
#pragma once
using namespace std;
class MovieList{
    private:
        struct node{
            int num, year;
            string title, genre;
            node *next;
        };
        node *head;
    public:
        MovieList();
        void appendNode(int num, int year, string title, string genre);
        void deleteNode();
        void printList();
};
#endif