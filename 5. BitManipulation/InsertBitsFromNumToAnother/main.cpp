/* You are given two 32-bit numbers, N and M, and two bit positions, i and j Write a
method to set all bits between i and j in N equal to M (e g , M becomes a substring of
N located at i and starting at j)
EXAMPLE:
Input: N = 10000000000, M = 10101, i = 2, j = 6
Output: N = 10001010100 */
#include <iostream>
#include <stdlib.h>

using namespace std;

int strToNum( string str)
{
    if ( str.size() > 32 )
    {
        cout << "Too big number";

        exit( 1);
    }

    int result = 0;

    for ( int i = 0; i < str.size(); i++ )
    {
        char digit = str[i] - '0';

        if ( digit > 1 || digit < 0 )
        {
            cout << "Digit can be eigther 0 or 1";

            exit( 1);
        }

        result = result * 2 + digit;
    }

    return result;
}

/* Вопрос интервьюеру: что делать в случае, если j-i+1 будет больше, чем длина m
   в битах? В версии ниже вместо недостающих цифр добавляются нули */
unsigned insertBits( unsigned n, unsigned m, int i, int j)
{
    if ( j < i || i < 0 || j > 31 )
    {
        cout << "Inappropriate bit positions";

        exit( 1);
    }

    unsigned mask = (1 << (j - i + 1)) - 1;
    unsigned result = n & ~(mask << i);

    return result | ((m & mask) << i);
}

int main()
{
    string n_str, m_str;

    cout << "Input n in binary: ";
    getline( cin, n_str);

    unsigned n = strToNum( n_str);

    cout << "Input m in binary: ";
    getline( cin, m_str);

    unsigned m = strToNum( m_str);
    int i, j;

    cout << "Start at bit: ";
    cin >> i;
    cout << "Finish at bit: ";
    cin >> j;

    int result = insertBits( n, m, i, j);
    string res_str;

    while ( result )
    {
        res_str = (char)('0' + (result % 2)) + res_str;
        result /= 2;
    }

    cout << res_str;

    return 0;
}
