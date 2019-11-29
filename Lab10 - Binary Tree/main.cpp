#include <iostream>
#include "tree.cpp"
using namespace std;

int main()
{
    system("cls");
    Tree tree;
    cNode *node1 = new cNode(17);
    cNode *node2 = new cNode(13);
    cNode *node3 = new cNode(14);
    cNode *node4 = new cNode(18);
    cNode *node5 = new cNode(3);
    cNode *node6 = new cNode(10);

    tree.insert(node1).insert(node2).insert(node3).insert(node4).insert(node5).insert(node6);


    /* cNode *node7 = new cNode();
    node7->setData(10);

    tree.insert(node7); */
    /*
    if (tree.search(node7) != -1)
    {
        cout << "Node is present at level " << tree.search(node7) << ".\n\n";
    } */
}