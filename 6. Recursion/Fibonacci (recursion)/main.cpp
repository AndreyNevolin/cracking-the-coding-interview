/* Write a method to generate the nth Fibonacci number */
#include <iostream>

using namespace std;

long long Fibonacci( int n)
{
    if ( n < 0 )
        return -1;

    if ( n == 0 )
        return 0;

    if ( n == 1 )
        return 1;

    return Fibonacci( n - 1) + Fibonacci( n - 2);
}

int main()
{
    for ( int i = 0; i < 20; i++ )
        cout << Fibonacci( i) << " ";

    return 0;
}
