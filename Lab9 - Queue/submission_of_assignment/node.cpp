#include <iostream>
#include <cstring>
using namespace std;

class cNode
{
private:
    string name;
    int priority;

public:
    int marks;
    cNode *nextNode;

    cNode() {}

    cNode(string d) : name(d) {}

    void setName(string name) { this->name = name; }

    string getName() const { return name; }

    // void setMarks(int marks) { this->marks = marks; }

    int getMarks() { return marks; }

    void setPriority(int prior)
    {
        priority = prior;
    }

    int getPriority()
    {
        return priority;
    }

    void printPriority() const
    {
        cout << priority << " ";
    }

    // void print() const { cout << name << " "; }
};