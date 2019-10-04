#include <iostream>
#include "Node.cpp"
using namespace std;

class List
{
    Node *headNode;
    Node *currentNode;
    Node *lastCurrentNode;
    int size;

public:
    List()
    {
        headNode = NULL;
        currentNode = NULL;
        lastCurrentNode = NULL;
        size = 0;
    }

    void insert(int n)
    {
        if (currentNode != NULL)
        {
            if (currentNode->getNextNode() == 0)
            {
                Node *newNode = new Node();
                lastCurrentNode = currentNode;
                currentNode->setNextNode(newNode);
                currentNode = newNode;

                currentNode->setValue(n);
                currentNode->setNextNode(0);
                size++;
            }
            else
            {
                Node *newNode = new Node();
                newNode->setNextNode(currentNode->getNextNode());
                currentNode->setNextNode(newNode);
                lastCurrentNode = currentNode;
                currentNode = newNode;
            }
        }
        else
        {

            Node *newNode = new Node();
            headNode = newNode;
            currentNode = headNode;
            lastCurrentNode = 0;

            currentNode->setValue(n);
            currentNode->setNextNode(0);
            size++;
        }
    }

    void insertAtBegin(int n)
    {
        Node *newNode = new Node();
        newNode->setNextNode(headNode);
        headNode = newNode;
        currentNode = headNode;
        lastCurrentNode = 0;
        currentNode->setValue(n);
        size++;
    }

    void insertAtEnd(int n)
    {
        lastCurrentNode = currentNode;
        Node *newNode = new Node();
        if (currentNode)
        {
            currentNode = headNode;
            while (currentNode->getNextNode())
            {
                currentNode = currentNode->getNextNode();
            }
            currentNode->setNextNode(newNode);
        }
        else
        {
            headNode = newNode;
        }
        currentNode = newNode;
        currentNode->setValue(n);
        currentNode->setNextNode(0);
        size++;
    }

    void display()
    {
        Node *temp = headNode;
        cout << "\nMy Linked List is\n";
        while (temp)
        {
            cout << temp->getValue() << endl;
            temp = temp->getNextNode();
        }
    }

    void deleteNode(int n)
    {
        start();
        while (currentNode != 0)
        {
            if (get() == n)
            {
                break;
            }
            move();
        }
        cout << currentNode << "    " << get();
        lastCurrentNode->setNextNode(currentNode->getNextNode());
        delete currentNode;
        size--;
    }

    int sumOfNode()
    {
        int sum = 0;
        int n;
        while (currentNode != 0)
        {
            n = get();
            sum = sum + n;
            move();
        }
        cout << "SUM of all nodes: " << sum << endl
             << endl;
        return sum;
    }

    void start()
    {
        currentNode = headNode;
    }

    void move()
    {
        lastCurrentNode = currentNode;
        currentNode->setNextNode(currentNode);
    }

    int get()
    {
        return currentNode->getValue();
    }

    int getSize()
    {
        return size;
    }
};
