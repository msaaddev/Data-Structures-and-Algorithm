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
    cNode *search(cNode *&ptr, cNode *&temp, cNode *&rptr);
    void printPreOrder();
    void printPostOrder();
    void printInfixOrder();
    cNode *smallestNode(cNode *temp);
    cNode *largestNode(cNode *temp);
    cNode *removeNode(int value);
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

cNode *Tree::search(cNode *&ptr, cNode *&temp, cNode *&rptr)
{
    temp = root;

    while (temp->leftNode != NULL || temp->rightNode != NULL)
    {
        rptr = temp;
        if (temp->getValue() < ptr->getValue())
        {
            temp = temp->rightNode;
            if (temp->getValue() == ptr->getValue())
                return temp;
        }
        else if (temp->getValue() > ptr->getValue())
        {
            temp = temp->leftNode;
            if (temp->getValue() == ptr->getValue())
                return temp;
        }
        else if (temp->getValue() == ptr->getValue())
        {
            return temp;
        }
        else
        {
            cout << "\n\nNode does not exist.\n\n";
            return NULL;
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

cNode *Tree::largestNode(cNode *temp)
{
    cNode *rptr = temp;
    cNode *bptr;
    while (rptr)
    {
        bptr = rptr;
        rptr = rptr->rightNode;
    }
    return bptr;
}

/* void *Tree::removeNode(cNode *&ptr)
{
    cNode *rptr;
    cNode *result = this->search(ptr, result, rptr);

    if (result->leftNode == NULL && result->rightNode == NULL)
        delete result;
    else if (result->leftNode == NULL && result->rightNode != NULL)
    {
        if (rptr->getValue() > result->getValue())
        {
            rptr->leftNode = result->rightNode;
            delete result;
        }
        else
        {
            rptr->rightNode = result->rightNode;
            delete result;
        }
    }
    else if (result->leftNode != NULL && result->rightNode == NULL)
    {
        if (rptr->getValue() > result->getValue())
        {
            rptr->leftNode = result->leftNode;
            delete result;
        }
        else
        {
            rptr->rightNode = result->leftNode;
            delete result;
        }
    }
    else
    {
        if (rptr->getValue() < root->getValue())
        {
            if (rptr->getValue() < result->getValue())
            {
                cNode *temp = smallestNode(result);
                rptr->rightNode = temp;
                temp->rightNode = result->rightNode;
                delete result;
            }
            else
            {
                cNode *temp = largestNode(result);
                rptr->leftNode = temp;
                temp->leftNode = result->leftNode;
                delete result;
            }
        }
        else
        {
            if (rptr->getValue() < result->getValue())
            {
                cNode *temp = smallestNode(result);
                rptr->rightNode = temp;
                temp->rightNode = result->rightNode;
                delete result;
            }
            else
            {
                cNode *temp = largestNode(result);
                rptr->leftNode = temp;
                temp->leftNode = result->leftNode;
                delete result;
            }
        }
    }
}
 */

cNode *Tree::removeNode(int value)
{
    cNode *ptr = NULL;
    ptr = root;
    cNode *bptr = NULL;
    if (ptr == NULL)
    {
        cout <<"\nTree is empty.\n";
        return NULL;
    }

    while(ptr)
    {
        if (ptr->getValue() == value)
        {
            cNode *rptr = ptr;
            if(!ptr->leftNode)
            {
                if (!bptr)
                {
                    /* code */
                }

            }
        }

    }
}