/* Write a method to sort an array of strings so that all the anagrams are next to each
other */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* ������� �����������:
   1) ����� ������ ���� ������� �������� ������������ ���� �����?
   2) ����� ������ ���� ������� �����, �� ���������� �����������?

   ���� ����������� ������� �� ������ ������������ ������� ����������
   (����� ��, ��� � ������). ��� ������� ����� �� ����������.

   ����������� ���� �� ���������:

   return !areAnagrams( s1, s2) && (s1 < s2);

   ����� ��������� areAnagrams( s1, s2) ���������, �������� �� ������
   ����������� ���� �����. ��. ���������� ���� ��������� ��� ������ ��
   ������� "Arrays and Strings" */
int cmp( string a, string b)
{
    vector<char> arr_a( a.begin(), a.end()), arr_b( b.begin(), b.end());

    sort( arr_a.begin(), arr_a.end());
    sort( arr_b.begin(), arr_b.end());

    return string( arr_a.begin(), arr_a.end()) < string( arr_b.begin(), arr_b.end());
}

int main()
{
    const int n = 7;
    char *arr[7] = {"abc", "cba", "aab", "bca", "aaab", "baa", "ykl"};
    vector<string> str_arr( n);

    cout << "Initial array: ";

    for ( int i = 0; i < n; i++ )
    {
        str_arr[i] = arr[i];
        cout << str_arr[i] << " ";
    }

    cout << "\nSorted array: ";
    sort( str_arr.begin(), str_arr.end(), cmp);

    for ( int i = 0; i < str_arr.size(); i++ )
        cout << str_arr[i] << " ";

    return 0;
}
