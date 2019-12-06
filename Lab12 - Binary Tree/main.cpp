#include <iostream>
#include "tree.cpp"
using namespace std;

int main()
{
     system("cls");
     Tree tree;
     cNode *node1 = new cNode(5);
     cNode *node2 = new cNode(2);
     cNode *node3 = new cNode(3);
     cNode *node4 = new cNode(7);
     cNode *node5 = new cNode(1);
     cNode *node6 = new cNode(9);

     tree.insert(node1).insert(node2).insert(node3).insert(node4).insert(node5).insert(node6);
     tree.printPostOrder();
     cNode *toBeDeleted = new cNode(5);
     tree.removeNode(toBeDeleted);
     cout << endl;
     tree.printPostOrder();
}