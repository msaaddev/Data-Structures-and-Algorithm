#include <iostream>
using namespace std;

class cNode
{
    int value;

public:
    cNode *leftNode, *rightNode;
    cNode() : leftNode(NULL), rightNode(NULL) {}
    cNode(int val) : leftNode(NULL), rightNode(NULL) { value = val; }
    void setData(int v)
    {
        value = v;
    }

    int getValue()
    {
        return value;
    }

    cNode *getLeftNode()
    {
        return leftNode;
    }

    cNode *getRightNode()
    {
        return rightNode;
    }
};