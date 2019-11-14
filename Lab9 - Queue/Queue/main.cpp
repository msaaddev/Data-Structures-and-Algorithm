#include <iostream>
#include "queue.cpp"
using namespace std;

int main()
{
    cQue queue;

    if (queue.isEmpty())
    {
        cout << "Queue is Empty\n\n";
    }
    else
    {
        cout << "Queue is not Empty\n\n";
    }

    cNode *node1 = new cNode(12);

    queue.enqueue(node1);

    // queue.print();

    cNode *node2 = new cNode();
    node2->setData(13);
    cNode *node3 = new cNode();
    node3->setData(14);
    cNode *node4 = new cNode();
    node4->setData(20);
    cNode *node5 = new cNode();
    node5->setData(24);

    queue.enqueue(node2).enqueue(node3).enqueue(node4).enqueue(node5);

    queue.print();

    queue.dequeue();
    cout << endl
         << endl;
    queue.print();

    queue.dequeue();
    cout << endl
         << endl;
    queue.print();

    cQue anotherQueue(queue);

    cout << endl
         << endl
         << "This is the copy of queue.\n";
    anotherQueue.print();
}