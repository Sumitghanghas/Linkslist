#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
using namespace std;

//-------node class-----/
template <typename v>
class Node
{
public:
    v data;
    Node *next;
    Node(v value);
};
//-------linklist class----//
template <typename v>
class linkist
{
private:
    Node<v> *head;
    void destroy();

public:
    linkist();
    linkist(const linkist<v> &other);
    linkist<v> &operator=(const linkist<v> &other);
    void perpend(v value);
    void append(v value);
    void insert(int index, v value);
    void pop();
    void removeatstaring();
    void remove(int index);
    void print();
    Node<v> *prev(int index);
    ~linkist();
};

#include "source.cpp"

#endif
