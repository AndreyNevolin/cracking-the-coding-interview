/* Write a program to swap odd and even bits in an integer with as few instructions as
possible (e g , bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc) */
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

/* ����� ���� ������������ �� ������� ������.
   ����� ����� implemenation dependant. ����������� ������������
   �� ����������� ����� ������ ��� ��� ��������������� �����, � ��
   �������� - � ����������������. ��-��������, ��������� �� ���������� ������,
   � ����� ������ �������� ����� ������� ��� ����� ������ ������ */
unsigned swapBits( unsigned n)
{
    return ((n & 0x55555555) << 1) | ((n & 0xAAAAAAAA) >> 1);
}

int main()
{
    unsigned n = 0;
    unsigned n_swapped = 0;

    cin >> n;
    cout << "In binary: " << inBinary( n) << "\n";
    n_swapped = swapBits( n);
    cout << "Bits swapped: " << n_swapped << " (" << inBinary( n_swapped) << ")";

    return 0;
}
