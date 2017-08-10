#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include <iostream>
using namespace std;

class LinkedList
{
public:
    LinkedList():firstPtr(nullptr),lastPtr(nullptr){}
    void insertFirst(bool dat)
    {
        Node *newPtr= new Node(dat);
        if(isEmpty())
            firstPtr=lastPtr=newPtr;
        else
        {
            newPtr->nextPtr=firstPtr;
            firstPtr=newPtr;
        }
    }

    void insertLast(bool dat)
    {
        Node *newPtr=new  Node(dat);
        if(isEmpty())
            firstPtr=lastPtr=newPtr;
        else
        {
            lastPtr->nextPtr=newPtr;
            lastPtr=newPtr;
        }

    }
    void print()
    {
        Node *temPtr=firstPtr;
        while(temPtr)
        {
            if(temPtr->data)
                cout << "1" << endl;
            else
                cout << "0" << endl;
            temPtr=temPtr->nextPtr;
        }
    }

    bool isEmpty()
    {
        return firstPtr==nullptr;
    }

private:
    Node *firstPtr;
    Node *lastPtr;
    Node *getNewNode(bool &d)
    {
        return new Node(d);
    }
};

#endif // LINKEDLIST_H
