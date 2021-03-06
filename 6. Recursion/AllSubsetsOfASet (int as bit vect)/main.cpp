/* Write a method that returns all subsets of a set */
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>

using namespace std;

/* � ������������ ���������� �������� ��������� ����:
   1. ����� ������� ������������ �������� ���������?
   2. � ����� ���� ����� ������� ������������?
   3. ��������, ��� ������ ������������� ��������� ���������
      ������������� ����������. ���� ��� ���, �� ��������, ����� ��
      ���-�� ������ ���� ������ ��� ����� �������, ��� ���������� ���.
      ���� ��������� ����� ����, �� ��� ������: ��������� ���� � ������
      ��� ������������ ������������ ��� � ������ ���������� (�.�. ��
      �������� ��������� � ������ �������������� ������������ �����, ��� ���� ���)?
   4. � ���������� ������������� ��� ������������ ����� ������ ��� �������� ��������.
      ������� ���� �������� �����������, ���� �� �����:
      a) ������� ����������� ������� (���������� �������������� + �� �������� ���
         ����� ������� ��������, �.�. ����� ��������� ��-�� ������������ �����)
      �) ������� �� ������� ��������. ������ ����� ���� ��� ���� �������:
            - ������� ������ ��������� � ����������� ������������� ������ (��� �������
              �� ������� ��� ������� ��������)
            - ������� ������� ������ �� ������� �� ����������� �������� (��� ��� ���������
              �������� � ���������� ����� ��������)
      �) ����������� ������� (��� �������� � ������� ��������)

      ��������, ��� � ����� ������ ���� �������� ����������� ������� � ������������� ������ ���

      ����� ���������� ������� � ������� �������� �� int-�������
*/
vector< vector<int> > getSubsets( vector<int> &num_set)
{
    if ( num_set.size() > sizeof( int) << 3 )
    {
        cout << "Too big set";

        exit( 1);
    }

    vector< vector<int> > result( 1 << num_set.size());
    int ind = 0;

    for ( int i = 0; i < 1 << num_set.size(); i++ )
    {
        vector<int> subset;
        int num = i, j = 0;

        while ( num )
        {
            if ( num & 1 )
                subset.push_back( num_set[j]);

            j++;
            num >>= 1;
        }

        result[ind++] = subset;
    }

    return result;
}

int main()
{
    const int n = 4;
    vector<int> num_set( n);

    cout << "Set: ";
    for ( int i = 0; i < n; i++ )
    {
        num_set[i] = i;
        cout << setw( 3) << num_set[i];
    }

    cout << "\nSubsets: \n";

    vector< vector<int> > subsets = getSubsets( num_set);

    for ( int i = 0; i < subsets.size(); i++ )
    {
        for ( int j = 0; j < subsets[i].size(); j++ )
            cout << setw( 3) << subsets[i][j];

        cout << "\n";
    }

    return 0;
}
