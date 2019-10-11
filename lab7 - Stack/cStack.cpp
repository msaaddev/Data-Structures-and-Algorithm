
//Added Node.cpp file
#include "Node.cpp"
#include <iostream>

using namespace std;

class CStack
{
    Node *top;
    int size;

public:
    CStack()
    {
        top = NULL;
        size = 0;
    }

    void push(int value)
    {
        if (!top)
        {
            Node *newNode = new Node();
            top = newNode;
            newNode->setValue(value);
            newNode->setNext(0);
            size++;
        }
        else
        {
            Node *newNode = new Node();
            newNode->setNext(top);
            top = newNode;
            newNode->setValue(value);
            size++;
        }
    }

    int pop()
    {
        if (stackIsEmpty())
        {
            cout << "There is nothing in the stack.";
        }
        else
        {
            int value = topGetValue();
            Node *temp = top;
            top = top->getNext();
            delete temp;
            return value;
        }
    }

    bool stackIsEmpty()
    {
        if (top)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    int topGetValue()
    {
        return top->getValue();
    }
};