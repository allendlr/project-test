#include<iostream>
#include "implementation2.cpp"
#include "data2.h"
using namespace std;

int main(){
    MovieList ml;
    //Menu
    ml.appendNode(2, 1997, "Movie 1", "horror");
    ml.appendNode(4, 1987, "Movie 2", "comedy");
    ml.printList();
}