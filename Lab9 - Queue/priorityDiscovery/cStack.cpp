#include <iostream>
#include "node.cpp"
using namespace std;

class cStack
{
protected:
    cNode *top;

public:
    cStack() : top(NULL){};
    cStack(cNode *ptr) : top(ptr)
    {
        top->nextNode = NULL;
        ptr = NULL;
    }

    cStack(const cStack &src)
    {
        this->top = src.top;
        if (src.top)
        {
            cNode *sptr, *dptr;
            dptr = top = new cNode(*src.top);
            sptr = src.top->nextNode;
            while (sptr)
            {
                dptr->nextNode = new cNode(*sptr);
                sptr = sptr->nextNode;
                dptr = dptr->nextNode;
            }
        }
    }

    cStack &operator=(const cStack &rObj)
    {
        if (this == &rObj)
            return *this;

        if (true)
        {
            cStack temp;
            temp.top = top;
        }

        if (true)
        {
            cStack temp = rObj;
            top = temp.top;
            temp.top = NULL;
        }

        return *this;
    }

    bool isNotEmpty() const
    {
        if (top)
            return true;
        else
            return false;
    }

    bool isEmpty() const
    {
        if (top)
            return false;
        else
            return true;
    }

    cStack &push(cNode *&ptr)
    {
        ptr->nextNode = top;
        top = ptr;
        ptr = NULL;
        return *this;
    }

    cNode *pop()
    {
        cNode *ptr = top;
        top = top->nextNode;
        ptr->nextNode = NULL;
        return ptr;
    }

    void print()
    {
        if (isNotEmpty())
        {
            cNode *ptr = top;
            while (ptr)
            {
                cout << "Values: " << ptr->getData() << endl;
                ptr = ptr->nextNode;
            }
        }
    }
};