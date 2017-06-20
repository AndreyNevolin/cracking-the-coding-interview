/* Write a method to generate the nth Fibonacci number */
#include <iostream>

using namespace std;

int BIT( int n, int m)
{
    return (n >> m) & 1;
}

void mul( long long A[][2], long long B[][2], long long res[][2])
{
    for ( int i = 0; i < 2; i++ )
            for ( int j = 0; j < 2; j++ )
            {
                res[i][j] = 0;

                for ( int k = 0; k < 2; k++ )
                    res[i][j] += A[i][k] * B[k][j];
            }
}

/* A = ( 1 1 )  A^n = ( F(n+1) F(n)   )
       ( 1 0 )        ( F(n)   F(n-1) )  */
long long Fibonacci( int n)
{
    if ( n < 0 )
        return -1;

    if ( n == 0 )
        return 0;

    if ( n == 1 )
        return 1;

    long long A[2][2] = {{1,1},{1,0}};
    long long powA[2][2] = {{1,1},{1,0}};
    long long diag[2][2] = {{1,0},{0,1}};
    int ind = 0;

    n--;

    while ( n >> ind )
        ind++;

    for ( int i = ind - 2; i >= 0; i-- )
    {
        long long temp[2][2];

        mul( powA, powA, temp);

        if ( BIT( n, i) )
            mul( temp, A, powA);
        else
            mul( temp, diag, powA);
    }

    return powA[0][0];
}

int main()
{
    for ( int i = 0; i < 20; i++ )
        cout << Fibonacci( i) << " ";

    return 0;
}
