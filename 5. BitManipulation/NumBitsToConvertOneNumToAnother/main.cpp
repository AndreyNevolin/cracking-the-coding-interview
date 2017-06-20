/* Write a function to determine the number of bits required to convert integer A to
integer B */
#include <iostream>

using namespace std;

string inBinary( int n)
{
    string result;

    while ( n)
    {
        result = (char)('0' + n % 2) + result;
        n /= 2;
    }

    return result;
}

/* Для подсчета суммы битов использован быстрый метод:
   n = A1000
   n - 1 = A0111
   n & (n - 1) = A (т.е. каждая итерация цикла обнуляет
                    самый младший ненулевой бит)
*/
int getNumBits( int a, int b)
{
    int diff = a ^ b;
    int bit_summ = 0;

    while ( diff )
    {
        bit_summ++;
        diff = diff & (diff - 1);
    }

    return bit_summ;
}

int main()
{
    int a, b;

    cout << "Input first: ";
    cin >> a;
    cout << "In binary: " << inBinary( a) << "\n";
    cout << "Input second: ";
    cin >> b;
    cout << "In binary: " << inBinary( b) << "\n";

    cout << "Num of diverging bits: " << getNumBits( a, b);

    return 0;
}
