/* Write a function that adds two numbers. You should not use + or any arithmetic operators */
#include <iostream>

using namespace std;

/* Надо уточнить, действительно ли имеется в виду сложение
   целых чисел */
int summ( int a, int b)
{
    int carry = a;
    int result = b;

    while ( carry )
    {
        int temp = carry & result;
        result ^= carry;
        carry = temp << 1;
    }

    return result;
}

int main()
{
    int a = 5, b = 9;

    cout << a << " + " << b << " = " << summ( a, b);

    return 0;
}
