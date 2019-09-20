#include <iostream>
#include "List.cpp"
using namespace std;

int main()
{
    List myLinkList;
    myLinkList.insert(10);

    cout << myLinkList.get() << endl;

    myLinkList.move();

    myLinkList.insert(123);
    cout << myLinkList.get() << endl;
    cout << myLinkList.getSize();
}