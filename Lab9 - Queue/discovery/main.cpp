#include <iostream>
#include "queue.cpp"
using namespace std;

int main()
{
    cQue queue[10];

    for (int i = 0; i < 10; i++)
    {
        cNode *nodes = new cNode[18];
        for (int j = 1; j <= 18; j++)
        {
            nodes[j].setData(j + i);
            cNode *newNode = &nodes[j];
            queue[i].enqueue(newNode);

            if (queue[i].getCount() == 18)
            {
                cout << endl
                     << "Queue " << i + 1 << " " << endl;
                queue[i].print();
            }
        }

        delete[] nodes;
    }
}