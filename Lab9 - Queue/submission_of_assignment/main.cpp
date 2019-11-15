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

    cNode *node6 = new cNode();
    node6->setName("Arthur");
    node6->setPriority(6);

    cNode *node7 = new cNode();
    node7->setName("Donald");
    node7->setPriority(7);

    cNode *node8 = new cNode();
    node8->setName("Gabby");
    node8->setPriority(8);

    cNode *node9 = new cNode();
    node9->setName("Mike");
    node9->setPriority(9);

    cNode *node10 = new cNode();
    node10->setName("Betty");
    node10->setPriority(10);

    cNode *node11 = new cNode();
    node11->setName("Shad");
    node11->setPriority(11);

    queue.insertWithPriority(node1).insertWithPriority(node2).insertWithPriority(node3).insertWithPriority(node4).insertWithPriority(node5).insertWithPriority(node6).insertWithPriority(node7).insertWithPriority(node8).insertWithPriority(node9).insertWithPriority(node10).insertWithPriority(node11);

    queue.print();


}