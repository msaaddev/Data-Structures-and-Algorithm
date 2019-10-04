#include <iostream>
#include "List.cpp"
using namespace std;

int main()
{
    {
        List myLinkList;
        myLinkList.insert(2);
        myLinkList.insert(3);
        myLinkList.insert(67);
        myLinkList.insert(91);
        myLinkList.display();
        cout << "Insert At Begin: \n";

        myLinkList.insertAtBegin(16);
        myLinkList.display();
        cout << endl
             << "Insert At End: \n";
        myLinkList.insertAtEnd(25);
        myLinkList.display();
        cout << endl
             << "Update: \n";

        myLinkList.start();
        myLinkList.move();
        myLinkList.move();
        myLinkList.update(65);
        myLinkList.display();
        cout << endl
             << endl
             << "After deleting a Node:" << endl;

        myLinkList.start();
        myLinkList.move();
        myLinkList.move();
        myLinkList.move();
        myLinkList.deleteNode(67);
        myLinkList.display();
        int VALUE;
        cout << "Enter the value you want to search in linkedSList : ";
        cin >> VALUE;

        myLinkList.start();

        myLinkList.start();

        //cout << "Size of Linked List = " << myLinkList.getSize();

        return 0;
    }
}