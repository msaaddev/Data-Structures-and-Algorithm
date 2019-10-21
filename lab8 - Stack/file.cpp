#include "cStack.cpp"
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
     CStack s;
     string num = "(A+B)/3^2";
     cout << "Post Expression: " << s.infixToPost(num);
}