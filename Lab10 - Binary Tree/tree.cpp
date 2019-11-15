#include <iostream>
#include "node.cpp"
using namespace std;

class Tree
{
private:
    cNode *root;

public:
    Tree &insert(cNode *&ptr);
};

Tree &Tree::insert(cNode *&ptr)
{
    if (!root)
    {
        root = ptr;
        root->rightNode = root->leftNode = NULL;
        ptr = NULL;
    }
    else
    {
        cNode *temp = root;
        while (temp->leftNode != NULL && temp->getRightNode != NULL)
        {
            if (temp->getValue() < ptr->getValue())
            {
                temp = temp->rightNode;
            }
            else
            {
                temp = temp->leftNode;
            }
        }

        if (temp->getValue() < ptr->getValue())
        {
            temp->rightNode = ptr;
        }
        else
        {
            temp->leftNode = ptr;
        }
    }
}