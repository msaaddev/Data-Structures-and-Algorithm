#include <iostream>
using namespace std;

class Node
{
    char value;
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

    char getValue()
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