#include <iostream>
#include "priorityQueue.cpp"
using namespace std;

int main()
{
    cPriorityQue queue[10];

    for (int i = 0; i < 10; i++)
    {
        cNode *nodes = new cNode[18];

        for (int j = 0; j < 18; j++)
        {
            nodes[j].setData(j + i + 1);
            nodes[j].setPriority(j + i + 1);
            cNode *newNode = &nodes[j];
            queue[i].insertWithPriority(newNode);
        }

        cout << endl
             << "Queue " << i + 1 << endl
             << endl;
        queue[i].print();
        delete[] nodes;
    }

    cNode *newNode = new cNode(31);
    newNode->setPriority(100);

    queue[0].insertWithPriority(newNode);
    cout << "\n\nPrint Queue 0 again\n\n";
    queue[0].print();
}