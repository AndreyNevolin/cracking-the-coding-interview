/* Given a sorted array of n integers that has been rotated an unknown number of
times, give an O(log n) algorithm that finds an element in the array You may assume
that the array was originally sorted in increasing order
EXAMPLE:
Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)
Output: 8 (the index of 5 in the array) */

#include <iostream>

using namespace std;

int findInBounds( int *arr, int left, int right, int val)
{
    if ( left == right )
        if ( arr[left] != val )
            return -1;
        else
            return left;

    int middle = (left + right) / 2;

    int in_left, in_right;
    int out_left, out_right;

    if ( arr[left] < arr[middle] )
    {
        in_left = left; in_right = middle;
        out_left = middle + 1; out_right = right;
    } else
    {
        in_left = middle + 1; in_right = right;
        out_left = left; out_right = middle;
    }

    if ( val >= arr[in_left] && val <= arr[in_right] )
        return findInBounds( arr, in_left, in_right, val);
    else
        return findInBounds( arr, out_left, out_right, val);
}

int findIndex( int *arr, int sz, int val)
{
    if ( !arr )
        return -1;

    return findInBounds( arr, 0, sz - 1, val);
}

int main()
{
    int arr[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};

    cout << "Index: " << findIndex( arr, 12, 5);
}
