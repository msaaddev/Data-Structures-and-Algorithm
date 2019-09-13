#include <iostream>
using namespace std;

struct tNode
{
    int data;
    tNode *next;
};

int main()
{
    tNode obj1, obj2, obj3, obj4, obj5;

    obj1.next = NULL;
    obj1.data = 2;

    obj2.next = NULL;
    obj2.data = 4;

    obj3.next = NULL;
    obj3.data = 6;

    obj4.next = NULL;
    obj4.data = 8;

    obj5.next = NULL;
    obj5.data = 10;

    obj1.next = &obj2;
    obj2.next = &obj3;
    obj3.next = &obj4;
    obj4.next = &obj5;

    cout << "Output" << obj1.next->data;
}