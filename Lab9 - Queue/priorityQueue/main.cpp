#include <iostream>
#include "priorityQueue.cpp"
using namespace std;

int main()
{
    cPriorityQue queue;
    /*
	This is a check to see if the Queue is empty by using isEmpty function
	*/
    cout << "This is a check to see if the Queue is empty by using isEmpty function. " << endl;
    if (queue.isEmpty())
    {
        cout << "Queue is empty." << endl
             << endl;
    }
    else
    {
        cout << "Queue is not Empty." << endl
             << endl;
    }

    /*
	This is a check to see if the Queue is empty by using isEmpty function.
	*/
    cout << endl
         << "This is a check to see if the Queue isNotEmpty by using isEmpty function." << endl;
    if (queue.isNotEmpty())
    {
        cout << "Queue is not empty." << endl
             << endl;
    }
    else
    {
        cout << "Queue is Empty." << endl
             << endl;
    }

    /*
	This is a check to see all the elements present in the queue by printing them.
	*/
    cout << "This is a check to see all the elements present in the queue by printing them." << endl;
    queue.print();
    cout << endl;

    /*
	Declaring a node and setting the data
	*/
    cNode *ptr = new cNode(132);
    ptr->setPriority(132);

    /*
	Pushing the new node whose address is stored in ptr into the Queue
	*/
    queue.insertWithPriority(ptr);
    queue.print();

    cNode *node2 = new cNode();
    node2->setData(25);
    node2->setPriority(25);
    queue.insertWithPriority(node2);

    cNode *node3 = new cNode();
    node3->setData(23);
    node3->setPriority(23);
    queue.insertWithPriority(node3);

    cNode *node4 = new cNode();
    node4->setData(524);
    node4->setPriority(524);
    queue.insertWithPriority(node4);

    cNode *node5 = new cNode();
    node5->setData(12);
    node5->setPriority(12);
    queue.insertWithPriority(node5);

    cNode *node6 = new cNode();
    node6->setData(221);
    node6->setPriority(221);
    queue.insertWithPriority(node6);

    cNode *node7 = new cNode();
    node7->setData(41);
    node7->setPriority(41);
    queue.insertWithPriority(node7);

    cout << endl
         << endl;

    cout << "\n\nNow printing Queue after pushing 7 new nodes if isNotEmpty function returns true\n";
    if (queue.isNotEmpty())
        queue.print(); /*
	Now deleting top of queue when more then one nodes is present
	*/
    cout << "\n\nNow deleting top of Queue when more then one nodes is present\n";
    queue.dequeue();
    if (queue.isNotEmpty())
        queue.print();

    cout << "\n\nHighest Prioriy: " << queue.getHighestPriority() << endl;

    /*
	Now getting value of a node using getValue function
	*/
    cNode *node8 = new cNode();
    node8->setData(800);
    node8->setPriority(5);
    cout << "\n\nNow getting value of a node8 using getData function: ";
    cout << node8->getData() << "\n";

    /*
	Now deleting top of queue when more then one nodes is present
	*/
    cout << "\n\nNow deleting top of Queue when more then one nodes is present\n";
    queue.dequeue();
    if (queue.isNotEmpty())
        queue.print();

    cPriorityQue newQueue(queue);
    /*
	/*
	Copying content of one queue to another queue using copy constructor
	*/
    cout << "\n\nCopying content of one queue to another queue using copy constructor and printing the contents of queue destination." << endl;
    newQueue.print();
}