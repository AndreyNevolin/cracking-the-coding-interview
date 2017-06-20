/* Write a function to swap a number in place without temporary variables */
#include <iostream>

using namespace std;

/* Этот метод работает для чисел в любом формате. Битовая запись
   чисел будет сохранена независимо от того, как они кодируются */
void swap( int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main()
{
    int a = 5, b = 70;

    cout << "a = " << a << ", b = " << b << "\n";
    swap( &a, &b);
    cout << "After swap a = " << a << ", b = " << b;

    return 0;
}
