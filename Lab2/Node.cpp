#include <iostream>
using namespace std;

class Node
{
    int value;
    Node *nextNode;

public:
    void setValue(int v)
    {
        value = v;
    }

    void setNextNode(Node *nn)
    {
        nextNode = nn;
    }

    int getValue()
    {
        return value;
    }
    Node *getNextNode()
    {
        
    }
};