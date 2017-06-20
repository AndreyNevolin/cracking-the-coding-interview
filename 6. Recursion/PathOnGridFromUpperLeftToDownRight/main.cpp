/* Imagine a robot sitting on the upper left hand corner of an NxN grid The robot can
only move in two directions: right and down How many possible paths are there for
the robot?
FOLLOW UP
Imagine certain squares are �off limits�, such that the robot can not step on them
Design an algorithm to get all possible paths for the robot */
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/* ������ �������:
   1) � ������ ��������, ��� ����� ����� ��� ��������� ����. ��� �������������, ���
      ���� ����� ������������� "� ������ ����", � �� ����������� � ������ ������ ����.
      ��� ���� � ����� �������, ������ ����� �� ������ ������ (���������� �����)
      �������������, ��� ������� ���� ������ � ������ ������ ����.
      ��-��������, ���� �������� � �����������, ����� �� ���� ������������� "� ������
      ����". ���� ��, �� ���� ��������� ����������� ������� ��� ������ ������ ��������.
   2) ��� ������ � ������, ���� ��������� ������ (0,0) ������ ������������? (� �������������
      ����� ������� ���������, ��� �� ������ ���� �� ���� ������ �� ����������)
   3) ��� ������ � ������, ���� �������� ������ ������������? (� ������������� �����
      ������� ���������, ��� �� ������ ���� � ��� ������ �� ����������)
   4) �������, ����������� � ����� ��� ������ ����� ������ ������� ������ ������ ����������
      ���� (���� ������� ����������). ������ � ������� ��������� ����� ��� ����. ������� ����
      ������� ��� ��������� ����
   5) � ������� �������, ��� ����� "��������" ��� ��������� ����. ������� ��-��������, ����
      ����� �� �������� (��� ������� ����), � "������������" � �����-�� �������� ���������
      ������ (��������, vector<vector<char>>)
*/
bool findPaths( int x, int y, int **arr, vector<char> &path)
{
    bool result = false;

    if ( !arr )
        return false;

    if ( x < 0 || y < 0 )
        return false;

    if ( arr[x][y] )
        return false;

    if ( !x && !y )
    {
        for ( int i = path.size() - 1; i >= 0; i-- )
            cout << path[i];

        cout << '\n';

        return true;
    }

    path.push_back( 'D');
    result |= findPaths( x - 1, y, arr, path);
    path.pop_back();
    path.push_back( 'R');
    result |= findPaths( x, y - 1, arr, path);
    path.pop_back();

    return result;
}

int main()
{
    const int n = 6;
    int arr[n][n] = { {0,0,0,1,0,1},
                      {1,0,1,1,0,0},
                      {0,0,0,0,0,0},
                      {0,1,0,1,1,0},
                      {0,0,0,0,0,0},
                      {0,0,0,0,0,0} };
    vector<char> path;
    int **grid = new int*[n];

    for ( int i = 0; i < n; i++ )
    {
        grid[i] = new int[n];

        for ( int j = 0; j < n; j++ )
        {
            grid[i][j] = arr[i][j];
            cout << setw( 1) << grid[i][j] << " ";
        }

        cout << "\n";
    }

    if ( !findPaths( n - 1, n - 1, grid, path) )
        cout << "No paths found";

    return 0;
}
