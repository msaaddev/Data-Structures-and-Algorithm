#include "cStack.cpp"
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
     CStack s;
     char input[20];
     int value;

     cout << endl
          << "Enter an algebraic expression in post prefix form: ";
     cin >> input;

     for (int i = 0; input[i] != '\0'; i++)
     {
          value = input[i];
          if (value >= 48 && value <= 57)
          {
               int val;
               val = value - 48;
               s.push(val);
          }
          else
          {
               int num1 = s.pop();
               int num2 = s.pop();

               if (input[i] == '+')
               {
                    int result;
                    result = num2 + num1;
                    s.push(result);
               }
               if (input[i] == '-')
               {
                    int result;
                    result = num2 - num1;
                    s.push(result);
               }
               if (input[i] == '*')
               {
                    int result;
                    result = num1 * num2;
                    s.push(result);
               }
               if (input[i] == '/')
               {
                    int result;
                    result = num2 / num1;
                    s.push(result);
               }
          }
     }
     cout << "Value: " << s.pop();
}