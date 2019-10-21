#include "cStack.cpp"
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
     CStack s;
     string num;
     cout << "Enter an infix expression: ";
     cin >>  num;
     cout << endl;
     cout << "Post Expression: " << s.infixToPost(num);
}
