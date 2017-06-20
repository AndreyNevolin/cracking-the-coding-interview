/* Given an integer, print the next smallest and next largest number that have the same
number of 1 bits in their binary representation */
#include <iostream>
#include <stdlib.h>
#include <climits>

using namespace std;

string inBinary( unsigned n)
{
    string result;

    while ( n)
    {
        result = (char)(n % 2 + '0') + result;
        n /= 2;
    }

    return result;
}

void error()
{
    cout << "ERROR";

    exit( 1);
}

bool BIT( int n, int i)
{
    return n & (1 << i);
}

/* Что выдавать в случае, когда функции передан ноль или максимально
   возможное число? */
unsigned nextLargest( unsigned n)
{
    int pos = 0;
    int result = n;
    int num_one = 0;

    if ( !n || n == UINT_MAX )
        error();

    while ( !BIT( n, pos) )
        pos++;

    while ( BIT( n, pos) )
    {
        num_one++;
        pos++;
    }

    result |= 1 << pos;
    num_one--;
    pos--;

    while ( pos + 1 > num_one )
    {
        result &= ~0 - (1 << pos);
        pos--;
    }

    return result |= (1 << num_one) - 1;
}

/* Если n == 2^m - 1, то получить требуемый результат невозможно */
unsigned nextSmallest( unsigned n)
{
    unsigned result = n;
    int pos = 0;
    int num_zero = 0;

    if ( !n || n == UINT_MAX || ((n + 1) & n) == 0 )
        error();

    while ( BIT( n, pos) )
        pos++;

    while ( !BIT( n, pos) )
    {
        pos++;
        num_zero++;
    }

    result ^= 1 << pos;
    pos--;
    num_zero--;

    while ( pos + 1 > num_zero )
    {
        result |= 1 << pos;
        pos--;
    }

    return result & ((~0) - (1 << num_zero) + 1);
}

int main()
{
    unsigned n, nextl, nexts;

    cin >> n;
    cout << "In binary: " << inBinary( n) << "\n";
    nextl = nextLargest( n);
    nexts = nextSmallest( n);

    cout << "Next largest: " << nextl << " (" << inBinary( nextl) << ")\n";
    cout << "Next smallest: " << nexts << " (" << inBinary( nexts) << ")\n";

    return 0;
}
