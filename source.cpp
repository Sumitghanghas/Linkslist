#include "LinkList.h"
template <typename v>
Node<v>::Node(v value)
{
    data = value;
    next = nullptr;
}

template <typename v>
linkist<v>::linkist()
{
    head = nullptr;
}

template <typename v>
linkist<v>::linkist(const linkist<v> &other)
{
    head = nullptr;
    if (!other.head)
        return;

    head = new Node<v>(other.head->data);
    Node<v> *current = head;
    Node<v> *otherCurrent = other.head->next;

    while (otherCurrent)
    {
        current->next = new Node<v>(otherCurrent->data);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
}

template <typename v>
linkist<v> &linkist<v>::operator=(const linkist<v> &other)
{
    if (this == &other)
        return *this;

    destroy();

    if (!other.head)
    {
        head = nullptr;
        return *this;
    }

    head = new Node<v>(other.head->data);
    Node<v> *current = head;
    Node<v> *otherCurrent = other.head->next;

    while (otherCurrent)
    {
        current->next = new Node<v>(otherCurrent->data);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }

    return *this;
}

template <typename v>
void linkist<v>::destroy()
{
    Node<v> *current = head;
    while (current)
    {
        Node<v> *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

template <typename v>
void linkist<v>::perpend(v value)
{
    Node<v> *newNode = new Node<v>(value);
    newNode->next = head;
    head = newNode;
}

template <typename v>
void linkist<v>::append(v value)
{
    Node<v> *newNode = new Node<v>(value);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node<v> *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

template <typename v>
void linkist<v>::insert(int index, v value)
{
    if(index < 0){
        cout<<"Index is out of bound : "<<index<<"  value is not insert in the linklist :"<<value<<endl;
    }
    Node<v> *newNode = new Node<v>(value);
    if (index == 0 || !head)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node<v> *prevNode = prev(index);
    if (!prevNode || !prevNode->next)
        return;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

template <typename v>
void linkist<v>::pop()
{
    if (!head)
        return;
    if (!head->next)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node<v> *temp = head;
    while (temp->next->next)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

template <typename v>
void linkist<v>::removeatstaring()
{
    if (!head)
        return;
    Node<v> *temp = head;
    head = head->next;
    delete temp;
}

template <typename v>
void linkist<v>::remove(int index)
{
    if (!head || index < 0)
        return;

    if (index == 0)
    {
        Node<v> *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node<v> *prevNode = prev(index);
    if (!prevNode || !prevNode->next){
        cout<<"Index is greater then the size : "<<index<<endl;
        return;
    }

    Node<v> *deletenode = prevNode->next;
    prevNode->next = deletenode->next;
    delete deletenode;
}

template <typename v>
void linkist<v>::print()
{
    Node<v> *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
template <typename v>
Node<v> *linkist<v>::prev(int index)
{
    // cout<<index<<endl;
    Node<v> *temp = head;
    int count = 0;
    while (temp && count < index - 1)
    {
        temp = temp->next;
        count++;
    }
    return temp;
}

template <typename v>
linkist<v>::~linkist()
{
    destroy();
}