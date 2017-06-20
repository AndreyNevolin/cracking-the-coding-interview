/* Write a method that returns all subsets of a set */
#include <iostream>
#include <vector>
#include <iomanip>

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

      ����� ���������� ����������� �������
*/
vector< vector<int> > getSubsets( vector<int> &num_set)
{
    bool push = true;
    vector< vector<int> > result( 1 << num_set.size());
    vector<int> subset;
    int res_ind = 0, ind = 0;
    vector<int> num_to_ind( num_set.size());

    for ( int i = 0; i < num_set.size(); i++ )
        num_to_ind[num_set[i]] = i;

    while ( 1)
    {
        if ( ind == num_set.size() )
        {
            result[res_ind++] = subset;

            if ( subset.empty() )
                break;
            else
            {
                ind = num_to_ind[subset.back()] + 1;
                subset.pop_back();
            }
        } else
            subset.push_back( num_set[ind++]);
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
