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
    cNode *smallestNode(cNode *temp);
    int largestKey();
    cNode *removeNode(cNode *&ptr);
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
            }
            else
            {
                rptr->rightNode = ptr;
                ptr = NULL;

                return *this;
            }
        }
        else
        {
            if (rptr->leftNode)
            {
                rptr = rptr->leftNode;
            }
            else
            {
                rptr->leftNode = ptr;
                ptr = NULL;
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

cNode *Tree::smallestNode(cNode *temp)
{
    cNode *rptr = temp;
    cNode *bptr;
    while (rptr)
    {
        bptr = rptr;
        rptr = rptr->leftNode;
    }

    return bptr;
}

int Tree::largestKey()
{
    cNode *rptr = root;
    cNode *bptr;
    while (rptr)
    {
        bptr = rptr;
        rptr = rptr->rightNode;
    }

    return bptr->getValue();
}

cNode *Tree::removeNode(cNode *&ptr)
{
    cNode *rptr = root;

    if (rptr == NULL)
    {
        return;
    }
    if (rptr->getValue() > ptr->getValue())
        rptr->leftNode = removeNode(rptr->leftNode);
    else if (rptr->getValue() < ptr->getValue())
        rptr->rightNode = removeNode(rptr->rightNode);
    else
    {
        if (rptr->leftNode == NULL && rptr->rightNode != NULL)
        {
            cNode *newPtr = ptr->rightNode;
            free(ptr);
            return newPtr;
        }
        else if (rptr->rightNode == NULL && rptr->leftNode != NULL)
        {
            cNode *newPtr = ptr->leftNode;
            free(ptr);
            return newPtr;
        }

        cNode *newPtr = smallestNode(ptr->rightNode);
        ptr->setData(newPtr->getValue());
        rptr->rightNode = removeNode(rptr->rightNode);
    }

    return ptr;
}
