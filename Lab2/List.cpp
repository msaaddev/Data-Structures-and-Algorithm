//This Program contains the list class. We declared insert, insert at end, insert at beginning, update value by index,
//update value by using previous value and print the link list

//Added Node.cpp file
#include "Node.cpp"
#include <iostream>

using namespace std;

//Declared class list in which we defined methods we want to implement on Link List
class list
{

    //Pointer which has the address of top
    Node *headNode;

    //pointer which points to the current Node
    Node *currentNode;

    //pointer which points to the Last Current Node
    Node *lastCurrentNode;

    //To keep record of size of Link List
    int size;

public:
    //Default Constructor which Sets all pointers to NULL and size to zero
    list()
    {
        headNode = NULL;
        currentNode = NULL;
        lastCurrentNode = NULL;
        size = 0;
    }

    //Function to insert a new Node in the link list
    void insert(int number)
    {
        if (currentNode != NULL)
        {
            if (currentNode->getNextNode() == 0)
            {
                Node *temp = new Node();
                currentNode->setNextNode(temp);
                lastCurrentNode = currentNode;
                currentNode = temp;
                currentNode->setValue(number);
                currentNode->setNextNode(0);
                size++;
            }
            else
            {
                Node *temp = new Node();
                temp->setNextNode(currentNode->getNextNode());
                currentNode->setNextNode(temp);
                lastCurrentNode = currentNode;
                currentNode = temp;
                currentNode->setValue(number);
                size++;
            }
        }
        else
        {
            Node *temp = new Node();
            headNode = temp;
            currentNode = headNode;
            lastCurrentNode = 0;
            currentNode->setValue(number);
            currentNode->setNextNode(0);
            size++;
        }
    }

    //function to insert a value at certain index
    void insertByPosition(int value, int position)
    {
        start();
        if (position <= size)
        {
            for (int i = 0; i < position - 2; i++)
            {
                move();
            }
            insert(value);
        }
        else
        {
            cout << "The position " << position << " is not available in Link list. Node is inserted at the end" << endl;
            insertAtEnd(value);
        }
    }

    void insertAfterValue(int value, int valueOfNodeAfter)
    {
        start();
        for (int i = 0; i < size; i++)
        {
            if (currentNode->getValue() == valueOfNodeAfter)
            {
                insert(value);
                break;
            }
            move();
        }
    }

    //Function to insert a new Node at the start of Link List
    void insertAtBegin(int number)
    {

        start();
        Node *temp = new Node();
        temp->setNextNode(currentNode);
        currentNode = temp;
        headNode = temp;
        currentNode->setValue(number);
        lastCurrentNode = 0;
        size++;
    }

    //Function to insert a new Node at the end of Link List
    void insertAtEnd(int number)
    {
        start();
        for (int i = 0; i < size; i++)
        {
            move();
        }
        Node *temp = new Node();
        currentNode->setNextNode(temp);
        lastCurrentNode = currentNode;
        currentNode = temp;
        currentNode->setValue(number);
        currentNode->setNextNode(0);
        size++;
    }

    //Function to update value of a Node by using index of that Node
    void updateValueByIndex(int newValue, int index)
    {
        start();
        for (int i = 0; i < index - 1; i++)
        {
            move();
        }
        currentNode->setValue(newValue);
    }

    //Function to update value of a Node by using previous value of that Node
    void updateValue(int newValue, int previousValue)
    {
        start();
        for (int i = 0; i < size; i++)
        {
            if (currentNode->getValue() == previousValue)
            {
                currentNode->setValue(newValue);
                break;
            }
            move();
        }
    }

    //Function to get size of Link List
    int getSize()
    {
        return size;
    }

    //Function to get value of a specific Node
    int get()
    {
        return currentNode->getValue();
    }

    //Function to get Value of Last current Node
    int getLast()
    {
        return lastCurrentNode->getValue();
    }

    //Function to move at the start of the Link List
    void start()
    {
        lastCurrentNode = 0;
        currentNode = headNode;
    }

    //Function to move to next Node
    void move()
    {
        if (currentNode->getNextNode() != 0)
        {
            lastCurrentNode = currentNode;
            currentNode = currentNode->getNextNode();
        }
    }

    //Function to print all the Nodes in the Link List
    void print()
    {
        if (headNode == NULL)
        {
            cout << "/nLink List is empty/n";
        }
        else
        {
            start();
            for (int i = 0; i < size; i++)
            {
                cout << get() << endl;
                if (i < (size - 1))
                {
                    move();
                }
            }
        }
    }

    //Function to delete a Node from list

    void deleteNode(int valueOfNode)
    {

        start();

        for (int i = 0; i < size; i++)
        {

            if (currentNode->getValue() == valueOfNode)
            {

                if (currentNode->getNextNode() != NULL)
                {

                    if (currentNode == headNode)
                    {

                        if (size == 1)
                        {
                            headNode = NULL;
                            delete currentNode;
                            currentNode = headNode;
                            lastCurrentNode = 0;
                            break;
                        }
                        else
                        {
                            Node *ptr;
                            ptr = currentNode;
                            currentNode = currentNode->getNextNode();
                            headNode = currentNode;
                            delete ptr;
                            break;
                        }
                    }
                    else
                    {
                        lastCurrentNode->setNextNode(currentNode->getNextNode());
                        delete currentNode;
                        currentNode = lastCurrentNode;
                        break;
                    }
                }
                else
                {
                    lastCurrentNode->setNextNode(0);
                    delete currentNode;
                    currentNode = lastCurrentNode;
                    break;
                }
            }

            move();
        }
        size--;
    }

    //Printing the sum of all the values in linklist

    int sumValue()
    {
        int sum = 0;
        start();
        for (int i = 0; i < size; i++)
        {
            sum += currentNode->getValue();
            move();
        }
        return sum;
    }

    //Searching a value if it is present in the list
    void searchValue(int value)
    {
        start();
        bool flag = false;
        int index = 0;
        for (int i = 0; i < size; i++)
        {
            if (currentNode->getValue() == value)
            {
                flag = true;
                index = i;
            }
            move();
        }
        if (flag == true)
        {
            cout << "The value is present in the link list at index " << index << endl;
        }
        else
        {
            cout << "The value is not present in the link list" << endl;
        }
    }
};