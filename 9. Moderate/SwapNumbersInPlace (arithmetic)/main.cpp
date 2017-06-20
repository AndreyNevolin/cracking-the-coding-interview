/* Write a function to swap a number in place without temporary variables */
#include <iostream>

using namespace std;

/* ”точнить у интервьюера значени€ какого типа мы мен€ем местами

   ≈сли числа могут быть разных знаков, то арифметический метод плох (см.
   метод на основе логических операций), т.к. невозможно избежать overflow.

   ≈сли знаки чисел об€заны совпадать, то overflow можно избежать, избавившись
   от сложени€ "больших" чисел:
   a = b - a;
   b = b - a;
   a = a + b; */
void swap( int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main()
{
    int a = 5, b = 70;

    cout << "a = " << a << ", b = " << b << "\n";
    swap( &a, &b);
    cout << "After swap: " << "a = " << a << ", b = " << b;

    return 0;
}
