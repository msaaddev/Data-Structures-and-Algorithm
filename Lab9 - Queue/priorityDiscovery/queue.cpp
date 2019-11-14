#include <iostream>
#include "cStack.cpp"
using namespace std;

class cQue : protected cStack
{
protected:
    cNode *tail;

public:
    cQue() : tail(NULL) {}
    cQue(cNode *&ptr) : cStack(ptr), tail(top)
    {
        tail->nextNode = NULL;
        ptr = NULL;
    }

    cQue(const cQue &src)
    {
        this->top = src.top;
        this->tail = src.tail;
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

            tail = dptr;
        }
    }

    bool isNotEmpty()
    {
        return cStack::isNotEmpty();
    }

    bool isEmpty()
    {
        return cStack::isEmpty();
    }

    cNode *dequeue()
    {
        if (!(top->nextNode))
        {
            tail = NULL;
        }
        else
        {
            return cStack::pop();
        }
    }

    cQue &enqueue(cNode *&ptr)
    {
        if (tail)
        {
            tail->nextNode = ptr;
            tail = tail->nextNode;
        }
        else
            tail = top = ptr;

        tail->nextNode = NULL;
        ptr = NULL;
        return *this;
    }


    cNode *returnHead()
    {
        return top;
    }

    cNode *returnTail()
    {
        return tail;
    }

    void print()
    {
        cStack::print();
    }
};
