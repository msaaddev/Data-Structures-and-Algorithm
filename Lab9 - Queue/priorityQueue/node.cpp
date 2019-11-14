#include <iostream>
using namespace std;

class cNode
{
private:
    int data;
    int priority;

public:
    cNode *nextNode;

    cNode() {}

    cNode(int d) : data(d) {}

    int getData() const { return data; }

    void *setData(int data) { this->data = data; }

    void setPriority(int prior)
    {
        priority = prior;
    }

    int getPriority()
    {
        return priority;
    }

    void printPriority() const
    {
        cout << priority << " ";
    }

    void print() const { cout << data << " "; }
};