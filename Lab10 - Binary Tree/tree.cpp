#include <iostream>
#include "node.cpp"
using namespace std;

class Tree
{
private:
    cNode *root;

public:
    Tree() : root(NULL){};
    Tree(cNode *&ptr) : root(ptr) {}
    Tree &insert(cNode *&ptr);
};

Tree::Tree(cNode *&ptr) : root(ptr)
{
    root->rightNode = root->leftNode = NULL;
    ptr = NULL;
}

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
                if (temp->rightNode == NULL)
                    break;
            }
            else if (temp->getValue() > ptr->getValue())
            {
                temp = temp->leftNode;
                if (temp->leftNode == NULL)
                    break;
            }
            else
            {
                cout << "\n\nNode already exists.\n\n";
                break;
            }
        }

        if (temp->getValue() < ptr->getValue())
        {
            temp->rightNode = ptr;
        }
        else if (temp->getValue() > ptr->getValue())
        {
            temp->leftNode = ptr;
        }

        temp = NULL;
    }

    return *this;
}
