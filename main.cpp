#include "LinkList.h"

#include <iostream>
using namespace std;

int main()
{
    linkist<int> myList;

    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);
    myList.print();

    myList.remove(1);
        myList.insert(2,10);    

    myList.print();

    return 0;
}
