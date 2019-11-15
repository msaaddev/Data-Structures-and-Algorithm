#include <iostream>
using namespace std;

class cNode
{
    int value;

public:
    cNode *leftNode, *rightNode;
    void setValue(int v)
    {
        value = v;
    }

    // void s(cNode *nn)
    // {
    //     leftNode = nn;
    // }

    // void setPrevNode(cNode *pn)
    // {
    //     prevNode = pn;
    // }

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