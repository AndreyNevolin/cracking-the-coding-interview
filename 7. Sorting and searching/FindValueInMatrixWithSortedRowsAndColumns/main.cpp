/* Given a matrix in which each row and each column is sorted, write a method to find
an element in it */
#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>

using namespace std;

/* Вопросы интервьюеру:
   1) если искомое число встречается в матрице несколько раз, какую позицию
      выбрать в качестве искомой?
   2) в каком виде вернуть результат? Надо ли, например, использовать отдельный
      объект для представления позиции? */
bool searchMtx( vector< vector<int> > arr, int val, int *row, int *col)
{
    assert( row && col);

    if ( !arr.size() )
        return false;

    int r = 0;
    int c = arr[0].size() - 1;

    while ( r < arr.size() && c >= 0 )
    {
        int elem = arr[r][c];

        if ( elem == val )
        {
            *row = r;
            *col = c;

            return true;
        } else if ( elem > val )
            c--;
        else
            r++;
    }

    return false;
}

int main()
{
    int matrix[][7] = { { 1,  2,  3,  4,  5,  6,  7},
                        { 3,  4,  7, 15, 16, 19, 42},
                        { 8,  9, 10, 21, 25, 30, 44},
                        {11, 15, 18, 27, 29, 33, 47},
                        {13, 17, 23, 31, 35, 39, 53},
                        {22, 28, 34, 38, 41, 52, 68} };
    vector< vector<int> > arr( sizeof( matrix) / sizeof( matrix[0]));

    for ( int i = 0; i < sizeof( matrix) / sizeof( matrix[0]); i++ )
    {
        arr[i] = vector<int>( matrix[i], matrix[i] + sizeof( matrix[i]) / sizeof( int));
    }

    for ( int i = 0; i < arr.size(); i++ )
    {
        for ( int j = 0; j < arr[i].size(); j++ )
            cout << setw( 3) << arr[i][j] << " ";

        cout << "\n";
    }

    cout << "Enter value to find: ";

    int val = 0, col = 0, row = 0;

    cin >> val;

    if ( searchMtx( arr, val, &row, &col) )
        cout << "Found at (" << row << ", " << col << ")";
    else
        cout << "Not found";

    return 0;
}
