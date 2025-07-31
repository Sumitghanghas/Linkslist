
#include <iostream>
using namespace std;

template <typename v>
class Node {
public:
    v data;
    Node* next;
    Node(v value);
};

template <typename v>
class linkist {
private:
    Node<v>* head;

public:
    linkist();
    void perpend(v value);
    void append(v value);
    void insert(int index, v value);
    void pop();
    void removeatstaring();
    void remove(int index);
    void print();
};

#include "linklistfun.h" 

