/* Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees Can you do this in place? */

/* ¬опрос: в какую сторону вращать?
   ѕо-хорошему, направление вращени€ можно задать параметром */
#include <iostream>
#include <iomanip>

using namespace std;

void printImage( int **image, int sz)
{
    for ( int i = 0; i < sz; i++ )
    {
        for ( int j = 0; j < sz; j++ )
            cout << setw( 2) << image[i][j];

        cout << "\n";
    }
}

void rotateImage( int **image, int n)
{
    for ( int i = 0; i < n / 2; i++ )
        for ( int j = i; j < n - i - 1; j++ )
        {
            int temp = image[i][j];

            image[i][j] = image[n - j - 1][i];
            image[n - j - 1][i] = image[n - i - 1][n - j - 1];
            image[n - i - 1][n - j - 1] = image[j][n - i - 1];
            image[j][n - i - 1] = temp;
        }
}

int main()
{
    const int n = 9;
    int image[n][n] = { {0,0,0,0,1,0,0,0,0},
                        {0,0,0,1,0,1,0,0,0},
                        {0,0,1,0,0,0,1,0,0},
                        {0,1,0,0,0,0,0,1,0},
                        {1,0,0,0,0,0,0,0,1},
                        {1,1,1,1,1,1,1,1,1},
                        {1,0,0,0,0,0,0,0,1},
                        {0,0,0,1,1,1,0,0,0},
                        {0,0,0,0,1,0,0,0,0}};

    int **img = new int*[n];

    for ( int i = 0; i < n; i++ )
    {
        img[i] = new int[n];

        for ( int j = 0; j < n; j++ )
            img[i][j] = image[i][j];
    }

    cout << "Before rotation: \n";
    printImage( img, n);
    rotateImage( img, n);
    cout << "After rotation: \n";
    printImage( img, n);

    return 0;
}
