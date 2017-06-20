/* Given a sorted array of strings which is interspersed with empty strings,
   write a method to find the location of a given string.
   Example: find �ball� in [�at�, ��, ��, ��, �ball�, ��, ��, �car�, ��, ��, �dad�, ��, ��] will return 4
   Example: find �ballcar� in [�at�, ��, ��, ��, ��, �ball�, �car�, ��, ��, �dad�, ��, ��] will return -1 */
#include <iostream>
#include <vector>

using namespace std;

/* ������� �����������:
   1. ��� ����������, ���� ������������ ��������
      ����� ������ ������? � ������� ���� ������������ ������ �������
      ��������� ������ ������ � ������� (���� ����� ��������� �������)
   2. ����������� ������ ��� ������ ������: ����� ������ ����������, ����
      � ������� ���� ��������� ���������, ������ ��������? */
int searchArr( const vector<string> &arr, string str)
{
    int left = 0, right = arr.size() - 1;

    if ( str == "" )
    {
        for ( int i = 0; i < arr.size(); i++ )
            if ( arr[i] == "" )
                return i;

        return -1;
    }

    while ( left < arr.size() && arr[left] == "" )
        left++;

    /* ������ �����, ����� �� ������ ������ ������ �� ������� */
    if ( left == arr.size() )
        return -1;

    while ( right >= 0 && arr[right] == "" )
        right--;

    /* ������������� ������� ������ �� ��������� ������. �����������
       �������� left < right. ���������� ����� �������� �������� ��
       ����� ������� ����� �����.
       ��� ��� ������� ������, ��� � ������ ������� ������� ������ ����������
       �� ���, ��� � ���������� ������ ��������� ������. � ����������� ������
       �������� �������������� �������� �� ������ ����, �.�. � "��������" �����
       ������������ �������. � ���� ���� � "��������" ������ ��
       ����������� ��-�� ����, ��� ������� �������������� � ����� ���������, ���
       ������ ��������� �� �������� ������ */
    while ( right - left > 1 )
    {
        /* ���� ������� ����������� � ���, ��� ������ ������
           mid = (left + right) / 2, �.�. ��� ����� ������� overflow */
        int mid = left + (right - left) / 2;
        int temp = mid;

        if ( arr[mid] == str )
            return mid;

        while ( temp > left && arr[temp] == "" )
            temp--;

        if ( str <= arr[temp] )
        {
            right = temp;
        } else
        {
            temp = mid;

            while ( temp < right && arr[temp] == "" )
                temp++;

            left = temp;
        }
    }

    if ( arr[left] == str )
        return left;
    else if ( arr[right] == str )
        return right;
    else
        return -1;
}

int main()
{
    const char *arr[] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    /* ������ ����� �� ����� ���� ������. ������� � ������ ������ �� �����.
       ���� ����� �������������� ����� �� ������ �������, ����� ������� ����������������
       ��������� */
    const vector<string> vect( arr, arr + sizeof( arr) / sizeof( arr[0]));

    cout << "Array to search in:\n";

    for ( int i = 0; i < vect.size(); i++ )
        cout << "\"" << vect[i] << "\"" << " ";

    cout << "\nIndex of ball: " << searchArr( vect, "ball");
    cout << "\nIndex of ballcar: " << searchArr( vect, "ballcar");

    return 0;
}
