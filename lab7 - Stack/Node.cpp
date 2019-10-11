#include <iostream>
using namespace std;

class Node
{
    int value;
    Node  *next;

public:
    void setValue(int v)
    {
        value = v;
    }

    // void setNextNode(Node *nn)
    // {
    //     nextNode = nn;
    // }

    void setNext(Node *nn)
    {
        next = nn;
    }

    int getValue()
    {
        return value;
    }

    // Node *getNextNode()
    // {
    //     return nextNode;
    // }

    Node *getNext()
    {
        return next;
    }
};