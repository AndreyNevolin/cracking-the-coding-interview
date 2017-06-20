/* Write a method to compute all permutations of a string */
#include <iostream>
#include <vector>

using namespace std;

/* �������� ������ - ������ � �������������� ���������.
   ������������ ���������� �������� ����� ����� �� ���� ����� �����.

   ���������� �������� � ������������ ����� �������. ����� ������� ������� -
   �����������. �� ��� �� �������� ����������� ��-�� ������������� � �����������
   ������������ �����. ������ ����� ������, ��� n! ����� ������ ������, �������
   �� �������� ������� �������� �� ������ ���� ����� �������.
   ��� �� �����, ��� ������ ���� "������..." (����� ����� ���������� ��������)
   ���������� ����� ���� ������������, ����������� ������ � ������� ����� �����������
   ���� (���� ������ �� ������� �������). ��� �������� ���������� ������ ������������
   �������.

   ���� ���������� ����������� ������� */
vector<string> getPermutations( string str)
{
    if ( !str.size() )
        return vector<string>( 1);

    vector<string> temp = getPermutations( str.substr( 1));
    vector<string> result;

    result.reserve( temp.size() * temp[0].size());
}

int main()
{
    string str;

    cout << "Enter a string: ";
    getline( cin, str);

    vector<string> permutations = getPermutations( str);

    for ( int i = 0; i < permutations.size(); i++ )
        cout << permutations[i] << "\n";

    return 0;
}
