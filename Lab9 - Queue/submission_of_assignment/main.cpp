#include <iostream>
#include "priorityQueue.cpp"
using namespace std;

int main()
{
    cPriorityQue queue;

    if (queue.isEmpty())
    {
        cout << "Queue is Empty\n\n";
    }
    else
    {
        cout << "Queue is not Empty\n\n";
    }

    cNode *node1 = new cNode("Saad");
    node1->setPriority(1);

    cNode *node2 = new cNode();
    node2->setName("John");
    node2->setPriority(2);

    cNode *node3 = new cNode();
    node3->setName("Sheldon");
    node3->setPriority(3);

    cNode *node4 = new cNode();
    node4->setName("Leonard");
    node4->setPriority(4);

    cNode *node5 = new cNode();
    node5->setName("Justin");
    node5->setPriority(5);

    queue.insertWithPriority(node1).insertWithPriority(node2).insertWithPriority(node3).insertWithPriority(node4).insertWithPriority(node5);

    queue.print();


}