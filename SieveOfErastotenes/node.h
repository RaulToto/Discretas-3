#ifndef NODE_H
#define NODE_H

#include "linkedlist.h"
class Node
{
    friend class LinkedList;
public:
    Node(bool &d):nextPtr(nullptr),data(d){}

    bool getData()
    {
        return this->data;
    }

private:
    Node *nextPtr;
    bool data;
};

#endif // NODE_H
