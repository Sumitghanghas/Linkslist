#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
using namespace std;

//-------node class-----/
template <typename v>
class Node {
public:
    v data;
    Node* next;
    Node(v value);
};
//-------linklist class----//
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
    Node<v>* prev(int index);
};

#include "source.cpp" 

#endif 
