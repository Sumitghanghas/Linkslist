#include "LinkList.h"

#include <iostream>
using namespace std;

int main()
{
    linkist<int> myList;

    myList.append(10);
    myList.append(20);
    myList.perpend(5);
    myList.insert(1, 15);  
    myList.print();       

     

    return 0;
}
