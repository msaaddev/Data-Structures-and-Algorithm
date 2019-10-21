
//Added Node.cpp file
#include "Node.cpp"
#include <iostream>

using namespace std;

class CStack
{
    Node *top;
    int size;

public:
    CStack()
    {
        top = NULL;
        size = 0;
    }

    void push(char value)
    {
        if (!top)
        {
            Node *newNode = new Node();
            top = newNode;
            newNode->setValue(value);
            newNode->setNext(0);
            size++;
        }
        else
        {
            Node *newNode = new Node();
            newNode->setNext(top);
            top = newNode;
            newNode->setValue(value);
            size++;
        }
    }

    char pop()
    {
        if (stackIsEmpty())
        {
            cout << "There is nothing in the stack.";
        }
        else
        {
            char value = topGetValue();
            Node *temp = top;
            top = top->getNext();
            delete temp;
            return value;
        }
    }

    bool stackIsEmpty()
    {
        if (top)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    char topGetValue()
    {
        return top->getValue();
    }

    bool precedence(char value, char oper)
    {
        bool condition = (oper == '^' && (value == '/' || value == '*' || value == '+' || value == '-')) || (oper == '/' && (value == '*' || value == '+' || value == '-')) || (oper == '*' && (value == '+' || value == '-'));

        if (condition)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string infixToPost(string infixExpression)
    {
        CStack s;
        string postExpression = "";

        for (int i = 0; i <= infixExpression.length(); i++)
        {
            int value = infixExpression[i];
            if (value >= 48 && value <= 57)
            {
                postExpression = postExpression + infixExpression[i];
            }

            else if (infixExpression[i] == '(')
            {
                s.push(infixExpression[i]);
            }
            else if (infixExpression[i] == ')')
            {
                while (s.topGetValue() != '(')
                {
                    postExpression = postExpression + s.pop();
                }
                s.pop();
            }
            else
            {
                char temp = infixExpression[i];

                while (!s.stackIsEmpty() && precedence(temp, s.topGetValue()))
                {
                    char op = s.pop();
                    postExpression = postExpression + op;
                }
                s.push(infixExpression[i]);
            }   
        }
        while (!s.stackIsEmpty())
        {
            char op = s.pop();
            postExpression = postExpression + op;
        }
        return postExpression;
    }
};