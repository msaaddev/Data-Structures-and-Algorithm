#include <iostream>
#include "node.cpp"
using namespace std;

class Tree
{
private:
    cNode *root;

public:
    Tree() : root(NULL){};
    Tree(cNode *&ptr) : root(ptr)
    {
        root->rightNode = root->leftNode = NULL;
        ptr = NULL;
    }
    Tree &insert(cNode *&ptr);
    int search(cNode *&ptr);
};

Tree &Tree::insert(cNode *&ptr)
{
    if (!root)
    {
        root = ptr;
        ptr = NULL;
        return *this;
    }
    cNode *rptr = root;
    while (rptr)
    {
        if (ptr->getValue() > rptr->getValue())
        {
            if (rptr->rightNode)
            {
                rptr = rptr->rightNode;
                cout << "\nright";
            }
            else
            {
                rptr->rightNode = ptr;
                ptr = NULL;
                cout << "\nright";

                return *this;
            }
        }
        else
        {
            if (rptr->leftNode)
            {
                rptr = rptr->leftNode;
                cout << "\nleft";
            }
            else
            {
                rptr->leftNode = ptr;
                ptr = NULL;
                cout << "\nleft";

                return *this;
            }
        }
    }
}

int Tree::search(cNode *&ptr)
{
    int level = -1;
    cNode *temp = root;

    while (temp->leftNode != NULL || temp->rightNode != NULL)
    {

        level++;
        if (temp->getValue() < ptr->getValue())
        {
            temp = temp->rightNode;
            if (temp->getValue() == ptr->getValue())
                return level;
        }
        else if (temp->getValue() > ptr->getValue())
        {
            temp = temp->leftNode;
            if (temp->getValue() == ptr->getValue())
                return level;
        }
        else if (temp->getValue() == ptr->getValue())
        {
            return level;
        }
        else
        {
            cout << "\n\nNode does not exist.\n\n";
            return -1;
        }
    }
}
