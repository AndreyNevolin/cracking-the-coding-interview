/* Write a method to generate the nth Fibonacci number */
#include <iostream>

using namespace std;

long long Fibonacci( int n)
{
    if ( n < 0 )
        return -1;

    int a = 0, b = 1;

    for ( int i = 0; i < n; i++ )
    {
        int c = a + b;

        a = b;
        b = c;
    }

    return a;
}

int main()
{
    for ( int i = 0; i < 20; i++ )
        cout << Fibonacci( i) << " ";

    return 0;
}
