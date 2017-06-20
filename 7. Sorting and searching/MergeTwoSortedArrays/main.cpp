/* You are given two sorted arrays, A and B, and A has a large enough buffer at the end
to hold B Write a method to merge B into A in sorted order */
#include <iostream>

using namespace std;

void mergeArrays( int *A, int *B, int n, int m)
{
    if ( !m )
        return;

    int posA = n - 1, posB = m - 1;
    int current = n + m - 1;

    while ( posB >= 0 && posB >= 0 )
    {
        if ( A[posA] > B[posB] )
        {
            A[current--] = A[posA--];
        } else
        {
            A[current--] = B[posB--];
        }
    }

    while ( posB >= 0 )
        A[current--] = B[posB--];
}

int main()
{
    const int n = 6;
    const int m = 9;
    int A[n] = {0,3,7,12,13,50};
    int B[m] = {1,3,4,5,9,10,21,33,100};
    int *C = new int[n + m];

    cout << "Array A: ";

    for ( int i = 0; i < n; i++ )
    {
        C[i] = A[i];
        cout << A[i] << " ";
    }

    cout << "\n Array B: ";

    for ( int i = 0; i < m; i++ )
        cout << B[i] << " ";

    cout << "\n";
    mergeArrays( C, B, n, m);
    cout << "Array A after merge: ";

    for ( int i = 0; i < n + m; i++ )
        cout << C[i] << " ";

    return 0;
}
