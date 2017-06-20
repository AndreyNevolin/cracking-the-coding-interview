/* Write a method to generate the nth Fibonacci number */
#include <iostream>

using namespace std;

long long Fibonacci( int n, long long f1, long long f2)
{
    if ( n < 0 )
        return -1;

    if ( !n )
        return f1;

    return Fibonacci( n - 1, f2, f1 + f2);
}

int main()
{
    for ( int i = 0; i < 20; i++ )
        cout << Fibonacci( i, 0, 1) << " ";

    return 0;
}
