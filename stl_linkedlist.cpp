#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> myList;
    list<int>::iterator iter;

    for(int i = 0; i <= 100; i+=10){
        myList.push_back(i);
    }

    for(iter = myList.begin(); iter != myList.end(); iter++){
        cout<<*iter<<endl;
    }
}