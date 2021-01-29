#include "data2.h"
#include <iostream>
using namespace std;

MovieList::MovieList(){
    head = NULL;
}

void MovieList::appendNode(int num, int year, string title, string genre){
    node *nodePtr, *newNode;
    newNode = new node;
    newNode->year = year;
    newNode->num = num;
    newNode->title = title;
    newNode->genre = genre;
    newNode->next = NULL;

    if (head == NULL){
        head = newNode;
    }
    else{
        nodePtr = head;
        while(nodePtr->next)
            nodePtr = nodePtr->next;
        nodePtr->next = newNode;
    }
    cout<<"added " << num <<" "
        << year << " "
        << title << " "
        << genre << " "
        <<endl;
}

void MovieList::printList(){
    node *nodePtr;
    if (head == NULL)
        cout<<"empty";
    else {
        nodePtr = head;
        while(nodePtr){
            cout<<nodePtr->year <<" "
                <<nodePtr->num <<" "
                <<nodePtr->title<< " "
                <<nodePtr->genre;
            nodePtr= nodePtr->next;
            cout<<endl;
        }
    }

}
