#include "LinkList.h"
#include <iostream>
using namespace std;

int main() {
    linkist<int> myList;

    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);
    myList.insert(-1,10);
    myList.remove(10);
    myList.print();
    

    linkist<int> newList = myList; 
    newList.print();

    newList.remove(1);
    newList.insert(2, 10);
    newList.print();

    myList.print();

    linkist<int> b;
    b = myList;
    b.append(88);
    b.print();
    myList.print();


    return 0;
}
