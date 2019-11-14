#include <iostream>
#include "queue.cpp"
using namespace std;

class cPriorityQue : protected cQue
{
public:
    cPriorityQue() {}
    cPriorityQue(cNode *ptr) : cQue(ptr) {}

    cPriorityQue(const cPriorityQue &src)
    {
        this->top = src.top;
        this->tail = src.tail;
        if (src.top)
        {
            cNode *dptr, *sptr;
            dptr = top = new cNode(*src.top);
            sptr = src.top->nextNode;
            while (sptr)
            {
                dptr->nextNode = new cNode(*sptr);
                dptr = dptr->nextNode;
                sptr = sptr->nextNode;
            }
            tail = dptr;
        }
    }

    cPriorityQue &insertWithPriority(cNode *&ptr)
    {
        if (!top)
        {
            top = tail = ptr;
            tail->nextNode = ptr = NULL;
        }
        else if (top->getPriority() < ptr->getPriority())
        {
            cStack::push(ptr);
        }
        else if (tail->getPriority() >= ptr->getPriority())
        {
            cQue::enqueue(ptr);
        }
        else
        {
            cNode *rptr = top;
            while (rptr->getPriority() >= ptr->getPriority())
            {
                rptr = rptr->nextNode;
            }

            cNode *aptr = top;
            while (aptr->nextNode != rptr)
            {
                aptr = aptr->nextNode;
            }
            aptr->nextNode = ptr;
            ptr->nextNode = rptr;
            ptr = NULL;
        }
        return *this;
    }

    bool isNotEmpty()
    {
        return cQue::isNotEmpty();
    }

    bool isEmpty()
    {
        return cQue::isEmpty();
    }

    cNode *dequeue()
    {
        return cQue::dequeue();
    }

    cNode *returnHead()
    {
        return cQue::returnHead();
    }

    cNode *returnTail()
    {
        return cQue::returnTail();
    }

    int getHighestPriority()
    {
        int max = top->getPriority();
        cNode *rptr = top->nextNode;
        while (rptr != NULL)
        {
            if (max < rptr->getPriority())
                max = rptr->getPriority();

            rptr = rptr->nextNode;
        }

        rptr = NULL;
        return max;
    }

    void print() const
    {
        cQue::print();
    }

    ~cPriorityQue()
    {
        cNode *ptr = top;
        tail = NULL;
        while (ptr)
        {
            ptr = ptr->nextNode;
            delete top;
            top = ptr;
        }
    }
};