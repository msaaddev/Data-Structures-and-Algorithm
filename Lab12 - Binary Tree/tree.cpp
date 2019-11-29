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
    bool isEmpty();
    bool isNotEmpty();
    Tree &insert(cNode *&ptr);
    int search(cNode *&ptr);
    void printPreOrder();
    void printPostOrder();
    void printInfixOrder();
    int smallestKey();
    int largestKey();
};

bool Tree::isEmpty()
{
    if (!root)
        return true;
    else
        return false;
}

bool Tree::isNotEmpty()
{
    if (!root)
        return false;
    else
        return true;
}

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

void Tree::printPreOrder()
{
    void prtPreOrder(cNode * root);

    if (!root)
        cout << "\nEmpty Tree\n";
    else
        prtPreOrder(root);
}

void prtPreOrder(cNode *root)
{
    if (root)
    {
        root->print();
        prtPreOrder(root->leftNode);
        prtPreOrder(root->rightNode);
    }
}

void Tree::printPostOrder()
{
    void prtPostOrder(cNode * root);

    if (!root)
        cout << "\nEmpty Tree\n";
    else
        prtPostOrder(root);
}

void prtPostOrder(cNode *root)
{
    if (root)
    {
        prtPostOrder(root->leftNode);
        prtPostOrder(root->rightNode);
        root->print();
    }
}

void Tree::printInfixOrder()
{
    void prtInfixOrder(cNode * root);

    if (!root)
        cout << "\nEmpty Tree\n";
    else
        prtInfixOrder(root);
}

void prtInfixOrder(cNode *root)
{
    if (root)
    {
        prtInfixOrder(root->leftNode);
        root->print();
        prtInfixOrder(root->rightNode);
    }
}

int Tree::smallestKey()
{
    cNode *rptr = root;
    cNode *bptr;
    while (rptr)
    {
        bptr = rptr;
        rptr = rptr->leftNode;
    }

    return bptr->getValue();
}
