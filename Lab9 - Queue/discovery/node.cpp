#include <iostream>
using namespace std;

class cNode
{
private:
    int data;

public:
    cNode *nextNode;

    cNode() {}

    cNode(int d) : data(d) {}

    int getData() const { return data; }

    void *setData(int data) { this->data = data; }

    void print() const { cout << data << " "; }
};