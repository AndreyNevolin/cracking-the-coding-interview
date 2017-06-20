/*  Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column is set to 0 */

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

void printMatrix( int **matrix, int m, int n)
{
    for ( int i = 0; i < m; i++ )
    {
        for ( int j = 0; j < n; j++ )
            cout << setw( 3) << matrix[i][j];

        cout << "\n";
    }
}

void replaceByZero( int **mtx, int m, int n)
{
    bool *row = new bool[m];
    bool *column = new bool[n];

    memset( row, false, sizeof( bool) * m);
    memset( column, false, sizeof( bool) * n);

    for ( int i = 0; i < m; i++ )
        for ( int j = 0; j < n; j++ )
            if ( !mtx[i][j] )
            {
                row[i] = true;
                column[j] = true;
            }

    for ( int i = 0; i < m; i++ )
        for ( int j = 0; j < n; j++ )
        {
            if ( row[i] || column[j] )
                mtx[i][j] = 0;
        }

    delete[] row;
    delete[] column;
}

int main()
{
    const int m = 5, n = 6;
    int matrix[m][n] = { {1, 2 ,3 ,4 ,5, 6},
                         {0, 2, 1, 0, 7, 0},
                         {5, 0, 1, 0, 1, 1},
                         {2, 1, 3, 5, 2, 1},
                         {6, 3, 7, 0, 2, 3}};

    int **mtx = new int*[m];

    for ( int i = 0; i < m; i++ )
    {
        mtx[i] = new int[n];

        for ( int j = 0; j < n; j++ )
            mtx[i][j] = matrix[i][j];
    }

    printMatrix( mtx, m, n);
    replaceByZero( mtx, m, n);
    cout << "After replacement: \n";
    printMatrix( mtx, m, n);
}
