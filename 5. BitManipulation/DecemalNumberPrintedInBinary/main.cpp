/* Given a (decimal - e.g. 3.72) number that is passed in as a string,
   print the binary representation. If the number can not be represented
   accurately in binary, print �ERROR� */
#include <iostream>
#include <stdlib.h>
#include <climits>
#include <math.h>

using namespace std;

void error()
{
    cout << "ERROR";

    exit( 1);
}

int parseInt( string str, int start, int *val)
{
    *val = 0;

    int ind = start;

    while ( ind < str.size() && str[ind] != '.' )
    {
        if ( *val > INT_MAX / 10 )
            error();

        char digit = str[ind] - '0';

        if ( digit < 0 || digit > 9 )
            error();

        if ( *val == INT_MAX / 10 && digit > INT_MAX % 10 )
            error();

        *val = *val * 10 + digit;
        ind++;
    }

    return ind;
}

/* �������� ������:
   1. ���� �� ������������ ������� ���������� ��� ����� ������������
      ������������ ������ � ��������� ������ � �������� �������� ��������?
   2. ��� ������ � �������������� �������? ��������, ����� 0.3 (� ����������
      �������) ������������ ����� ����������� ������������� �����, ����
      �������� � �������� �������. ��� ������ � ����� ������? ���� ��
      "�������" ������ � ���-�� ���������� ���?
   3. ����� ����� ���� ��� ������� �����, �.�. ��� �����. ��� ���� ������ ���
      ��������
   4. ����� �� ����� ���� �������������?
   5. � ����� ����� �������� �����? ������ ����� � ������ ��� ����� ���� �������
      ����������? */
void printInBinary( string str)
{
    int int_part = 0;
    int ind1 = parseInt( str, 0, &int_part);
    int frac_part_int = 0;
    int ind2 = parseInt( str, ind1 + 1, &frac_part_int);

    if ( ind2 != str.size() )
        error();

    double frac_part = 0.0;

    if ( ind2 - ind1 - 1 > 0 )
        frac_part = frac_part_int / pow( 10, ind2 - ind1 - 1);

    string int_str, frac_str;

    while ( int_part )
    {
        int_str = (char)((int_part % 2) + '0') + int_str;
        int_part /= 2;
    }

    while ( frac_part > 0.0 )
    {
        if ( frac_str.size() > 32 )
            error();

        frac_part *= 2;

        if ( frac_part >= 1 )
        {
            frac_str = frac_str + '1';
            frac_part -= 1;
        } else
        {
            frac_str = frac_str + '0';
        }
    }

        cout << int_str << "." << frac_str;
}

int main()
{
    string str;

    getline( cin, str);
    printInBinary( str);

    return 0;
}
