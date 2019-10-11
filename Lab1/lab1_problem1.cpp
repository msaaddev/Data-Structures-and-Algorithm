#include <iostream>
using namespace std;

struct complexNumber
{
    int real;
    int imaginary;
};

complexNumber addition(complexNumber firstNumber, complexNumber secondNumber)
{
    complexNumber thirdNumber;

    thirdNumber.real = firstNumber.real + secondNumber.real;
    thirdNumber.imaginary = firstNumber.imaginary + secondNumber.imaginary;

    return thirdNumber;

}

complexNumber subtraction(complexNumber firstNumber, complexNumber secondNumber)
{
    complexNumber thirdNumber;

    thirdNumber.real = firstNumber.real - secondNumber.real;
    thirdNumber.imaginary = firstNumber.imaginary - secondNumber.imaginary;

    return thirdNumber;
}

complexNumber multiplication(complexNumber firstNumber, complexNumber secondNumber)
{
    complexNumber thirdNumber;

    thirdNumber.real = firstNumber.real * secondNumber.real;
    thirdNumber.imaginary = firstNumber.imaginary * secondNumber.imaginary;

    return thirdNumber;
}

int main()
{
    complexNumber firstNumber, secondNumber, total;

    // Input block
    cout << "Enter the value for real part of the 1st number; ";
    cin >> firstNumber.real;

    cout << "Enter the value for imaginary part of the 1st number: ";
    cin >> firstNumber.imaginary;

    cout << endl;

    cout << "Enter the value for real part of the 2nd number: ";
    cin >> secondNumber.real;

    cout << "Enter the value for imaginary part of the 2nd number: ";
    cin >> secondNumber.imaginary;
    cout << endl;

    total = addition(firstNumber, secondNumber);

    cout << "Sum of Real Part of number 1 and 2: " << total.real << endl;
    cout << "Sum of Imaginary Part of number 1 and 2: " << total.imaginary << endl;
    cout << endl;

    total = subtraction(firstNumber, secondNumber);

    cout << "Subtraction of Real Part of number 1 and 2: " << total.real << endl;
    cout << "Subtraction of Imaginary Part of number 1 and 2: " << total.imaginary << endl;
    cout << endl;

    total = multiplication(firstNumber, secondNumber);

    cout << "Multiplication of Real Part of number 1 and 2: " << total.real << endl;
    cout << "Multiplication of Imaginary Part of number 1 and 2: " << total.imaginary << endl;
}